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
  return 1 + (x+1)*(x+1) - x*x*x;
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

double zero_bisection( double (*f)(double x), double x1, double x2,
		       double x_accuracy, double y_accuracy, int &ifail)
{
  ifail = 1;
  int N = 50;
  bool xcheck, ycheck;
  double f1, f2, fprod;
  double deltax, deltay;
  double xm, xzero;
  f1 = (*f)(x1);
  deltax = x2 - x1;
  
  for(int i=0; i<N; i++){
    xm = x1 + deltax/2.;

    f2 = (*f)(xm);

    if(f1*f2 < 0){
      deltax /= 2.;
    }
    else if(f1*f2 > 0){
      x1 = xm;
    }
    deltay = f1 - f2;
    ///*!!*/deltay = f2;
    xcheck = sqrt(deltax*deltax) < x_accuracy;
    ycheck = sqrt(deltay*deltay) < y_accuracy;

    
    if( xcheck or ycheck ){
      xzero = xm; 
    	   
      ifail = 0;
      cerr << "iterations : " << i << endl;
      return xzero;
      break;
    }
  }

  return xzero;
}
double zero_regulafalsi( double (*f)(double x), double x1, double x2,
		       double x_accuracy, double y_accuracy, int &ifail)
{
  ifail = 1;
  int N = 50;
  bool xcheck, ycheck;
  double f1, f2, fprod;
  double ftemp, xtemp;
  double deltax, deltay;
  double xm, xzero;
  f1 = (*f)(x1);
  deltax = x2 - x1;
  xm = x2;
  
  for(int i=0; i<N; i++){
    cerr << "_______________________" << endl;   
    f2 = (*f)(xm);
    xm = (f2*x1 - f1*xm)/(f2-f1);

  
    
    cerr << "x1 " << x1 << " xm " << xm << endl;
    cerr << "f1 " << f1 << " f2 " << f2 << endl;
    fprod = f1*f2;
    cerr << "fprod " << fprod << endl;
    

    if(f1*f2 < 0){
      //nothing to do
    }
    else if(f1*f2 > 0){
      x1 = xm;
      f1 = f2;
      //cerr << "x1 changed\n";
    }
    deltay = f1 - f2;
    ///*!!*/deltay = f2;
    xcheck = sqrt(deltax*deltax) < x_accuracy;
    ycheck = sqrt(deltay*deltay) < y_accuracy;

    if( xcheck or ycheck ){
      xzero = xm; 
      //cerr << i << " iterations\n";	  
	   
      ifail = 0;
      return xzero;
      break;
    }
  }

  return xzero;
}



int main()
{
  double x1;
  double x2;
  cerr << "Insert begin and end of interval:\n";
  cin >> x1 >> x2;

  double (*myfunc)(double x) = &fexp_m;//&fud;


  int tot_fail;
  //////////////////////////////////////////////////////////
  // Not convenient to iterate poorman/knuth alternance
  int pm_fail;
  int kn_fail;
  poorman_bracketing(myfunc, x1, x2, tot_fail);
  pm_fail = tot_fail;
  //while(pm_fail == 1){
  if(pm_fail == 1) {
    knuth_bracketing(myfunc, x1, x2, tot_fail);
    kn_fail = tot_fail;
  }
  //////////////////////////////////////////////////////////

  // exit if no zero found
  if(tot_fail == 1){
    cerr << "!no zero found!\n";
    return 1;
  }

  
  cerr << "Bracketed interval:\n";
  cerr << setw(20) << left << x1 << x2 << endl;
 
   

  /* zero_bisection( double (*f) (double x), double x1, double x2,
     double x_accuracy, double y_accuracy, int &ifail)*/
  double x_acc, y_acc, x_zero;
  cerr << "Insert desired accuracy in x and f(x)\n";
  cin >> x_acc >> y_acc;
  // x_zero = zero_bisection(myfunc,x1,x2,x_acc,y_acc,tot_fail);
  x_zero = zero_regulafalsi(myfunc,x1,x2,x_acc,y_acc,tot_fail);
  cerr << "Zero of the function is in " << x_zero << endl;
  cerr << "Value of the function in this zero is " << (*myfunc)(x_zero) << endl;
  




  return 0;
}
