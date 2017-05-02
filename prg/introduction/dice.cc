#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>


using namespace std;

int main()
{
  int seed = time(NULL);
  srand48(seed);
  int N;// = 1000;
  cout << "Insert number of trials:\n";
  cin >> N;
  
  int sum = 0;
  
  
  int counters[11] = {0}; //but sum is in [2;12] !
    
  cout << "Generate " << N << " couples of dice numbers:\n";
  for(int i=0; i<N; i++){
    int A = int(6*drand48()+1);
    int B = int(6*drand48()+1);
    //cout << setw(10) << left << A << " " << B << endl;

    sum = A + B;

    counters[sum-2]++;
    /*for(int i=0; i<11; i++){
      if(sum == (i+2)) counters[i]++;
    }
    */
  }

  //int n_occurrences = 0;
  //int total_sum = 0;
  //cout << setw(20) << left
       << "sum equals to" << "probability" << endl;
  for(int i=0; i<11; i++){
    cout << setw(20) << left
	 << i+2 << float(counters[i])/N;
    //cout << " +/- " << sqrt(double(counters[i]))/N << endl;
    ///n_occurrences += counters[i];
    //total_sum += (i+2)*counters[i];
  }



  
  
  //cout << "Total occurrences = " << n_occurrences << endl;
  //cout << "Mean of the sum = " << float(total_sum)/n_occurrences << endl;
  
    
  
  











  return 0;
}
