#include <utils.h>

#include <cjson/cJSON.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <search.h>

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
  puts("-- Callback triggered.");
  struct response_t * r = (struct response_t *) userdata;
  size_t sz = nmemb * size;

  /* Expand entry memory for new incoming data */
  r->buf = realloc(r->buf, r->sz + sz + 1);

  memcpy(&(r->buf[r->sz]), ptr, sz);
  r->sz += sz;
  r->buf[r->sz] = '\0';

  puts("-- New buf:\n");
  char* p = r->buf;
  while(p != r->buf+r->sz)
  {
    putc(*p++, stdout);
  }
  puts("");

  return sz;
}
