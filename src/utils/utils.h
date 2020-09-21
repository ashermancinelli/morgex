#pragma once

#include <stddef.h>

struct response_t
{
  char* buf;
  size_t sz;
};

/**
 * @brief Callback for curl getter.
 */
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);

