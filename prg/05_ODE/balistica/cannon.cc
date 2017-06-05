#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

const double rho_air = 1.22; //kg/m^3
const double D = 0.35; //constant of turbolent motion
const double g = 9.81;

int main()
{
  double y, v, theta;
  cerr << "Insert initial y, v, theta (deg):\n";
  cin >> y >>  v >> theta;
  theta *= M_PI/180.;
  double x = 0;
  double vx = v*cos(theta);
  double vy = v*sin(theta);
  //cerr << sqrt(vx*vx+vy*vy) << endl;

  double x_f = x;
  double y_f = y;
  double vx_f = vx;
  double vy_f = vy;
  
  double m, A;
  cerr << "Insert m, A:\n";
  cin >> m >> A;
 
  double dt, vy0, vy0_f;
  dt = .01;
  int N = 1500;

  double mult = 1./(2*m)*D*rho_air*A;

  for(int i=0; i<N; i++){

    if(i%3==0){
      cout
	<< setw(15) << left << i*dt
	<< setw(15) << left << x
	<< setw(15) << left << y
	<< setw(15) << left << vx
	<< setw(15) << left << vy
	<< setw(15) << left << x_f
	<< setw(15) << left << y_f
	<< setw(15) << left << vx_f
	<< setw(15) << left << vy_f
	<< endl;
    }
    
    vy0 = vy;
    v = sqrt( vx*vx + vy*vy );
    if( i<10 or (y+vy0*dt)>0) vy = vy0 * ( - g - mult*v*vy ) * dt;
    else vy = - vy0;
    x = x + vx  * dt;
    y = y + vy0 * dt;
    vx += ( - 1./(2*m)*D*rho_air*A*v*vx ) * dt;


    vy0_f = vy_f;
    v = sqrt( vx_f*vx_f + vy_f*vy_f );
    if((y_f+vy0_f*dt)>0 or i<10) vy_f = vy0_f - g * dt;
    else vy_f = -vy0_f;
    x_f = x_f + vx_f  * dt;
    y_f = y_f + vy0_f * dt;
    cout << vx << " " << vy << endl;
    cout << vx_f << " " << vy_f << endl;

  }
   
  return 0;
}
