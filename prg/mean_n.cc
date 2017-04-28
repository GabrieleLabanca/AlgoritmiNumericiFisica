#include <iostream>

using namespace std;

double mean(int * , int);



int main()
{
  cout << "Insert number\n";
  int n;
  cin >> n;

  int * vec = new int[n];  
  for(int i=0; i<n; i++){
    vec[i] = i+1;
  }

  cout << "The mean of numbers from 1 to n is "
       << mean(vec,n)
       << endl;


  return 0;
}

double mean(int * numbers, int d)
{
  float mean = 0;
  for(int i=0; i<d; i++){
    mean += numbers[i];
  }
  return mean/d;
}
  
