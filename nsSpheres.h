#ifndef _NSSPHERES
#define _NSSPHERES

#include <math.h>
#include "nsMetaballs.h"
#define SPHSIZE 0.1

class Spheres : public Metaballs {
public:
  Spheres():Metaballs(),radii(0){};
  Spheres(const char *filename);
  ~Spheres();

  double root(double x, double y);

private:
  double *radii;
};

#endif
