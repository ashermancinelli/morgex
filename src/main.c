#include <string.h>
#include <assert.h>

#include <curl/curl.h>

#include <config.h>
#include <utils.h>

int main(int argc, char** argv)
{
  const char* const url = API_ENDPOINT_URL;
  int ret = 0;
  CURL* curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();

  if(curl)
  {
    puts("-- Initialized cURL.");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_3);
    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
    {
      puts("-- cURL returned an error code!");
      printf("\t-- Got error code %d.\n", res);
      printf("\t-- Got error message %s\n", curl_easy_strerror(res));
      ret = 1;
    }
  }
  else
  {
    fprintf(stderr, "Could not initialize cURL.");
    ret = 1;
  }

  curl_easy_cleanup(curl);
  return ret;
}
