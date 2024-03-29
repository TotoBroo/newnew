#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE (1024)

int main(int argc, char *argv[]) {
  //checks for certain files
  if (argc != 1) {
    // loop through certain files from command
    for (int i = 1; i < argc; i++){
      FILE *fp = fopen(argv[i], "r");
      if (fp == NULL) {
        printf("wcat: cannot open file\n");
        exit(1);
      }
      // read and print file
      char buffer[1024];
      while (fgets(buffer, 1024, fp) != NULL) {
        printf("%s", buffer);
      }
      fclose(fp); // closes file after reading
    }
  }
  exit(0);
}