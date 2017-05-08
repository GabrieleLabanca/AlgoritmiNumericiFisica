#include <iostream>
#include <iomanip>
#include <cmath>
#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/rnd_generators.hh"
//#include <fstream>

using namespace std;

int main()
{
  cerr << "Generate a random series of coordinates\n";
  int N = 1000;
  int n_walk;

  cin >> n_walk;

  randomize48();
  float * x = new float[n_walk];
  float * y = new float[n_walk];
  
  float dx, dy, norm;

  float mean_R=0;
  
  //cout << setw(10) << left << x << y << endl;
  for(int i=0; i<N; i++){
    if((i%1) == 0) cout << setw(10) << left
			<< sqrt(double(i))
			<< mean_R/n_walk
			<< endl;
    mean_R = 0;
    
    for(int j=0; j<n_walk; j++){
      dx = rnd_uni(-1,1);
      dy = rnd_uni(-1,1);
      norm = sqrt(dx*dx + dy*dy);
      dx /= norm;
      dy /= norm;
      x[j] += dx;
      y[j] += dy;
      mean_R += sqrt(x[j]*x[j] + y[j]*y[j]);
            
      //print random walks
      //cout << setw(10) << left << x << y << endl;
      
      //print R as a function of sqrt(N)
      //if((i%50)==0) cout << setw(10) << left << sqrt(double(i)) << sqrt(x*x + y*y) << endl;
    }

    
  }

  
  return 0;
}
