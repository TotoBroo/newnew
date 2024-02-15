#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE (1024)

// count as as integer with character
void compression(int count, char c) {
  fwrite(&count, sizeof(int), 1, stdout);
  putchar(c);
}

int main(int argc, char *argv[]) {
  //checks to make sure there is one file.
  if (argc < 2) {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }
  //looks through files
  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r"); // open file
    int first_c = fgetc(fp);
    if (first_c == EOF) {
      fclose(fp);
    }
    else {
      int count = 1;
      int current_c;
      while ((current_c = fgetc(fp)) != EOF) {
        if (current_c == first_c) {
          count++;
        }
        else {
          fwrite(&count, sizeof(int), 1, stdout);
          putchar(first_c);
          count = 1;
          first_c = current_c;
        }
      }
      fclose(fp);
    }
  }
  exit(0
}
