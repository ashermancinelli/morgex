#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include <curl/curl.h>

#include <config.h>
#include <utils.h>

int main(int argc, char** argv)
{
  char* url = API_ENDPOINT_URL;
  char* url_args = API_ARGS;
  int ret = 0;
  CURL* curl;
  CURLcode res;

  /* Data entry in which all response data will be placed. */
  struct response_t* r = malloc(sizeof(struct response_t));

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();

  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)r);

    printf("-- Initialized cURL using URL %s.\n", url);
    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
    {
      puts("-- cURL returned an error code!");
      printf("--- Got error code %d.\n", res);
      printf("--- Got error message `%s`\n", curl_easy_strerror(res));
      ret = 1;
    }
    puts("-- cURL performed successfully.");
  }
  else
  {
    fprintf(stderr, "Could not initialize cURL.");
    ret = 1;
  }

  curl_easy_cleanup(curl);
  return ret;
}
