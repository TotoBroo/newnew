#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 8192

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int j = 1; j < argc; j++) {
        FILE *fp = fopen(argv[j], "r");
        if (fp == NULL) {
            perror("Error opening file");
            exit(1);
        }

        char str[BUFFER_SIZE];
        char prev = '\0';
        int counter = 0;

        while (fgets(str, BUFFER_SIZE, fp) != NULL) {
            int l = strlen(str);
            for (int i = 0; i < l; i++) {
                char current = str[i];
                if (current == prev) {
                    counter++;
                } else {
                    if (counter > 0) {
                        fwrite(&counter, sizeof(int), 1, stdout);
                        fwrite(&prev, sizeof(char), 1, stdout);
                    }
                    prev = current;
                    counter = 1;
                }
            }
        }

        fclose(fp);
    }

    // Write remaining characters
    if (counter > 0) {
        fwrite(&counter, sizeof(int), 1, stdout);
        fwrite(&prev, sizeof(char), 1, stdout);
    }

    return 0;
}
