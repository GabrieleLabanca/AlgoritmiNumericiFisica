#include <iostream>
#include <cmath>
#include <iomanip>
#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/rnd_generators.hh"

using namespace std;

int main()
{
  cerr << "Insert initial number of atoms:\n";
  int N0;
  cin >> N0;
  /*
  cerr << "Insert time of decay tau:\n";
  float tau;
  cin >> tau;
  cerr << "Insert unit of time:\n";
  float dt;
  cin >> dt;
  */
  /*
  cerr << "Insert probability of decay in unit of time:\n";
  float P;
  cin >> P;
  */
  float P = 0.3;
  cerr << "Probability of decay in unit of time fixed at " << P << endl;
  /*cerr << "Insert unit of time [0:1]:\n";
  float dt;
  cin >> dt;
  cerr << "Insert number of calls:\n";
  int ncalls;
  cin >> ncalls;
  */

  //float tau = dt/P;
  int decayed = 0;

  randomize48();

  int N = N0;
  int j = 0;

  while(N>0){
    N -= decayed;
    decayed = 0;
    for(int i=0; i<N; i++){
      if(rnd_uni(0,1) < P) decayed++;
    }
    cout << setw(20) << left << j;
    cout << setw(20) << left << float(N)/N0 << endl; //<< exp(-j*dt/tau) << endl;
    j++;
  }
  






  return 0;
}
