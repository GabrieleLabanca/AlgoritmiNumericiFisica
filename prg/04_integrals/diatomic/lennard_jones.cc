#include <iostream>
#include <cmath>
#include <iomanip>

#include "lib_zero.h"
#include "quadrature.h"
#include "phys_constants.h"

using namespace std;


double eps; // eps = E/u0
double f_lennard_jones(double x) // x= R/a
{
  double t = x*x*x*x*x*x;
  return eps - 4.*( 1./t - 1 )/t;
}

double d_f_lennard_jones(double x)
{
  double t6 = x*x*x*x*x*x;
  double t7 = x*t6;
  return -24.*(1. - 2./t6)/t7;
}



int main()
{
  cerr << "Insert epsilon:\n";
  cin >> eps;
  cerr << "Insert desired accuracy in x and y:\n";
  double xacc, yacc;
  cin >> xacc, yacc;


  double y;
  for(int i=100; i<1000; i++){
    y = i/100.;
    cout << y << " " << f_lennard_jones(y) << " " << d_f_lennard_jones(y) << endl;
   }

  int ifail;

  double x_MAX = 7;
  double dx = 0.1;
  int N_interval = int(x_MAX/dx);
  double x1, x2;
  double z1,z2;

  // check that energy is negative
  if(eps > 0){
    cerr << "E must be negative!! EXIT\n";
    return 1;
  }
  
  // first half
  x1 = 1;
  x2 = pow(2.,1./6.) - 0.001;
  
  //  cerr << "z1: " << z1 << endl;
  z1 = zero_bisection(f_lennard_jones,x1,x2,.001,.001,ifail);
  cerr << "z1: " << z1 << endl;
  z1 = zero_newton(f_lennard_jones,d_f_lennard_jones,x1,x2,z1,xacc,yacc,ifail);

 



  //second half
  x1 = pow(2.,1./6.) + 0.001;
  x2 = x_MAX;

  z2 = zero_bisection(f_lennard_jones,x1,x2,.001,.001,ifail);
  cerr << "z2: " << setprecision(9) <<  z2 << endl;
  z2 = zero_newton(f_lennard_jones,d_f_lennard_jones,x1,x2,z2,xacc,yacc,ifail);
    
  if(ifail == 0) cerr << "ZERO FOUND" << endl;
  cerr << "zeros: "
       << setprecision(9) <<  z1 << " ; "
       << setprecision(9) <<  z2 << endl;
    







  return 0;
}
