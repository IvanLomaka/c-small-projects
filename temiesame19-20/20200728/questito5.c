#include <stdio.h>

// Function to compare two binary files
int diff(char nomeFile[], char nomeFile2[]) {
    FILE *file1 = fopen(nomeFile, "rb");
    FILE *file2 = fopen(nomeFile2, "rb");

    if (file1 == NULL || file2 == NULL) {
        if (file1) fclose(file1);
        if (file2) fclose(file2);
        return -1;  // Error opening files
    }

    int byte1, byte2;

    // Compare files byte by byte
    while ((byte1 = fgetc(file1)) != EOF && (byte2 = fgetc(file2)) != EOF) {
        if (byte1 != byte2) {
            fclose(file1);
            fclose(file2);
            return 1;  // Files are different
        }
    }

    // If one file has extra content, they are different
    if (fgetc(file1) != EOF || fgetc(file2) != EOF) {
        fclose(file1);
        fclose(file2);
        return 1;  // Different sizes
    }

    fclose(file1);
    fclose(file2);
    return 0;  // Files are identical
}

int main() {
    char file1[] = "file1.bin";
    char file2[] = "file2.bin";

    int result = diff(file1, file2);

    if (result == 0)
        printf("Files are identical.\n");
    else if (result == 1)
        printf("Files are different.\n");
    else
        printf("Error: Could not open one or both files.\n");

    return 0;
}