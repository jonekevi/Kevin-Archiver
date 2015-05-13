void extract(char *kar, char *nm){
  FILE *ar; 
  //fseek(ar,-1,SEEK_SET); 
  char mag[10];
  char name[32];
  char date[32];
  char gid[32];
  char uid[32];
  char mode[32];
  char size[32];
  char fmag[32];
  char buff[4096];
  int i;
  int num_read;
  int num_written;
  int fd_in;
  int fd_out;
  char *f=nm; 
  //f = strcat(f,"/");
  fd_out = open(nm, O_WRONLY | O_CREAT , S_IRWXU );
  //  fd_in = open(kar,O_RDONLY);
  f= strcat(f,"/");
  if (fd_out ==-1){
    perror("output file");
  }
  //  if (fd_in ==-1) {
  // perror("input file");
  // }
  ar=fopen(kar,"r");
  fgets(mag,sizeof(mag),ar);
  fscanf(ar,"%s",name);  

  while(strcmp(name,nm)){ 
    if( fscanf(ar,"%s", name)==EOF){
      perror("EOF");
      exit(-1);
    }
  }
  fscanf(ar,"%s",date);
  fscanf(ar,"%s",uid);
  fscanf(ar,"%s",gid);
  fscanf(ar,"%s",mode);
  fscanf(ar,"%s",size);
  fscanf(ar,"%s",fmag);
  fseek(ar, 1,SEEK_CUR);
  lseek(fd_out, 0, SEEK_CUR);
  cpbuff(ar, fd_out, atoi(size));
  fclose(ar);
  // fd_out = open(name, O_CREAT,  S_IRWXU);
  // if (fd_out ==-1){
  // perror("output file");
  //} 
  
  
  //  lseek(fd_out, -1, SEEK_SET);
   
  close(fd_out);
}
