#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  //checks to make sure there is one file.
  if (argc < 2) {
    printf("wunzip: file1 [file2 ...]\n");
    exit(1);
  }
  //looks through files
  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r"); // open file
    if (fp == NULL) {
      printf("wunzip: cannot open file\n");
      exit(1);
    }
    //defining variables
    int count;
    char c;
    // Read pairs of count and character from the file until EOF
    while (fread(&count, sizeof(int), 1, fp) == 1) {
      //if the the file fails to read, print error and exit
      if (fread(&c, sizeof(char), 1, fp) != 1) {
        printf("wunzip: file corrupted\n");
        exit(1);
      }
      for (int j = 0; j < count; j++) {
        putchar(c);
      }
    }
    fclose(fp);
  }
  return 0;
}
