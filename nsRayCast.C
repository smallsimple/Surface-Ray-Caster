#include "nsRayCast.h"

void nsRenderFcn(const char *ppmFilename, const double dz, const int pRes,
		 const unsigned char r, const unsigned char g, const unsigned char b,
		 Gaussians mballs)
{
  FILE *ppmFP = openPPMFile(ppmFilename, pRes, pRes);

  const unsigned char bckgrnd[3] = {r, g, b};

  unsigned char grey[3];

  const double dx = 2.0/pRes, dy = 2.0/pRes;

  double x, y = 1. - dy;

  for (unsigned int iy = 0; iy < pRes; iy++, y -= dy)
    {
      x = -1. + dx;
      for (unsigned int ix = 0; ix < pRes; ix++, x += dx)
	{

	  /*
	   * Call your root finding procedure here in your implementation
	   */
        double z = mballs.findRoot(x, y, dz, 100);
        // printf("z: %f\t\t", z);
	  //double z = mballs.root(x, y);
	  if (z < 1.)
	    {
	      grey[0] = grey[1] = grey[2] = shadeDepth(z);
	      fwrite(grey, 1, 3, ppmFP);
	    }
	  else
	    fwrite(bckgrnd, 1, 3, ppmFP);

	  /*
	   *
	   */

	}
    }

  fclose(ppmFP);
}

