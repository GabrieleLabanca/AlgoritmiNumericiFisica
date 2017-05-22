#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <vector>
//#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/lib_zero.h"
//#include "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/include/lib_special.h"
#include "../../include/lib_zero.h"
#include "../../include/lib_special.h"




using namespace std;

int N_ORDER;

double legendre_fixed(double x)
{
  return legendre(N_ORDER,x);
}

double d_legendre_fixed(double x)
{
  return d_legendre(N_ORDER,x);
}

double trial(double x)
{
  return x;
}


int main()
{
  double x1;
  double x2;
 
  double dx = 0.2;
  int N_division = 2/dx; 
  

  double x_acc, y_acc, x_zero;
  cerr << "Insert desired accuracy in x and in f(x)\n";
  cin >> x_acc >> y_acc;

  int N_MAX;
  cerr << "Insert maximum order of polinomials\n";
  cin >> N_MAX;


  // vector of zeros:
  // - first index: order of polinomial
  // - second index: zeros
  vector< vector<double> > v_zeros;
  v_zeros.resize(N_MAX+1);
    
  for(int j=0; j<N_division; j++){

    x1 = -1 + (j) * dx; 
    x2 = -1 + (j+1) * dx;

    for(int io=1; io<N_MAX+1; io++){
      N_ORDER = io;
      
      int tot_fail;
      // cerr << x1 << " " << x2 << endl;
      poorman_bracketing(legendre_fixed, x1, x2, tot_fail);

      if(tot_fail == 1) continue;
            
      x_zero = zero_bisection(legendre_fixed,x1,x2,0.00,0.001,tot_fail);
            
      //x_zero =  zero_newton(legendre_fixed,d_legendre_fixed,x1,x2,x_zero,x_acc,y_acc,tot_fail);

       
      //cerr << "Zero of the function is in \n#### ";
      //cerr << fixed << setprecision(9) <<  x_zero << endl;
    
      v_zeros.at(N_ORDER).push_back(x_zero);
    }
  }




  
  for(int i=1;i<N_MAX+1;i++){
    cerr << "Zeros of order " << i << ":\n";
    for(vector<double>::iterator it=v_zeros.at(i).begin(); it!=v_zeros.at(i).end(); it++){
      double t = *it;
      cerr << "     ";
      cerr << setw(10) << left <<  *it << endl;
      
    }
    cerr << endl;
  }
    

  




  return 0;
}
