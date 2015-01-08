#ifndef _NSGAUSSIANS
#define _NSGAUSSIANS

#include <math.h>
#include "nsMetaballs.h"

class Gaussians: public Metaballs
{
    public:
        //constructors
        Gaussians():Metaballs(),a(0),b(1){};
        Gaussians(const char *filename);
        //member functions
        double eval (double x, double y, double z);//return f(x,y,z)

        unsigned int bracket(double x, double y, double z);

        double findRoot(double x, double y, double dz, unsigned int n);
        double findRootFcnErr(double x, double y, double dz, double fErr);
        double findRootLastErr(double x, double y, double dz, double lErr);
        double deval (double x, double y, double z);

        //destructors
        ~Gaussians();
    private:
        double a, b;
};

#endif
