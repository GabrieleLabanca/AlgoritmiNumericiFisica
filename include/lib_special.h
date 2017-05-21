#ifndef H_SPEC
#define H_SPEC

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;


double legendre(int n, double x)
{
  double y;

  if(n == 0) return y = 1;
  else if(n == 1) return y = x;
  else y = 1/double(n) * ( (2*n-1)*x*legendre(n-1,x) - (n-1)*legendre(n-2,x) );

  return y;
}

double d_legendre(int n, double x)
{
  double y;

  if(n == 0) return y = 0;
  else if(n == 1) return y = 0;
  else  y = 1./(x*x - 1) * ( n*x*legendre(n,x) - n * legendre(n-1,x) );

  return y;
}

#endif
