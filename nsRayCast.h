#ifndef _NSRAYCAST
#define _NSRAYCAST

#include <stdio.h>
//#include "nsSpheres.h"
#include "nsGaussians.h"
#include "nsShade.h"
#include "nsPPM.h"

void nsRenderFcn(const char *, const double, const int, const unsigned char, const unsigned char,
		 const unsigned char, Gaussians);
#endif

