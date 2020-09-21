#include <utils.h>

#include <string.h>
#include <stdlib.h>

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
  puts("-- Callback triggered.");
  struct entry_t* e = (struct entry_t*) userdata;
  size_t sz = nmemb * size;

  /* Expand entry memory for new incoming data */
  e->buf = realloc(e->buf, e->sz + sz + 1);

  memcpy(&(e->buf[e->sz]), ptr, sz);
  e->sz += sz;
  e->buf[e->sz] = '\0';

  puts("-- New buf:\n");
  char* p = e->buf;
  while(p != e->buf+e->sz)
  {
    putc(*p++, stdout);
  }
  puts("");

  return sz;
}
