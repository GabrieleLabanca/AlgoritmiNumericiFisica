/* scalar product, with Euclidean and Minkowskian (+,-,-,...) metrics
 * different ways: 
 *  - arrays
 *  - std:vectors
 */
#include<iostream>
#include<iomanip>      // setw
#include<stdlib.h>     // srand, rand 
#include<time.h>       // time
#include<vector>

using namespace std;

// Euclidean product
float scal_eucl(const float *, const float *, int);
// Minkowskian product
float scal_mink(const float *, const float *, int);
// general scalar product with vectors
template<typename T>
float scalar(vector<T> & v, vector<T> & w, char metric);


int main()
{
  // arrays with random values
  cout << "Euclidean vectors\nInsert number of dimensions ";
  int D;
  cin >> D;
  float * a = new float[D];
  float * b = new float[D];

  srand (time(NULL));
  for(int i=0; i<D; i++){
    a[i] = (rand() % 1000)/100.0;
    b[i] = (rand() % 1000)/100.0;
  }

  // cout the arrays
  cout << "Two D-dimensional vectors created.\n"
       << setw(10) << left
       << "a" << "b" << endl;
  for(int i=0; i<D; i++) cout << setw(10) << left << a[i] << b[i] << endl;

  // products with arrays 
  cout << "Euclidean product:\n"
       << scal_eucl(a, b, D) << endl
       << "Minkowskian product:\n"
       << scal_mink(a,b,D) << endl
       << endl;

  // transfer data into std::vectors
  vector<float> A, B;
  A.resize(D);
  B.resize(D);
  for(int i=0; i<D; i++) {
    A.at(i) = a[i];
    B.at(i) = b[i];
  }
  

  // products with vectors
  cout << "Products with std::vectors\n"
       << "Euclidean product:\n"
       << scalar(A,B,'e') << endl
       << "Minkowskian product:\n"
       << scalar(A,B,'m') << endl
       << endl;


  

  return 0;
}
  
float scal_eucl ( const float * v, const float * w, int dim)
{
  float res = 0;
  for(int i=0; i<dim; i++) res += v[i] * w[i];
  return res;
}

float scal_mink ( const float * v, const float * w, int dim)
{
  float res = v[0]*w[0];
  for(int i=1; i<dim; i++) res -= v[i] * w[i];
  return res;
}

template<typename T>
float scalar(vector<T> & v, vector<T> & w, char metric)
{
    if(v.size() == w.size() ) {
    float res = v.at(0) * w.at(0);
    switch(metric){
    case 'e':
      for(int i=1; i<v.size(); i++) res += v.at(i) * w.at(i);
      break;
    case 'm':
      for(int i=1; i<v.size(); i++) res -= v.at(i) * w.at(i);
      break;
    }   
  return res;
  }
  else {
    cout << "!! Different dimensionality of vectors !!\nZero is returned\n";
    return 0;
  }
    
}
