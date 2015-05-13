#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "kar.h"
#include "inithdr.c"
#include "wrhdr.c"
#include "copy.c"
//#include "initkar.c"
#include "append.c"
#include "extract.c"
#include "tables.c"
 
int main(int argc, char **argv){
  if(argc < 2){
    perror("not enough arguments");
  }
  int i;
  char *mode = argv[1];
  if(strcmp(mode,  "a")==0){
    for(i=3;i<argc;i++){
      append(argv[i],argv[2]);
      }
  } else if(strcmp(mode, "x")==0) {
    extract(argv[2],argv[3]);
  } else if(strcmp(mode, "t")==0) {
    tables(argv[2]);
  } else if(strcmp(mode, "v")==0) {
    tv(argv[2]);
  } else printf("Enter a for append, x for extract, t for table"); 
      
  return 1;
}

