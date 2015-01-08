#include <stdlib.h>
#include <stdio.h>
#include "nsSpheres.h"
#include "nsRayCast.h"

#define NSNUMARGS 8


int main(int argc, char **argv)
{
  if (argc != NSNUMARGS)
    {
      fprintf(stderr, "usage: metaball <inFile .mball> <outFile .ppm> dz res r g b\n");
      return 1;
    }

  Gaussians mballs(argv[1]);
  nsRenderFcn(argv[2], atof(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]),
	      atoi(argv[7]), mballs);

  return 0;
}
