#include "nsGaussians.h"

Gaussians::Gaussians(const char *filename):Metaballs(filename), a(0), b(1)
{

    if(this->nMetaballs == 0)
    {
      fprintf(stderr, "ERROR: Allocate array.\n", filename);
      exit(0);
    }

    fclose(fp);
    fp=0;
}

double Gaussians::eval(double x, double y, double z)
{
    double sum=0;
    for(int i=0; i<this->nMetaballs; i++)
    {
        sum += this->lambda[i]*exp(- this->rho[i]*((x - this->centers[i].cx)*(x - this->centers[i].cx) + (y - this->centers[i].cy)*(y - this->centers[i].cy)+(z-this->centers[i].cz)*(z-this->centers[i].cz)));
    }
    //if (sum >= 0.00001) printf("location1: %f %f %f %f %f\t gaussiansum: %f\n", x, y, z, this->a, this->b, sum);
    return sum - this->constantC;
}

unsigned int Gaussians::bracket(double x, double y, double dz)
{
    double *zroot;
    double d= 2.0/dz;
    int n=(int)d, f=0;
    zroot=(double *)malloc(sizeof(double)*(n+1));
    //printf("n:%d\n", n);

    for (int i= 0; i<= n; i++)
    zroot[i]=-1 + i*dz;
    for (int i= 0; i<n; i++)
    {
        //printf("how?\n");
        if (this->eval(x, y, zroot[i])*this->eval(x,y,zroot[i+1])<=0)
        {   this->a = zroot[i];
            this->b = zroot[i+1];

            f = 1;
            //printf("location2: %f\t%f\t%f\t%f\t%f\t%f\n", x, y, this->a, this->b, this->eval(x,y,zroot[i]), this->eval(x,y,zroot[i+1]));
            return 1;

            break;

        }
    }
    if (f==0)
    //printf("helelehelej\n");
    return 0;
}

double Gaussians::findRoot(double x, double y, double dz, unsigned int n)
{
    double a, b, c, d, error=0.0000001;
    a = this->a;
    b = this->b;
    //printf("%f\t%f\t\t", this->a, this->b);

    if (this->bracket(x,y,dz) == 1)
    {
        //printf("3: %f\t%f\t%f\t%f\t%f\t%f\n", x,y,a,b,this->eval(x,y,a), this->eval(x,y,b));
        for(int i=0; i< n; i++) //bisection
        {
            c = (a+b)/2;
            if(((this->eval(x,y,c))*(this->eval(x,y,a))) <= 0)
            {b = c; printf("error1\t");exit(1);}
            else if((this->eval(x,y,c))*(this->eval(x,y,b)) <= 0)
            {a = c; printf("error2\t");}
         //   else
          //  printf("Error\n");
        }
        // Newton
        c=(a+b)/2;
        while ( ( d = this->eval(x,y,c)/this->deval(x,y,c)) >error)
        {
            c = c - d;
        }
        return c;
    }

    else
    return 2;
}

double Gaussians::findRootFcnErr (double x, double y, double dz, double fErr)
{
    double a, b, c, d, error=0.000001;
    a = this->a;
    b = this->b;

    if (this->bracket(x,y,dz) == 1)
    {
        while (1) //bisection
        {
            c = (a+b)/2;
            if((this->eval(x,y,c)) < fErr)
            break;
            if((this->eval(x,y,c)*this->eval(x,y,a)) <= 0)
            b = c;
            else if((this->eval(x,y,c))*(this->eval(x,y,b)) <= 0)
            a = c;
         //   else
        //    printf("Error\n");
        }
        while ( ( d = this->eval(x,y,c)/this->deval(x,y,c)) >error)
        {
            c = c - d;
        }
        return c;
    }
    if(this->bracket(x,y,dz)==0)
    return NULL;
}

double Gaussians::findRootLastErr(double x, double y, double dz, double lErr)
{
    double a, b, c, d, error=0.000001;
    a = this->a;
    b = this->b;

    if (this->bracket(x,y,dz) == 1)
    {
        d = b-a;
        while (1) //bisection
        {
            c = (a+b)/2;
            d = d/2;
            if ( d < lErr)  break;
            if((this->eval(x,y,c)-this->constantC)*(this->eval(x,y,a)-this->constantC) <= 0)
            b = c;
            else if((this->eval(x,y,c)-this->constantC)*(this->eval(x,y,b)-this->constantC) <= 0)
            a = c;
           // else
           //printf("Error\n");
        }
        while ( ( d = this->eval(x,y,c)/this->deval(x,y,c)) >error)
        {
            c = c - d;
        }
        return c;
    }
    if(this->bracket(x,y,dz)==0)
    return NULL;
}

double Gaussians::deval(double x, double y, double z)
{
    double sum=0;
    for(int i=0; i<this->nMetaballs; i++)
    {
        sum += this->rho[i]*(z - this->centers[i].cz)*this->lambda[i]*exp(- this->rho[i]*((x - this->centers[i].cx)*(x - this->centers[i].cx) + (y - this->centers[i].cy)*(y - this->centers[i].cy)+(z-this->centers[i].cz)*(z-this->centers[i].cz)));
    }
    return sum*(-2.0);
}

Gaussians::~Gaussians()
{

}
