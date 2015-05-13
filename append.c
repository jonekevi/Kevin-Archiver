void append(char *inname, char *karname){
  struct kar_hdr *hdr;
  int karfd;
  int fd;
  if(access(karname, F_OK)<0){
    karfd = open(karname,O_WRONLY | O_CREAT, S_IRWXU);
    lseek(karfd, -1, SEEK_CUR); 
    write(karfd,KARMAG, sizeof(KARMAG)-1); 
  }else
    karfd = open(karname,O_WRONLY, S_IRWXU); 
  hdr = inithdr(inname);
  wrhdr(karfd, hdr);
  cp(inname, karname);
  close(karfd);
}
/*int main(int argc, char **argv){
  char *kar = argv[1];
  char *f = argv[2];
  int fd;
  //int karfd;
  
  //karfd = open(kar, O_WRONLY | O_CREAT, S_IRWXU); 
  fd = open(f,O_RDONLY); 
  append(fd, f, kar);  
  
  close(fd);
  // close(karfd);
  return 1;
  } */ 
