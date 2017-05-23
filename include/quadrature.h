#ifndef QUAD_H
#define QUAD_H

#include <iostream>
#include <cmath>



//
// Function quad - it calculate the definite integral of an external function
// provided by the user.
//
double quad(double (*func)(double x), double xa, double xb, 
            double acc, char mth)
{
  using namespace std;
  int    n_inter = 32;
  
  int    n_gint  = 1;
  int    ng      = 8;
  double gp[8] = {-0.96028986,-0.79666648,-0.52553241,-0.18343464,
		  0.18343464, 0.52553241, 0.79666648, 0.96028986};
  double gw[8] = { 0.10122854, 0.22238103, 0.31370665, 0.36268378,
		   0.36268378, 0.31370665, 0.22238103, 0.10122854};
  
  double sum0=1.e120;
  double err=1.;
  switch(mth)
    {
    case 'R':
    case 'r':
      while ( err > acc )
	{
	  n_inter=n_inter*2;
	  double dx=(xb-xa)/n_inter;
	  double x=xa;
	  double sum1=0.;
	  for(int i=1; i<=n_inter; i++)
	    {
	      sum1=sum1+func(x);
	      x=x+dx;
	    }
	  sum1=sum1*dx;
	  err=abs(sum0-sum1);
	  sum0=sum1;
	}
      break;
    case 'T':
    case 't':
      while ( err > acc )
	{
	  n_inter=n_inter*2;
	  double dx=(xb-xa)/n_inter;
	  double sum1=func(xa)+func(xb);
	  double x=xa+dx;
	  for(int i=1; i<n_inter; i++)
	    {
	      sum1=sum1+2*func(x);
	      x=x+dx;
	    }
	  sum1=sum1*dx/2;
	  err=abs(sum0-sum1);
	  sum0=sum1;
	}
      break; 
    case 'S':
    case 's':
      while ( err > acc )
	{
	  n_inter=n_inter*2;
	  double dx=(xb-xa)/n_inter;
	  double sum1=func(xa)+func(xb);
	  double x=xa+dx;
	  double factor=4.;
	  for(int i=1; i<n_inter; i++)
	    {
	      sum1=sum1+factor*func(x);
	      factor=6.-factor;
	      x=x+dx;
	    }
	  sum1=sum1*dx/3;
	  err=abs(sum0-sum1);
	  sum0=sum1;
	}
      break;
    case 'G':
    case 'g':
      while ( err > acc )
	{
	  n_gint=n_gint*2;
	  double hx=(xb-xa)/(2.*n_gint);
	  double sum1=0.;
	  double bx;
	  for(int i=1; i<=n_gint; i++)
	    {
	      bx=xa + hx*(2*i - 1);
	      for (int k=0; k < ng; k++)
		{
		  sum1=sum1 + gw[k] * func(hx*gp[k]+bx);
		}
	    }
	  sum1=sum1*hx;
	  err=abs(sum0-sum1);
	  sum0=sum1;
	}
      break;
    default:
      cout << " Method not yet supported:" << endl;
      break;
    }
  
  return sum0;
}
/*
  double My_exp(double x)
  {
  return exp(-x);
  }
  
int main()
  {
    cout << " Enter xmin,xmax,acc and method (r,t,s,g) _>";

    double xmin,xmax,acc;
    char mth;
    cin >> xmin >> xmax >> acc >> mth;

    double value =quad(My_exp,xmin,xmax,acc,mth);
    double exact = exp(-xmin)-exp(-xmax);

    cout << "The value of the integral is = "
         << value  <<endl;

    cout << "The exact value is           = "
         << exact  <<endl;

    return 0;  
  }
*/

#endif
