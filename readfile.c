#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if two filenames are provided
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    // Check if both filenames are the same
    if (strcmp(argv[1], argv[2]) == 0) {
        printf("Error: Both filenames are the same.\n");
        return 1;
    }

    // Open the first file in append mode
    FILE *file1 = fopen(argv[1], "a");
    if (file1 == NULL) {
        printf("Error: Could not open %s for appending.\n", argv[1]);
        return 1;
    }

    // Open the second file in read mode
    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        printf("Error: Could not open %s for reading.\n", argv[2]);
        fclose(file1);
        return 1;
    }

    // Read content from the second file and append it to the first file
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), file2)) > 0) {
        fwrite(buffer, 1, bytes, file1);
    }

    // Close both files
    fclose(file1);
    fclose(file2);

    printf("File %s has been successfully appended to %s.\n", argv[2], argv[1]);
    return 0;
}
