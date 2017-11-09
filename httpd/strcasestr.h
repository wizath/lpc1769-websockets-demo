#ifndef STRCASESTR_H
#define STRCASESTR_H

//#include <sys/types.h>
#include "stddef.h"

char *strcasestr(const char *s, const char *find);
char *strncasestr(const char *s, const char * find, size_t slen);
size_t strlcpy(dst, src, siz);

#endif /* STRCASESTR_H */

