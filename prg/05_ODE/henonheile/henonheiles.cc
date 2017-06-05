#include<iostream>
#include<iomanip>
#include<math.h>
#include <fstream>
#include "rk4s.h"

using namespace std;

// y = (x, px, y, py)
void ydot(double t, double *y, double *dy)
{
  double X  = y[0];
  double px = y[1];
  double Y  = y[2];
  double py = y[3];
  dy[0] = px;
  dy[1] = - X - 2*X*Y;
  dy[2] = py;
  dy[3] = - Y - X*X + Y*Y;
}

double H(double * y)
{
  double X  = y[0];
  double px = y[1];
  double Y  = y[2];
  double py = y[3];
  return 0.5 * (px*px + py*py) + X*X/2. + Y*Y/2.  + X*X*Y - Y*Y*Y/3.;
}

int main()
{
  int neq = 4;
  double y[neq];
  double tfin, dt;
  
  cout << "Enter tfin,h" << endl;
  cin >> tfin >> dt;

  cout << "Enter x, px, y, py:\n";
  cin >> y[0] >> y[1] >> y[2] >> y[3];
  double t=0.;



  fstream file_zerox ("y_py.dat",fstream::out);

  cerr << "Energy:\n";
  while(t <= tfin)
    {
      double X  = y[0];
      double px = y[1];
      double Y  = y[2];
      double py = y[3];
      double x0 = X;
      double y0 = Y;
      double px0 = px;
      double py0 = py;
      
      rk4(t, dt, ydot, y, neq);
      
      cout << setw(4)  << t 
	   << setw(13) << y[0]
	   << setw(13) << y[1]
	   << setw(13) << y[2]
	   << setw(13) << y[3]
	   << endl;

      
      if(x0*X < 0){
	double pxinter = px - X*(px0-px)/(x0-X);
	double yinter= Y - X*(y0-Y)/(x0-X);
	double pyinter = py - X*(py0-py)/(x0-X);
	file_zerox << pxinter << " " << yinter << " " << pyinter << endl;
      }
      
    }
  cerr << H(y) << endl;
  
  return 0;
}
