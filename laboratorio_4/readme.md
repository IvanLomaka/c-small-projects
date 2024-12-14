# Labirinti di Parole

## Overview

"Labirinti di Parole" is a word maze game where the goal is to navigate from a starting word to an ending word by applying specific transformation rules. The rules for transforming words are:

- Anagramming the word (e.g., **ANSA** → **SANA**)
- Changing one character (e.g., **CARTA** → **CORTA**)
- Adding a character (e.g., **CASA** → **CASTA**)
- Removing a character (e.g., **PORTA** → **POTA**)

The game is played by loading a sequence of words from a text file, where the first word is the start and the last word is the destination. The objective is to find a valid sequence of transformations from the start word to the end word.

## Program Features

1. **Load Word Sequence**: The program will prompt the user for a file name and load a sequence of words. The first word represents the starting word and the last word is the destination. At least 4 words must be provided to start the game.
   
2. **Menu Options**:
    - **Display Word Sequence**: Show the start and end words and the available words for transformations.
    - **Verify Solution**: Allow the user to input a solution file and check whether it is correct.
    - **Acquire New Word Sequence**: Restart the game with a new set of words.
    - **Exit**: Exit the program.

3. **Solution Verification**: After loading a sequence of words, the program will check if the user's proposed solution follows the transformation rules correctly and uses each word exactly once.

4. **Error Handling**: The program checks for errors when loading the file:
    - It ensures there are at least 4 words in the sequence.
    - It handles errors when opening the file or invalid characters in the words.

## Specifications

- **Word Length**: Each word in the sequence is no longer than 30 characters and may include both uppercase and lowercase letters.
- **File Format**: The input and solution files should contain words separated by spaces. Special characters (other than alphabets) are not allowed in words.

### Example Flow

1. Load a file containing a sequence of words:

    ```
    NUMERI PRESO sapore SUPER SARTE OPTARE RUSPE PRESTO OSARE SORTE TERSA RASPE POTARE PORTE PERSA POLARE SUPERI SPORTE stare POSARE SPORE Sumeri OSTARE PAROLE
    ```

2. The program will display the starting and ending words, as well as the intermediate words for transformation.

3. The user can verify their proposed solution by entering another file. If the solution follows the transformation rules correctly, the program will display “Soluzione esatta”.

## Optional Feature

- **Auto-Solution Finder**: Implement a subprogram that finds and displays a solution for the given set of words. This feature can be added to the program's menu for automatic solving.

## Implementation Checklist

- [ ] Define necessary data structures (the word sequence, transformations, etc.).
- [ ] Implement the main program flow based on the user menu and choices.
- [ ] Define the required subprograms (loading files, verifying solutions, etc.) with proper input/output parameters.
- [ ] Split the work into manageable tasks for modular development.

## Compilation and Execution

To compile the program in ANSI C89, use the following command:

```bash
gcc -o labirinto parole_labirinto.c