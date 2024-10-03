#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3
#define FALSE 0
#define TRUE 1

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}

void printBoard(char board[9]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c\t", board[(i * 3) + j]);
        }
        printf("\n");
    }
}

int* generateMoves(char board[9], int size) {
    int* moves_remaining = (int*)malloc(size * sizeof(int));
    
    if (moves_remaining == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    int i, j = 0;

    for (i = 0; i < 9; i++) {
        if (board[i] == '-') {
            moves_remaining[j] = i;
            j++;
        }
    }

    return moves_remaining; 
}

int checkWin(char board[9], char turn, int minimaxCheck) {
    int combos[8][3] = {
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    int i, j;
    int game_ended = 0;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            if (board[combos[i][j]] == turn) game_ended = 1;
            else {
                game_ended = 0;
                break;
            };
        }

        if (game_ended) {
            if (!minimaxCheck) printf("Win of '%c'\n", turn);
            return 1;
        }
    }

    return 0;
}

int checkTie(char board[9], int minimaxCheck) {
    int i;

    for (i = 0; i < 9; i++) {
        if (board[i] == '-') return 0;
    }

    if(!minimaxCheck) printf("Game ended! Tie!\n");
    return 1;
}

int checkGameEnded(char board[9], char turn, int minimaxCheck) {
    if (checkWin(board, turn, minimaxCheck)) return 1;
    if (checkTie(board, minimaxCheck)) return 1;
    return 0;
}

int minimax(char board[9], int alpha, int beta, char player, char bot, char turn, int move_number, int *movecount) {
    int size = 9 - move_number;
    int* moves_left = generateMoves(board, size);
    int best_move_index = -1, evaluation, move_evaluation, i, j;

    if(checkWin(board, bot, TRUE)) return 10;
    if(checkWin(board, player, TRUE)) return -10;
    if(checkTie(board, TRUE)) return 0;

    (*movecount)++;

    if (turn == bot) {
        evaluation = -9999;
        for (i = 0; i < size; i++) {
            board[moves_left[i]] = bot;
            move_number++;

            move_evaluation = minimax(board, alpha, beta, player, bot, player, move_number, movecount);
            evaluation = (evaluation > move_evaluation) ? evaluation : move_evaluation;

            board[moves_left[i]] = '-';
            move_number--;

            alpha = (evaluation > alpha) ? evaluation : alpha;
            if(beta <= alpha) {
                free(moves_left);
                return evaluation;
            }
        }
        free(moves_left);
        return evaluation;
    } else {
        evaluation = 9999;
        for (i = 0; i < size; i++) {
            board[moves_left[i]] = player;
            move_number++;

            move_evaluation = minimax(board, alpha, beta, player, bot, bot, move_number, movecount);
            evaluation = (evaluation < move_evaluation) ? evaluation : move_evaluation;

            board[moves_left[i]] = '-';
            move_number--;

            beta = (evaluation < beta) ? evaluation : beta;
            if(beta <= alpha) {
                free(moves_left);
                return evaluation;
            }
        }
        free(moves_left);
        return evaluation;
    }
}

int minimaxRoot(char board[9], char player, char bot, char turn, int move_number, int *bot_checked_moves) {
    int size = 9 - move_number;
    int* moves_left = generateMoves(board, size);
    int best_move_index = -1, max_evaluation = -9999, evaluation = -9999, i, j;

    for (i = 0; i < size; i++) {
        board[moves_left[i]] = bot;
        move_number++;

        (*bot_checked_moves)++;

        evaluation = minimax(board, -9999, 9999, player, bot, player, move_number, bot_checked_moves);

        if(evaluation > max_evaluation) {
            max_evaluation = evaluation;
            best_move_index = moves_left[i];
        }

        board[moves_left[i]] = '-';
        move_number--;
    }

    free(moves_left);
    return best_move_index;
}

void bot_move(char board[9], char player, char bot, char turn, int move_number, int *bot_checked_moves) {
    board[minimaxRoot(board, player, bot, turn, move_number, bot_checked_moves)] = bot;
}

void start(char player_1, char player_2, int against_computer) {
    char board[9];
    char turn = player_1;
    int game_ended = 0, hit, move_number = 0, bot_checked_moves = 0;

    for (int i = 0; i < 9; i++) {
        board[i] = '-';
    }

    while (!game_ended) {
        if (move_number == 0) printBoard(board);

        printf("Define where you want to put your mark! 1-9\n");
        scanf(" %d", &hit);

        if (hit >= 1 && hit <= 9 && board[hit - 1] == '-') {
            board[hit - 1] = turn;

            move_number++;

            clearConsole();

            printf("Player's turn '%c'\nMove number: %d\nBoard:\n", turn, move_number);

            printBoard(board);

            game_ended = checkGameEnded(board, turn, FALSE);

            if (against_computer && !game_ended) {
                bot_move(board, player_1, player_2, player_2, move_number, &bot_checked_moves);
                
                move_number++;

                clearConsole();

                printf("Player's turn '%c'\nMove number: %d\nBot Checked moves: %d\nBoard:\n", player_1, move_number, bot_checked_moves);
                printBoard(board);

                game_ended = checkGameEnded(board, player_2, FALSE);
            }

            if (turn == player_1 && !against_computer && !game_ended) {
                turn = player_2;
            } else {
                turn = player_1;
            }
        } else {
            clearConsole();
            
            printf("Invalid move! Try again.\n");
            printf("Board:\n");

            printBoard(board);
        }
    }
}

int main() {
    char player_1, player_2;
    int against_computer;

    clearConsole();

    printf("Write '1' if you want to play against a bot, write '0' if you want to play against your friend!\n");

    scanf(" %d", &against_computer);

    if (against_computer) printf("Write your type of char 'X' or 'O'\n");
    else printf("Player 1 write your type of char 'X' or 'O'\n");

    scanf(" %c", &player_1);

    if (player_1 == 'X') {
        player_2 = 'O';
    } else {
        player_1 = 'O';
        player_2 = 'X';
    }

    if (against_computer) {
        printf("Player: %c Bot: %c\n", player_1, player_2);
    } else {
        printf("Player: %c Opponent: %c\n", player_1, player_2);
    }

    start(player_1, player_2, against_computer);

    return 0;
}