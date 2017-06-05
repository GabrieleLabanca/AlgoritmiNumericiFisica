#ifndef RUNGEKUTTA4SIMMETRIC_H
#define RUNGEKUTTA4SIMMETRIC_H

#include<iostream>
#include<iomanip>
#include<math.h>

void rk4 (double &t, double h, 
          void (*ydot) (double t, double *y, double *dy),
          double *y, 
          int neq )
{
  //
  // FISICA NUMERICA (GZP)
  // rk4s.cc - Program to solve a system of first order differential 
  //           equation. Initial value problem. 
  //           4 points Runge-Kupta
  //
  double fk1[neq], fk2[neq], fk3[neq], fk4[neq];
  double  yt[neq],  dy[neq];
  int i;

  double h12=h/2.;
  ydot(t,y,dy);
  for (i=0; i<neq; i++)
   {
     fk1[i]=h*dy[i];
     yt[i]=y[i]+fk1[i]*0.5;
   }
  ydot(t+h12,yt,dy);
  for (i=0; i<neq; i++)
   {
     fk2[i]=h*dy[i] ;
     yt[i]=y[i]+fk2[i]*0.5 ;
   }
  ydot(t+h12,yt,dy);
  for (i=0; i<neq; i++)
   {
     fk3[i]=h*dy[i];
     yt[i]=y[i]+fk3[i];
   }
  ydot(t+h,yt,dy);
  for (i=0; i<neq; i++)
   {   
     fk4[i]=h*dy[i];
     y[i]=y[i]+(fk1[i]+2.*fk2[i]+2.*fk3[i]+fk4[i])/6.;
   }
  t=t+h;
}


/*
void ydot(double t,double *y, double *dy)
{
  dy[0]=1.+4.*t-4.*y[1]-2.*y[0];
  dy[1]=1.5*t*t+y[1]-y[0];
}


int main()
{
 int  neq=2;
 double y[neq],yex[neq];
 double tfin,dt;

 cout << "Enter tfin,h" << endl;
 cin >> tfin >> dt;

 y[0]=1.;
 y[1]=0.;
 double t=0.;

 while (t <= tfin)
  {
    rk4(t,dt,ydot,y,neq);
    // yex is the analytical solution
    yex[0]=exp(2.*t)/5.+4.*exp(-3.*t)/5.+t*t+t;
    yex[1]=-exp(2.*t)/5.+exp(-3.*t)/5.-0.5*t*t;

    cout << setw(4)  << t 
         << setw(13) << y[0]
         << setw(13) << y[1]
         << setw(13) << yex[0]
         << setw(13) << yex[1]
         << endl;
  }
 return 0;
}
*/

#endif


