#include <iostream>
#include <iomanip>
#include <cmath>
#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/rnd_generators.hh"
//#include <fstream>

using namespace std;

int main()
{
  cerr << "Generate a random series of coordinates\n";
  int N = 10000;
  int n_walk;

  cin >> n_walk;

  randomize48();
  float * x = new float[n_walk];
  float * y = new float[n_walk];
  
  float dx, dy, norm, theta;

  float mean_R=0;

  char mode;
  cin >> mode;
  
  //cout << setw(10) << left << x << y << endl;
  for(int i=0; i<N; i++){
    
    if((i%1) == 0) cout << setw(10) << left
		      //<< i
			 << sqrt(double(i))
			 << mean_R/n_walk
			 << endl;
    mean_R = 0;
    
    for(int j=0; j<n_walk; j++){
      
      switch(mode){
      case('a'):
	dx = rnd_uni(-1,1);
	dy = rnd_uni(-1,1);
	norm = sqrt(dx*dx + dy*dy);
	dx /= norm;
	dy /= norm;
	break;
      case('b'):
	theta = rnd_uni(0,2*M_PI);
	dx = cos(theta);
	dy = sin(theta);
	break;
      case('c'):
	dx = rnd_uni(-1,1);
	if(rnd_uni(0,1)<=0.5) dy = -sqrt(1-dx*dx);
	else dy = sqrt(1-dx*dx);
	break;
      case('d'):
	dx = rnd_uni(-sqrt(2),sqrt(2));
	dy = rnd_uni(-sqrt(2),sqrt(2));
	break;
      case('e'):
	// here norm is used as a temp variable!
	norm = rnd_uni(0,1);
	if(norm < 0.25)      dx =  1;
	else if(norm < 0.5)  dx = -1;
	else if(norm < 0.75) dy =  1;
	else                 dy = -1;
      }
    
      x[j] += dx;
      y[j] += dy;
      dx = 0;
      dy = 0;
      mean_R += sqrt(x[j]*x[j] + y[j]*y[j]);
            
      //print random walks
      //cout << setw(10) << left << x << y << endl;
      
      //print R as a function of sqrt(N)
      //if((i%50)==0) cout << setw(10) << left << sqrt(double(i)) << sqrt(x*x + y*y) << endl;
    }

  }

  
  return 0;
}
