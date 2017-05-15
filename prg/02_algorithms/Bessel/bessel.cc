#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename T>
T fact(T);
template <typename T>
T besJ_direct(T,int,int);
template <typename T>
T besJ(T,int,int);


int main()
{
  cerr << "Series of Bessel function of 1st kind; select order:\n";
  int alpha;
  cin >> alpha;
  cerr << "Select percentual precision (estimated on J_0(0)):\n";
  int precision;
  cin >> precision;

  int order = 0;
  double t1, t2, tdiff;

  for(int i=0;i<10;i++){
    cerr <<setw(10)<<left << besJ_direct(1.1,1,i) << endl;
    
  }
  
  cerr << "SELECTING ORDER" << endl;
  do{
    cerr << "Current order: "<< order << endl;
    t1 = besJ_direct(0.1,0,order);
    t2 = besJ_direct(0.1,0,order+1);
    tdiff = (t2 - t1)/t2;
    cerr << setw(10) << left << t1 << t2 << " " << tdiff << endl;

    ++order;
  }
  while (tdiff > precision);
  cerr << "ORDER = " << order << endl;

  //waiting for a good method to choose order TODO
  order = 2;

  for(int i=0; i<1000; i++){
    cout << setw(10) << left << double(i)/5 << besJ(double(i)/5,alpha,order) << endl;
  }

  return 0;
}



template <typename T>
T fact(T x)
{
  if( x == 0 ) return 1;
  else return fact(x-1)*x;
}

template <typename T>
T besJ_direct(T x, int alpha, int ord) // over 10 factorial doesn't work
{
  double res = 0;
  double temp;
  for(int i=0; i<ord; i++){
        temp = pow( x/2., 2*i+alpha) / (fact(i)*fact(i+alpha+1));
    if(i%2 == 0) res += temp;
    else if(1%2 == 1) res -= temp;
  }
}

template <typename T>
T besJ(T x, int alpha, int ord)
{
  if(alpha == 0) return besJ_direct(x,0,ord);
  else if(alpha == 1) return besJ_direct(x,1,ord);
  else return
	 2.*alpha/x * besJ(x,alpha-1,ord) - besJ(x,alpha-2,ord);  
}
