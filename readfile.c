#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int x, char *y[]) {
    if (x != 3) {
        printf("Usage: %s <file1> <file2>\n", y[0]);
        return 1;
    }
    if (strcmp(y[1], y[2]) == 0) {
        printf("Error: Both filenames are the same.\n");
        return 1;
    }
    FILE *file1 = fopen(y[1], "a");
    if (file1 == NULL) {
        printf("Error: Could not open %s for appending.\n", y[1]);
        return 1;
    }
    FILE *file2 = fopen(y[2], "r");
    if (file2 == NULL) {
        printf("Error: Could not open %s for reading.\n", y[2]);
        fclose(file1);
        return 1;
    }
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), file2)) > 0) {
        fwrite(buffer, 1, bytes, file1);
    }
    fclose(file1);
    fclose(file2);
    printf("File %s has been successfully appended to %s.\n", y[2], y[1]);
    return 0;
}
