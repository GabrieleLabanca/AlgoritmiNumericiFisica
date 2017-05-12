#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
  int seed = time(NULL);
  srand48(seed);

  int N;
  cerr << "Insert N of throws\n";
  cin >> N;

  fstream raw;
  fstream histo;
  int n_intervals = 30;
  float * h_array = new float[n_intervals];

  raw.open("raw_data.dat",fstream::out);

  float t;
  for(int i=0; i<N; i++){
    t = drand48();
    raw << setw(10) << left << t << 1 << endl;
    ++h_array[int(t*n_intervals)];
  }
  raw.close();

  float mean_freq = 0;
  for(int i=0; i<n_intervals; i++) {
    mean_freq += h_array[i]/(N*n_intervals);
    cerr << "mean frequency = " << mean_freq << endl;
  }

  histo.open("histo_data.dat",fstream::out);
  for(int i=0; i<n_intervals; i++){
    histo << setw(10) << left << float(i)/n_intervals << h_array[i]/N - mean_freq << endl;
  }
  histo.close();
  
  return 0;
}
