#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
//#include "zero_lib.h"

using namespace std;


double fexp_m(double x)
{
  return exp(-x) - x;
}

double fexp_p(double x)
{
  return exp(2*x) - 3*x - 4;
}

double fud(double x)
{
  return 1 + 2*x*x - x*x*x;
}


void poorman_bracketing(double (*f)(double x), double &x1, double &x2, int &ifail)
{
  ifail = 1;
  int N = 50;
  double h = (x2 - x1)/N;
  double f1, f2, fprod;
  f1 = (*f)(x1);
  for(int i=0; i<N; i++){
    x2 = x1 + h;
    f2 = (*f)(x2);
    fprod = f1*f2;
    if(fprod < 0){
      ifail = 0;
      break;
    }
    x1 = x2;
    f1 = f2;
  }
  x2 += h;
  return;
}

void knuth_bracketing(double (*f)(double x), double &x1, double &x2, int &ifail)
{
  ifail = 1;
  int N = 50;
  double const alpha = 1.65;
  double y1 = x1;
  double y2 = x2;
  double f1, f2, fprod, temp;
  f1 = (*f)(x1);
  for(int i=0; i<N; i++){
    if(abs(f1) > abs(f2)) temp = (x2 - x1);
    else temp = (x1 - x2);
    x1 = x2;
    x2 += alpha*temp;
    f2 = (*f)(x2);
    fprod = f1*f2;
    if(fprod < 0){
      ifail = 0;
      break;
    }
    f1 = f2;
  }  
  return;
}

int main()
{
  double x1;
  double x2;
  cerr << "Insert begin and end of interval:\n";
  cin >> x1 >> x2;

  int bohl;

  int pm_fail;
  int kn_fail;
  poorman_bracketing(&fud, x1, x2, pm_fail);
  while(pm_fail == 1){
    knuth_bracketing(&fud, x1, x2, kn_fail);
    poorman_bracketing(&fud, x1, x2, pm_fail);
  }
  
  
  //knuth_bracketing(&fud, x1, x2, ifail);
  /*switch(ifail){
    case(0):*/
    cerr << "Bracketed interval:\n";
    cerr << setw(20) << left << x1 << x2 << endl;/*
    break;
  case(1):
    cerr << "Bracketing failed\n";
    break;
  }
  */

  return 0;
}
