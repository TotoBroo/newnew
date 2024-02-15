#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE (1024)

// function to search for a term in a file
// uses getline() instead of fgets()
void search_file(char *searchterm, FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  // reads each line of the file and prints line if term is found
  while ((getline(&line, &len, fp)) != -1) {
    if (strstr(line, searchterm) != NULL) {
      printf("%s", line);
    }
  }
  //frees up allocated memory because of getline()
  free(line);
}

int main(int argc, char *argv[]) {
  // if no argument provided
  if (argc == 1) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }
  // if only one argument provided
  else if (argc == 2) {
    char *searchterm = argv[1]; //search term
    search_file(searchterm, stdin);
  }
  //if two arguments provided
  else if (argc == 3) {
    char *searchterm = argv[1]; //search term
    FILE *fp = fopen(argv[2], "r"); //open file
    //if unable to open file/gives NULL value
    if (fp == NULL) {
      printf("Wgrep: cannot open file \n");
      exit(1);
      }
    search_file(searchterm, fp);
    fclose(fp); //closes file
  }
  // if more than two arguments provided
  else {
    printf("Wgrep: too many arguments \n");
    exit(1);
  }
  exit(0);
}
