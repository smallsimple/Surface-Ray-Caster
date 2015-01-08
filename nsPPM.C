#include <stdlib.h>
#include "nsPPM.h"

FILE *openPPMFile(const char *filename, const int width, const int height)
{
  FILE *fp;

  if ((fp = fopen(filename, "w")) == 0)
    {
      fprintf(stderr, "ERROR: Opening file '%s' for write.\n", filename);
      exit(0);
    }

  fprintf(fp, "P6\n%d %d\n255\n", width, height);
  
  return fp;
}
