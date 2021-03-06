#ifndef H_ZERO
#define H_ZERO

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;



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
      x2 += h;
      break;
    }
 
    
    x1 = x2;
    f1 = f2;
  }
  //x2 += h;
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
      //cerr << "iterations : " << i << endl;
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
    deltax = x1 - xm;
    deltay = f1 - f2;
    ///*!!*/deltay = f2;
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
  double xn, fn, dfn;
  double deltax, deltay;


  xn = est0;
     
  fn = f(xn);
  dfn = f_der(xn);
  deltax = xn;
  deltay = fn;

  for(int i=0; i<N; i++){
    xn = xn - ( fn / dfn );
    fn = f(xn);
        
    deltax -= xn;
    deltay -= fn;
          
    xcheck = sqrt(deltax*deltax) < x_accuracy;
    ycheck = sqrt(deltay*deltay) < y_accuracy;
    if( xcheck or ycheck ){
      ifail = 0;
      return xn;
    }
  }
  

  // fail: return the old value
  return xn;
}

#endif
