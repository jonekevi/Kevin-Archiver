void wrhdr(int fd, struct kar_hdr* hdr){
  FILE* f = fdopen(fd, "a");
  int i;
  fseek(f,0,SEEK_CUR);
  for(i=0;i<16;i++) {
    if(hdr->kar_name[i]=='\0')
      break;
    else fprintf(f, "%c", hdr->kar_name[i]);
  }
  fprintf(f,"/");
  for(i=i+1 ; i<16; i++) 
    fprintf(f, " ");
  for(i=0;i<12;i++) {
    if(hdr->kar_date[i]=='\0')
      fprintf(f,"%s"," "); 
    else
      fprintf(f, "%c", hdr->kar_date[i]);
  }
  for(i=0;i<6;i++) {
    if(hdr->kar_uid[i]=='\0')
      fprintf(f," ");
    else 
      fprintf(f, "%c", hdr->kar_uid[i]);
  }
  for(i=0;i<6;i++) {
    if(hdr->kar_gid[i]=='\0')
      fprintf(f," ");
    else
      fprintf(f, "%c", hdr->kar_gid[i]);
  }

  for(i=0;i<8;i++) {
    if(hdr->kar_mode[i]=='\0')
      fprintf(f," ");
    else
      fprintf(f, "%c", hdr->kar_mode[i]);
  }
  for(i=0;i<10;i++) {
    if(hdr->kar_size[i]=='\0')
      fprintf(f," ");
    else
      fprintf(f, "%c", hdr->kar_size[i]);
  }
  fprintf(f,"%s",KARFMAG);
  

  
  fclose(f);
}
/*int main(int argc, char **argv) {
  struct kar_hdr* hdr;
  char *f = argv[1];
  char *target = argv[2];
  int fdout;
  
  fdout = open(target, O_WRONLY | O_CREAT, S_IRWXU);  
  hdr = inithdr(f);
  wrhdr(fdout, hdr);

  }*/

