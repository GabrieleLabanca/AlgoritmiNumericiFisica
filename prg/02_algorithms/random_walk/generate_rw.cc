#include <iostream>
#include <iomanip>
#include <cmath>
#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/rnd_generators.hh"
#include <fstream>

using namespace std;

int main()
{
  cerr << "Generate a random series of coordinates\n";
  int N = 1000;

  randomize48();
  float x = 0;
  float y = 0;
  
  float dx, dy, norm;
 
  //fstream fileRN;
  //fileRN.open("R_N.dat",ios::app);
  
  
  for(int i=0; i<N; i++){
    //print random walks
    cout << setw(10) << left << x << y << endl;

    dx = rnd_uni(-1,1);
    dy = rnd_uni(-1,1);
    norm = dx*dx + dy*dy;
    dx /= norm;
    dy /= norm;
    x += dx;
    y += dy;

    
    

    //print R as a function of sqrt(N)
    //if((i%50)==0) cout << setw(10) << left << sqrt(double(i)) << sqrt(x*x + y*y) << endl;
  }

  






  return 0;
}
