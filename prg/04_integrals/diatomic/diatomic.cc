/* TODO:
 * function parabolic: well centered!
 * d_f_parabolic
 * cfr. results LJ-parabolic
 */  


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

/*
double a, b, c;
double parabola(double x)
{
  return a*x*x + b*x + c;
}

double d_parabola(double x)
{
  return 2*a*x + b;
}
*/
double sqrt_lennard_jones(double x)
{
  return sqrt(f_lennard_jones(x));
}


int n;
double gam;
double xacc, yacc, quad_precision;
double action(double energy)//, double (*V)(double x), double (*dV)(double x))
{
  eps = energy;
  int ifail;
  double x_MAX = 7;
  //double dx = 0.1;
  //int N_interval = int(x_MAX/dx);
  double x1, x2;
  double z1, z2;

  //cerr << "epsilon = " << eps << endl;
  // first half
  x1 = 1;
  x2 = pow(2.,1./6.) - 0.001;
  z1 = zero_bisection(f_lennard_jones,x1,x2,.001,.001,ifail);
  z1 = zero_newton(f_lennard_jones,d_f_lennard_jones,x1,x2,z1,xacc,yacc,ifail);

  //second half
  x1 = pow(2.,1./6.) + 0.001;
  x2 = x_MAX;
  z2 = zero_bisection(f_lennard_jones,x1,x2,.001,.001,ifail);
  z2 = zero_newton(f_lennard_jones,d_f_lennard_jones,x1,x2,z2,xacc,yacc,ifail);
  //if(ifail == 0) cerr << "ZERO FOUND" << endl;
  // cerr << "zeros: "
  //     << setprecision(9) <<  z1 << " ; "
  //     << setprecision(9) <<  z2 << endl;
  return 2*gam*quad(sqrt_lennard_jones,z1,z2,quad_precision,'g') - 2*M_PI*(n+0.5); 
}

double parabola_eigenvalues(int q)
{
  double x0 = pow(2.,1./6.);
  double x8 = x0*x0*x0*x0 * x0*x0*x0*x0;
  double x14 = x8 * x0*x0 * x0*x0 * x0*x0;
  return -1 + (q+0.5)*2*sqrt(2)/gam*sqrt(6)*sqrt( 26/x14 - 7/x8 );
}



int main()
{
  cerr << "Insert desired accuracy in x and y:\n";
  cin >> xacc >> yacc;

  cerr << "Insert accuracy in quadrature method:\n";
  cin >> quad_precision;
  
  cerr << "Insert gamma:\n";
  cin >> gam;
  cerr << setw(5) << left << "n"
       << setw(15) << left << "zero"
       << setw(15) << left << "harmonic"
       << setw(15) << left << "sigma"
       << endl;
   for(n=0;n<9;n++){ // wkb method
    int efail;
    double e1, e2, e0;
    double dE = 0.01;
    int N_steps = 1./dE;
    for(int en=0.; en<N_steps-1; en++){
      e1 = -1. + en*dE;
      e2 = e1 + dE;
      poorman_bracketing(action,e1,e2,efail);
      if(efail == 0){
	e0 = zero_bisection(action,e1,e2,xacc,yacc,efail);
	cerr << setw(5) << left <<  n
	     << setprecision(10) << setw(15) << left  << e0
	  //<< setw(10) << left
	     << setprecision(10) << setw(15) << left << parabola_eigenvalues(n)
	     << setw(15) << left << setprecision(2) <<  abs((e0 - parabola_eigenvalues(n))/e0)
	     << endl;
      }
    }
  }

  return 0;
}
