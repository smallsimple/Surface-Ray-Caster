#include "nsSpheres.h"

Spheres::Spheres(const char *filename):Metaballs(filename), radii(0)
{
  if ((this->radii = (double *)malloc(sizeof(double) * this->nMetaballs)) == 0)
    {
      fprintf(stderr, "ERROR: Allocate radii array.\n", filename);
      exit(0);
    }

  fclose(fp);
  fp = 0;

  for (unsigned int i = 0; i < this->nMetaballs; i++)
    this->radii[i] = SPHSIZE;
}

Spheres::~Spheres()
{
  if (this->radii != 0)
    free(this->radii);
}


double
Spheres::root(double x, double y)
{
  double minZ = 1.;
  double det, z;

  for (unsigned int i = 0; i < this->nMetaballs; i++)
    {
      det = this->radii[i] * this->radii[i] -
	(x - this->centers[i].cx) * (x - this->centers[i].cx) -
	(y - this->centers[i].cy) * (y - this->centers[i].cy);

      if (det > 0)
	{
	  det = sqrt(det);

	  z = det + this->centers[i].cz;
	  if (z < minZ) minZ = z;

	  z = this->centers[i].cz - det;
	  if (z < minZ) minZ = z;
	}
    }

  return minZ;
}
