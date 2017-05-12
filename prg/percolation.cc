/* bw_matrix.cc
 * generate a 0/1 matrix
 */
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct travel{
  int x,y;
};

void src_way(vector<travel>&, vector< vector<int> >);

int main()
{
  int seed = 1;// time(NULL);
  srand48(seed);
  int dim = 10;
  cout << "Insert probability of full cell (between 0 and 1)\n";
  float prob0;
  cin >> prob0;
  
  vector< vector<int> > M;
  M.resize(dim);
  for(int i=0; i<dim; i++) M.at(i).resize(dim);
  
  for(int i=0; i<dim; i++){
    for(int j=0; j<dim; j++){
      if(drand48()>prob0) M.at(i).at(j) = 0;
      else M.at(i).at(j) = 1;
    }
  }
  for(int i=0; i<dim; i++){
    for(int j=0; j<dim; j++){
      cerr << M.at(i).at(j) << " ";
    }
    cerr << endl;
  }
  
  
  vector<travel> history;
  travel guy;
  
  
  

  return 0;
}


void src_way(vector<travel>&, vector< vector<int> >)
{






  return 0;
}
