#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
  // if no file arguments are given, print error message and exit
    if(argc==1)
  {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }
  // loop through each file
  for (int i; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    int first_c = EOF; // first char to end of file
    int count = 0; //initialize count
    int c; //current char
    // read characters from file until end of file
    while ((c = getc(fp)) != EOF) {
      // if the current character is the same as the first character, increment count
      if (c == first_c) {
        count++;
      }
      // if not, print the count and character to stdout
      else {
        if (count > 0) {
          fwrite(&count, sizeof(int), 1, stdout);
          fwrite(&first_c, sizeof(char), 1, stdout);
        }
        // update first character and count
        first_c = c;
        count = 1;
      }
    }
    // write count and first character of the last sequence to stdout
    if (count > 0) {
      fwrite(&count, sizeof(int), 1, stdout);
      fwrite(&first_c, sizeof(char), 1, stdout);
    }
    fclose(fp);
  }
  return(0);
}