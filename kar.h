/* formatted after ar.h */

#ifndef _KAR_H_
#define _KAR_H_ 1

#include <sys/cdefs.h>

#define KARMAG "!<arch>\n"
#define SKARMAG 8

#define KARFMAG "`\n"

__BEGIN_DECLS

struct kar_hdr {
  char kar_name[16];
  char kar_date[12];
  char kar_uid[6];
  char kar_gid[6];
  char kar_mode[8];
  char kar_size[10];
  char kar_fmag[2];
};

__END_DECLS

#endif /* kar.h */
