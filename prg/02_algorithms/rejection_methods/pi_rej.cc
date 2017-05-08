#include <iostream>
#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/rnd_generators.hh"
#include <iomanip>

using namespace std;


float generate_pi(int,int=10);

int main()
{

  randomize48();
  int N;
  cin >> N;
  //int n_trials;
  //cin >> n_trials;
  int n_means;
  cin >> n_means;


  int n_intervals = 100;
  float radium;
  cin >> radium;
  float top = 3.14 + radium;
  float btm = 3.14 - radium;
  float width = (top-btm)/n_intervals;
  float P;

  int tmp;
  float checksum = 0;


  float * prob = new float[n_intervals];
  for(int i=0; i<n_means; i++){
    tmp = int( (generate_pi(N)-btm) / width );
    ++prob[tmp];    
   }
  
  for(int i=0; i<n_intervals; i++){
    P = prob[i]/n_means;
    cout << setw(10) << left
	 << btm+i*width << P
	 << endl;
    checksum += P;
  }

  cerr << N << " throws, " << n_means << " entries." << endl;
  cerr << "Total sum of probs = " << checksum << endl;

   





  return 0;
}

float generate_pi(int throws, int trials)
{
  float x;
  float y;

  int hit=0;

  
  float mean = 0;
  float temp = 0;
  //float sumsq = 0;
  //float std =0;;
  
  //for(int j=0; j<trials; j++){*/
    for(int i=0; i<throws; i++){
      
      x = rnd_uni(0,1);
      y = rnd_uni(0,1);
      if( x*x+y*y < 1 ) hit++;
      
    }
    
    temp =  4*float(hit)/throws;
    
    hit = 0;
        
    mean  += temp;
    //sumsq += temp*temp;
    //}

    //mean /= trials;
  //sumsq /= n_trials;
  //sumsq /= sqrt(-(mean*mean - sumsq));

  return mean;
}
