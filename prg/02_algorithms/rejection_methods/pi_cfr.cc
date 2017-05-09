#include <iostream>
#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/rnd_generators.hh"
#include <iomanip>

using namespace std;


struct entry{
  float meas;
  float sum;
  float sumsq;
};

void thrw(int,entry&);

int main()
{

  randomize48();

  entry data; //container of data
  data.sum = 0;
  data.sumsq = 0;

  
  int N;
  cerr << "insert number of throws:\n";
  cin >> N;
  int n_trials;
  cerr << "insert number of trials:\n";
  cin >> n_trials;


  int n_intervals = 50;
  float radium;
  cerr << "insert radium:\n";
  cin >> radium;
  //histogram parameters
  float top = 3.14 + radium;
  float btm = 3.14 - radium;
  float width = (top-btm)/n_intervals;
  float P;



  int tmp; //holds floor of selected bin
  float checksum = 0; //check if sum of frequencies is 1


  float * prob = new float[n_intervals]; //histogram array

  int d_cnt = 0;
  
  for(int i=0; i<n_trials; i++){
 
    thrw(N,data);
    tmp = int( ((data.meas)-btm) / width );
    ++prob[tmp];
  }

  //fill histogram
  for(int i=0; i<n_intervals; i++){
    P = prob[i]/n_trials;
    cerr << setw(10) << left
	 << btm+i*width << P
	 << endl;
    checksum += P;
  }
  cerr << N << " throws, " << n_trials << " entries." << endl;
  cerr << "Total sum of probs = " << checksum << endl;
  
  //mean and std
  data.sum /= n_trials;   //now is E(x)
  data.sumsq /= n_trials; //now is E(x*x)
  cerr << "N ; mean ; std  \n";
  cout << setw(10) << left << N << data.sum << " "
       << setw(10) << left<< sqrt(data.sumsq - data.sum*data.sum)
       << endl;
   





  return 0;
}

void thrw(int throws, entry& temp_data)
{
  float x;
  float y;
  float temp;

  int hit=0;

  //temp_data.sum = 0;
  //temp_data.sumsq = 0;

  for(int i=0; i<throws; i++){
    
    x = rnd_uni(0,1);
    y = rnd_uni(0,1);
    if( x*x+y*y < 1 ) hit++;
    
  }

  temp =  4*float(hit)/throws;

  temp_data.meas = temp;
  
  temp_data.sum   += temp;
  temp_data.sumsq += temp*temp;
  
  //sumsq /= n_trials;
  //sumsq /= sqrt(-(mean*mean - sumsq));

  return;
}
