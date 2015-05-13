#include "kar.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

struct kar_hdr* inithdr(char *f){  
  struct stat filestat;
  struct kar_hdr *hdr;
  int i;
  hdr =(struct kar_hdr*) malloc(sizeof(struct kar_hdr));
  memset(hdr, 0, sizeof(struct kar_hdr));
  //for(i=0;i<6;i++){
  //  hdr->kar_uid[i]= '\0'; 
  //}
  if(stat(f, &filestat)<0){
    perror("file stat failed");
    exit(1);
  }
  char temp[32];
  strncpy(hdr->kar_name,f, sizeof(f));
  
  sprintf(temp, "%lld", (long long)filestat.st_ctime); 
  strncpy(hdr->kar_date, temp, sizeof(hdr->kar_date));   
  sprintf(temp,"%lld",(long long)filestat.st_uid);
  strncpy(hdr->kar_uid, temp, sizeof(hdr->kar_uid));
  sprintf(temp,"%lld",(long long)filestat.st_gid);
  strncpy(hdr->kar_gid, temp, sizeof(hdr->kar_gid));
  sprintf(temp,"%o",(int)filestat.st_mode);
  strncpy(hdr->kar_mode, temp, sizeof(hdr->kar_mode));
  sprintf(temp,"%lld",(long long)filestat.st_size); 
  strncpy(hdr->kar_size, temp, sizeof(hdr->kar_size));
  sprintf(temp,"%s", KARFMAG);
  strncpy(hdr->kar_fmag, temp, sizeof(hdr->kar_fmag));
  return hdr;
}  
//int main(int argc, char **argv){
//return 1;
  
//} 
