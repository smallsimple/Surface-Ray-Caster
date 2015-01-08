#ifndef _NSMETABALLS
#define _NSMETABALLS

#include <stdlib.h>
#include <stdio.h>

class Metaballs {

typedef struct {
  double cx, cy, cz;
} Center;

public:
  Metaballs():nMetaballs(0), centers(0), lambda(0), rho(0), constantC(0){}; //Bobo add//
  Metaballs(const char *);
  ~Metaballs();

  unsigned int getnMetaballs() { return this->nMetaballs; }

protected:
  unsigned int nMetaballs;
  Center *centers;
  // Bobo add
  double *lambda, *rho, constantC;
  //
  FILE *fp;

};

#endif
