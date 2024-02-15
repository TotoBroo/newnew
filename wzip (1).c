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
    if (fp == NULL) {
      printf("wzip: cannot open file\n");
      exit(1);
    }
    //defining variables
    int count = 0;
    char buffer[BUFFER_SIZE];
    int first_c;
    size_t bytes_read;
    //continues until fread() returns 0
    while((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
      for (size_t j = 0; j < bytes_read; j++) {
        //if count is zero, initialize first_c and increment count
        if (count == 0) {
          first_c = buffer[j];
          count++;
        }
        //if current character is same as first_c, increment count
        else if  (first_c == buffer[j]) {
          count++;
        }
        // if current character is not same as first_c, compress and reset count and first_c
        else {
          compression(count, first_c);
          count = 1;
          first_c = buffer[j];
        }
      }
    }
    //write any remaining count and character
    if (count > 0) {
      compression(count, first_c);
    }
  fclose(fp);
  }
  exit(0);
}
