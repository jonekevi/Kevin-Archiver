#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define BLOCKSIZE 4096

void cp(char * in, char *out)
{
  char *input = in;
  char *output = out;
  int in_fd;
  int out_fd;
  char buf[BLOCKSIZE];

  int num_read;
  int num_written = 0;

  int location;

  in_fd = open(input, O_RDONLY);
  if(in_fd == -1){
    perror("Can't open input file");
    exit(-1);
  }

  out_fd = open(output, O_WRONLY, S_IRWXU);
  if(out_fd == -1){
    perror("Can't open input file");
    exit(-1);
  }
  
  lseek(out_fd, 0, SEEK_END);
  while((num_read = read(in_fd, buf, BLOCKSIZE)) > 0){
    if (write(out_fd, buf, num_read) != num_read)
      perror("Couldn't write whole buffer");    
  
  }
  write(out_fd,"\n",1);
  close(in_fd);
  close(out_fd);
}

void cpbuff(FILE *in_f, int  out_fd, int size)
{
  char buf[BLOCKSIZE];
  int ReadBytes = BLOCKSIZE;
  
  
  while(size > 0){
    if( size < BLOCKSIZE )
      ReadBytes = size;
    else 
      ReadBytes = BLOCKSIZE;

    if (fread(buf,1, ReadBytes, in_f) != ReadBytes) 
      perror("couldn't read whole buffer");
    if (write(out_fd, buf, ReadBytes) != ReadBytes)
      perror("Couldn't write whole buffer");

    size -= ReadBytes; 
  }
 
}
