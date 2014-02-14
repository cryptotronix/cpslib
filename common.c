#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "common.h"

float
percentage(unsigned long int n, unsigned long int d)
{
  /* TBD: Error check here */
  float percent = ((float)n / (float)d)*100.0;
  return percent;
}


int
str_comp(const void *key, const void *memb) 
{
  const char **a = (const char **)key;
  const char **b = (const char **)memb;
  return strcmp(*a, *b);
}

int
int_comp(const void *key, const void *memb) 
{
  const int a = *(int *)key;
  const int b = *(int *)memb;
  if (a == b) 
    return 0;
  else
    return -1;
}

  
char *
grep_awk(FILE *fp, char *fstr, int nfield, char *delim)
{
  char *line = (char *)calloc(500, sizeof(char));
  check_mem(line);
  char *ret = NULL;
  int i;
  while (fgets(line, 400, fp) != NULL) {
    if (strncasecmp(line, fstr, strlen(fstr)) == 0){
      ret = strtok(line, delim);
      for (i = 0; i < nfield; i++) {
        ret = strtok(NULL, delim);
      }
      if (ret) {
        ret = strdup(ret);
        check_mem(ret);
        free(line);
        return ret;
      }
    }
  }
  free(line);
  return NULL;
 error:
  return NULL;
}  
  
