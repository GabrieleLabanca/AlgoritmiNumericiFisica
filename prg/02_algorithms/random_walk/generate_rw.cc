#include <iostream>
#include <iomanip>
#include <cmath>
#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/rnd_generators.hh"

using namespace std;

int main()
{
  cerr << "Generate a random series of coordinates\n";
  int N = 30;

  randomize48();
  float x = 0;
  float y = 0;
  
  float dx, dy, norm;

  for(int i=0; i<N; i++){
    dx = rnd_uni(-1,1);
    dy = rnd_uni(-1,1);
    norm = dx*dx + dy*dy;
    dx /= norm;
    dy /= norm;
    x += dx;
    y += dy;
    cout << setw(10) << left << x << y << endl;
  }







  return 0;
}
