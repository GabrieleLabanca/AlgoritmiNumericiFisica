#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/lib_zero.h"
#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/lib_special.h"


using namespace std;

/*

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
    //!!deltay = f2;
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
    //cerr << "_______________________" << endl;   
    f2 = (*f)(xm);
    xm = (f2*x1 - f1*xm)/(f2-f1);

  
    
    //cerr << "x1 " << x1 << " xm " << xm << endl;
    //cerr << "f1 " << f1 << " f2 " << f2 << endl;
    fprod = f1*f2;
    //cerr << "fprod " << fprod << endl;
    

    if(f1*f2 < 0){
      //nothing to do
    }
    else if(f1*f2 > 0){
      x1 = xm;
      f1 = f2;
      //cerr << "x1 changed\n";
    }
    deltay = f1 - f2;
    //!!deltay = f2;
    xcheck = sqrt(deltax*deltax) < x_accuracy;
    ycheck = sqrt(deltay*deltay) < y_accuracy;

    if( xcheck or ycheck ){
      xzero = xm; 
      //cerr << i << " iterations\n";	  
	   
      ifail = 0;
      return xzero;
    }
  }

  return xzero;
}

double zero_newton( double (*f)(double x), double (*f_der)(double x),
		    double x1, double x2, double est0, //est0 is the previous esteem
		    double x_accuracy, double y_accuracy, int &ifail)
{
  ifail = 1;
  int N = 50;
  bool xcheck, ycheck;
  double fold, fnew, dfold, dfnew;
  double deltax, deltay;
  double xold, xnew;

  xold = est0;
  
  fold = f(xold);
  dfold = f_der(xold);

  for(int i=0; i<N; i++){
    xnew = xold - ( fold / dfold );
    //cerr << " xnew = " << setprecision(11) << xnew << endl;

        
    fnew = f(xnew);
    
    
    deltax = xnew - xold;
    deltay = fnew - fold;
      
    xcheck = sqrt(deltax*deltax) < x_accuracy;
    ycheck = sqrt(deltay*deltay) < y_accuracy;
    if( xcheck or ycheck ){
      ifail = 0;
      return xnew;
    }

    fold = fnew;
    //dfnew = f_der(xnew);
    //dfold = dfnew
    dfold = f_der(xnew);
    
      
  }
  
  // fail: return the old value
  return xold;
}
*/


/*
double fexp_m(double x)
{
  return exp(-x) - x;
}

double fexp_m_der(double x)
{
  return -exp(-x) - 1;
}
*/




/*
double legendre(int n, double x)
{
  double y;

  if(n == 0) return y = 1;
  else if(n == 1) return y = 0;
  else y = 1/double(n+1) * ( (2*n+1)*x*legendre(n,x) - n*legendre(n-1,x)     );
  
  return y;
}

double d_legendre(int n, double x)
{
  double y;

  y = 1./(x*x - 1) * ( n*x*legendre(n,x) - n * legendre(n-1,x)   );
  
  return y;
}
*/

int N_ORDER;

double legendre_fixed(double x)
{
  return legendre(N_ORDER,x);
}

double d_legendre_fixed(double x)
{
  return d_legendre(N_ORDER,x);
}


int main()
{
  double x1;
  double x2;
  //cerr << "Insert begin and end of interval:\n";
  //cin >> x1 >> x2;

  N_ORDER = 1;

  double dx = 0.1;
  int N_division = 2/0.1 - 2; //mustn't go in -1, +1!!


  /* zero_bisection( double (*f) (double x), double x1, double x2,
     double x_accuracy, double y_accuracy, int &ifail)*/
  double x_acc, y_acc, x_zero;
  cerr << "Insert desired accuracy in x and f(x)\n";
  cin >> x_acc >> y_acc;


  
  for(int j=0; j<N_division; j++){

    cerr << "CICLO " << j << endl;

    
    x1 = (j+1) * dx;  //mustn't go in -1, +1!!
    x2 = (j+2) * dx;
    
    
    int tot_fail;
    //////////////////////////////////////////////////////////
    // Not convenient to iterate poorman/knuth alternance
    int pm_fail;
    int kn_fail;
    poorman_bracketing(legendre_fixed, x1, x2, tot_fail);
    pm_fail = tot_fail;
    //while(pm_fail == 1){
    if(pm_fail == 1) {
      continue;
    }
    //////////////////////////////////////////////////////////
    
    // exit if no zero found
    if(tot_fail == 1){
      cerr << "!no zero found!\n";
      //return 1;
    }
    
    
    cerr << "Bracketed interval:\n";
    cerr << setw(20) << left << x1 << x2 << endl;
    
    
    
   
    
    x_zero = zero_bisection(legendre_fixed,x1,x2,0.001,0.001,tot_fail);
    //x_zero = zero_regulafalsi(fexp_m,x1,x2,0.001,0.001,tot_fail);
    
    cerr << "rough zero = " << setprecision(12) <<  x_zero << endl;
    
    x_zero = zero_newton(legendre_fixed,d_legendre_fixed,x1,x2,x_zero,x_acc,y_acc,tot_fail);
    cerr << "Zero of the function is in " << x_zero << endl;
    cerr << "Value of the function in this zero is\n ####"
	 << setprecision(9) << legendre_fixed(x_zero) << endl;
    
    
    for(int i=-1000; i<1000; i++){
      
      cout << i/1000. << " "  << legendre_fixed(i/1000.) << " " << d_legendre_fixed(i/1000.)
	   << endl;
      //cerr << "AAA" << endl;
      
      
    }
  }




  return 0;
}
