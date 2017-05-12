/* bw_matrix.cc
 * generate a 0/1 matrix
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  int seed = time(NULL);
  srand48(seed);
  int dim = 25;
  cout << "Insert probability of full cell (between 0 and 1)\n";
  float prob0;
  cin >> prob0;
  
  for(int i=0; i<dim; i++){
    for(int j=0; j<dim; j++){
      if(drand48()>prob0) cout << 0 << " ";
      else cout << 1 << " ";
    }
    cout << endl;
  }

  return 0;
}
