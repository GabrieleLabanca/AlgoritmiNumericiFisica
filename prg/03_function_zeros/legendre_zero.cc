#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
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
  //cerr << "Insert begin and end of interval:\n";
  //cin >> x1 >> x2;

  N_ORDER = 8;

  double dx = 0.00001;
  int N_division = 2/dx; //mustn't go in -1, +1!!
  //cerr << "N_DIVISION " << N_division << endl;

  double x_acc, y_acc, x_zero;
  cerr << "Insert desired accuracy in x and in f(x)\n";
  cin >> x_acc >> y_acc;


  
  for(int j=0; j<N_division; j++){

    //cerr << "CICLO " << j << endl;


    x1 = -1 + (j) * dx;  //mustn't go in -1, +1!!
    x2 = -1 + (j+1) * dx;
    //cerr << x1 << " " << x2 << endl;
    
    
    
    int tot_fail;
    //////////////////////////////////////////////////////////
    // Not convenient to iterate poorman/knuth alternance
    int pm_fail;
    int kn_fail;
    poorman_bracketing(legendre_fixed, x1, x2, tot_fail);
    pm_fail = tot_fail;
    //while(pm_fail == 1){
    if(pm_fail == 1) {
      //cerr << "pm_fail ==1" << endl;
      continue;
    }
    //////////////////////////////////////////////////////////
    
    // exit if no zero found
    if(tot_fail == 1){
      cerr << "!no zero found!\n";
      //return 1;
    }
    
    
    //cerr << "Bracketed interval:\n";
    //cerr << setw(20) << left << x1 << x2 << endl;
    
    
    
   
    
    x_zero = zero_bisection(legendre_fixed,x1,x2,0.001,0.001,tot_fail);
    //x_zero = zero_regulafalsi(fexp_m,x1,x2,0.001,0.001,tot_fail);
    
    //cerr << "rough zero = " << setprecision(12) <<  x_zero << endl;
    
    x_zero = zero_newton(legendre_fixed,d_legendre_fixed,x1,x2,x_zero,x_acc,y_acc,tot_fail);
    cerr << "Zero of the function is in \n#### ";
    cerr << fixed << setprecision(9) <<  x_zero << endl;
    cerr << "Value of the function in this zero is"
      //<< setprecision(9)
	 << legendre_fixed(x_zero) << endl;

  }

  // PLOT to check algorithm for Legendre polinomials
  for(int i=-1000; i<1000; i++){
    cout << i/1000.;
    
    for(int oi=0; oi<8; oi++){
      N_ORDER = oi+1;      
      
      
      cout << " "  << legendre_fixed(i/1000.);
      
    }
    cout << endl;
    
  }
  




  return 0;
}
