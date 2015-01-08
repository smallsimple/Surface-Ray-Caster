#include "nsMetaballs.h"

Metaballs::Metaballs(const char *filename)
{
  if ((fp = fopen(filename, "r")) == 0)
    {
      fprintf(stderr, "ERROR: Opening file '%s' for read.\n",
              filename);
      exit(0);
    }

  fscanf(fp, "%d\n", &(this->nMetaballs));

  if (this->nMetaballs >= 1)
    {

      if ((this->centers = (Center *)malloc(sizeof(Center) * this->nMetaballs)) == 0)
	{
	  fprintf(stderr, "ERROR: Allocate centers array.\n", filename);
	  exit(0);
	}

      for (unsigned int i = 0; i < this->nMetaballs; i++)
	{
	  float cx, cy, cz;
	  fscanf(fp, "%f %f %f\n", &cx, &cy, &cz);

	  this->centers[i].cx = cx;
	  this->centers[i].cy = cy;
	  this->centers[i].cz = cz;
	}
	// Bobo add
    if ((this->rho = ( double *)malloc(sizeof(double) * this->nMetaballs)) == 0)
    {
        fprintf(stderr, "ERROR: Allocate rho array.\n", filename);
        exit(0);
    }
    for (unsigned int i = 0; i < this->nMetaballs; i++)
    {
        float r;
        fscanf (fp, "%f\n", &r);
        this->rho[i] = r;
    }

    if ((this->lambda = (double *)malloc(sizeof(double) * this->nMetaballs)) == 0)
    {
        fprintf(stderr, "ERROR: Allocate lambda array. \n", filename);
        exit(0);
    }
    for (unsigned int i = 0; i< this->nMetaballs; i++)
    {
        float l;
        fscanf (fp, "%f\n", &l);
        this->lambda[i] =l;
    }

    if (this->constantC)
    {
        float c;
        fscanf (fp, "%f\n", &c);
        this->constantC = c;
    }
    ////
    }
  else
    {
      fprintf(stderr, "WARNING: No metaballs in file.\n");
      this->nMetaballs = 0;
      this->centers = 0;
    }
}

Metaballs::~Metaballs()
{
  if (this->centers != 0)
    free(this->centers);
    // Bobo add
    if (this->rho != 0)
    free(this->rho);
    if (this->lambda != 0)
    free (this->lambda);
    //if (this->constantC != 0)
    //free(this.constantC);
    ////
}
