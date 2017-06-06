#include <iostream>
#include <iomanip>
#include <fstream>
#include "phys_constants.h"
#include "rk4s.h"
#include "lib_zero.h"

using namespace std;

double htc = Physics::htc; // hbar
double m_e = Physics::m_e; // electron mass
double mu = 2e4*m_e/(htc*htc); 
double E;
double dt;
double epsilon = 1.e-6;

double V(double x)
{
  double alpha = 0.5;   //eV/angstrom^2 
  double beta = 0.25;      //eV/angstrom^4 
  return alpha*x*x + beta*x*x*x*x; 
}

double Ediff(double x)
{
  return E-V(x);
}  

void ydot(double x, double *y, double *dy)
{
  double psi = y[0];
  double v   = y[1];
  dy[0]=v;
  dy[1]=mu*(-E+V(x))*psi; //second terms
}

int neq = 2;
int psi_E(double E, double *psi_u, double *psi_d, double &turning_point)
{
  double y[neq];
  
  double x1 = 0;
  double x2 = 5;
  int ifail;
  poorman_bracketing(Ediff,x1,x2,ifail);
  turning_point = zero_regulafalsi(Ediff,0.0,x2,0.00001,0.001,ifail);
  double xmax = 5;//2.5*turning_point;
  double xmin = -5;//-xmax;
  cerr << "Turning point " << turning_point << " ; xmax " << xmax << endl; 

  y[0] = 0;
  y[1] = epsilon;

  int N = 2*xmax/dt;
  psi_u = new double[N];
  psi_d = new double[N];
  int j = 0;

  double x;
  
  x = xmin;
  while(x<xmax){
    rk4(x,dt,ydot,y,neq);
    cout << setw(4)  << x
	 << setw(13) << y[0]
	 << setw(13) << y[1]
	 << endl;
    psi_u[j] = y[0];
    j++;
  }
  
  x = xmax;
  j=0;
  while(x>xmin){
    rk4(x,-dt,ydot,y,neq);
    /*cout << setw(4)  << x
         << setw(13) << y[0]
         << setw(13) << y[1]
         << endl;
    */
    psi_d[j] = y[0];
    j++;
  }

  return N;
}  
  
double dispE(double E)
{
  double * psi_u;
  double * psi_d;
  double tp;
  int N = psi_E(E,psi_u,psi_d,tp);

  int xm = tp/dt;
 
  for(int i=0; i<N;i++){
    cerr << i << " " << psi_u[i] << " " << psi_d[i] << endl;
  }
  
  double psimod = psi_u[xm]*psi_u[xm];

  return (psi_u[xm-1] - psi_d[xm-1])/psimod;
}

int main()
{
  cerr << "Enter dt, energy:\n";
  cin >> dt >> E;
  double turp;
  double * mypsi;
  //psi_E(E,mypsi,turp,'u');

  cerr << "diffE" << dispE(E) << endl;
  
  return 0;
}