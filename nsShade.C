#include <stdlib.h>

unsigned char
shadeDepth(double z)
{
  return 255 - (unsigned char )(z * 127.5 + 128.0);
}
