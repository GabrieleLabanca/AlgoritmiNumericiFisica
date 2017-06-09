#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "phys_constants.h"
#include "rk4s.h"
#include "lib_zero.h"

using namespace std;

void debug() { cerr << "DEBUG" << endl; }

double htc = Physics::htc; // hbar
double m_e = Physics::m_e; // electron mass
double mu = 2e4*m_e/(htc*htc); 
double E;
double dt;

double epsilon = 1.e-6;

double V(double x)
{
  double alpha = 0.5;   //eV/angstrom^2 
  double beta = 0.25;   //eV/angstrom^4 
  return alpha*x*x + beta*x*x*x*x; 
}

double Ediff(double x)
{
  return V(x)-E;
}  

void ydot(double x, double *y, double *dy)
{
  double psi = y[0];
  double v   = y[1];
  dy[0]=v;
  dy[1]=mu*Ediff(x)*psi; //second terms
}

int neq = 2;
int psi_E(double E, double *&psi_u, double *&psi_d, int &t_p)
{
  //static int index= 0;
  //cerr << "INDEX " << index++ << endl;
  double y[neq];

  double xmax = 5;//2.5*turning_point;
  double xmin = -5;//-xmax;
  int N = 2*xmax/dt;

  double f1, f2;
  t_p = 1;
  f2 = Ediff(xmin);
  while(f1*f2>0 and t_p < N){
    f1 = f2; 
    f2 = Ediff(xmin+(t_p)*dt);
    t_p++;
  }
 
  y[0] = 0;
  y[1] = epsilon;

  psi_u = new double[N];
  psi_d = new double[N];
  int j = 0;

  double x;
  
  x = xmin;
  while(x<xmax){
    rk4(x,dt,ydot,y,neq);
    psi_u[j] = y[0];
    j++;
  }

  
  x = xmax;
  j=0;
  y[0] = 0;
  y[1] = epsilon;
  while(x>xmin){
    rk4(x,-dt,ydot,y,neq);
    psi_d[N-j] = y[0]; // opposite verse
    j++;
  }

  return N;
}


char print = 'y';  
double dispE(double Energy)
{
  E = Energy;
  // psi_u runs from -xmin to xmin
  // psi_d runs from xmin to -xmin
  //      !!!
  // for psi_u use xm, for psi_d use N-xm
  double * psi_u;
  double * psi_d;
  int tp; // turning point
  int N = psi_E(E,psi_u,psi_d,tp);

  int xm = tp;
  //cerr << "xm " << xm << endl;
 
  double coeff = psi_u[xm]/psi_d[xm];
  //cerr << "coeff " << coeff << endl;

  for(int i=0; i<N; i++){
    psi_d[i] *= coeff;
  }

  if(print == 'y'){
    for(int i=0; i<N; i++){
      cout << -5+i*dt << " " << psi_u[i] << " " << psi_d[i] << endl;
    }
    print = 'n';
    cerr << "E = " << E << endl;
  }

  
  double psimod = sqrt(psi_u[xm]*psi_u[xm]);


  return (psi_u[xm-1] - psi_d[xm-1])/psimod;
  delete[] psi_u;
  delete[] psi_d;
}


int main()
{
  cerr << "Enter dt, energy:\n";
  cin >> dt >> E;
  
  fstream file_ediff("ediff.dat",fstream::out);
  for(int i=0; i<100; i++){
    double temp =  -5+i*dt;
    file_ediff << temp << " " << V(temp) << " " <<  Ediff(temp) << endl;
  }
 
  
   dispE(E);
  
  fstream out_dispE("dispE.dat",fstream::out);
  E = 0;
  double dE = 0.1;
  for(double i=0; i<1000; i++){
    out_dispE << (E+=dE) << " " << dispE(E) << endl;
  }

  for(int i=0; i<100; i++){
    double x1 =  i*0.1;
    double x2 = x1 + 0.1;
    int ifail;
    //cerr << "pre bracketing " << x1 << " " << x2 << endl;
    poorman_bracketing(dispE,x1,x2,ifail);
    if (ifail == 0) cerr <<"FOUND" << endl;
    cerr << "bracketing " << x1 << " " << x2 << endl;
    /*if(ifail == 0){
      double zerotemp =  zero_regulafalsi(dispE,x1,x2,0.00001,0.001,ifail);
      cerr << "zero in " << zerotemp << endl;
      if(ifail == 1) cerr << "ERROR" << endl;
    }
    */
   }
  
  
  return 0;
  }
  
