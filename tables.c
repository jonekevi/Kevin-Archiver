#include <time.h>

void tables(char *kar) {
  char mag[10];
  char name[32];
  char date[32];
  char gid[32];
  char uid[32];
  char mode[32];
  char size[32];
  char fmag[32];
  int i;
  int eof;
  
  FILE *ar = fopen(kar, "r");
  eof = 0;
  fgets(mag,sizeof(mag),ar);
  while(eof!=EOF) {
    if(fscanf(ar,"%s",name)==EOF)
      break;
    for(i=0; i<32; i++) {
      if(name[i]=='/')
	name[i]='\0';
    }
        printf("%s\n",name);
    fscanf(ar,"%s",date);
    fscanf(ar,"%s",uid);
    fscanf(ar,"%s",gid);
    fscanf(ar,"%s",mode);
    fscanf(ar,"%s",size);
    fscanf(ar,"%s",fmag);
    fseek(ar,atoi(size),SEEK_CUR); 
  }
  fclose(ar);
}

void tv(char *kar){
  char mag[10];
  char name[32];
  char date[32];
  char gid[32];
  char uid[32];
  char mode[32];
  char size[32];
  char fmag[32];
  char temp[9];
  int i;
  int eof;
  char j;
  FILE *ar = fopen(kar, "r");  
  time_t time; 
  eof = 0;

  fgets(mag,sizeof(mag),ar);
  while(eof!=EOF) {
    if(fscanf(ar,"%s",name)==EOF)
      break;
    for(i=0; i<32; i++) {
      if(name[i]=='/')
        name[i]='\0';
  }
  fscanf(ar,"%s",date);
  fscanf(ar,"%s",uid);
  fscanf(ar,"%s",gid);
  fscanf(ar,"%s",mode);
  fscanf(ar,"%s",size);
  fscanf(ar,"%s",fmag);
  fseek(ar,atoi(size),SEEK_CUR);
  for(i=3;i<7;i++) {
    j = mode[i];
    if(j=='7')
      printf("rwx");
    else if (j=='6')
      printf("rw-");
    else if (j=='5')
      printf("r-x");
    else if (j=='4')
      printf("r--");
    else if (j=='3')
      printf("-wx");
    else if (j=='2')
      printf("-w-");
    else if (j=='1')
      printf("--x");
    else if (j=='0')
      printf("---");
      } 
  printf(" %s/%s",uid,gid);
  printf(" %s",size);
  time =(time_t)atoi(date);
  printf(" %s",ctime(&time)-1);
  printf(" %s\n",name); 

  }
  
}
