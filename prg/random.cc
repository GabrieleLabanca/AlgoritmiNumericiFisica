#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

float mean(float *, int);
float sigma(float *, int);


int main()
{
  int seed = time(NULL);
  srand(seed);
  srand48(seed);

  cout << setw(15) << left << "rand" << "srand\n";

  for(int i=0; i<20; i++){
    cout << setw(15) << left << rand() << drand48() << endl;
  }

  cout << "Su quanti valori calcolare media e scarto?\n";
  int N;
  cin >> N;
  

  float * arr = new float[N];
  for(int i=0; i<N; i++){
    arr[i] = drand48();
  }
  
  cout << "Media e scarto su " << N << " numeri casuali tra 0 e 1\n"
       << "media: " << mean(arr,N)
       << "\nscarto: " << sigma(arr,N)
       << endl;

   return 0;
}
    
float mean(float * numbers, int d)
{
  float mean = 0;
  for(int i=0; i<d; i++){
    mean += numbers[i];
  }
  return mean/d;
}

float sigma(float * numbers, int d)
{
  float m = mean(numbers,d);
  float sigma;
  for(int i=0; i<d; i++){
    sigma += (numbers[i] - m) * (numbers[i] - m);
  }
  sigma /= d;
  return sqrt(sigma);
}
