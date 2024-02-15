#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE (1024)

int main(int argc, char *argv[]) {
  //checks for certain files
  if (argc <= 1) {
    exit(0); //no files specfic to command
  }
  // loop through certain files from command
  for (int i = 1; i < argc; i++){
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wcat: cannot open file \n");
      exit(1);
    }
    // read and print file
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
      printf("%s", buffer);
    }
    fclose(fp); // closes file after reading
  }
  exit(0);
}