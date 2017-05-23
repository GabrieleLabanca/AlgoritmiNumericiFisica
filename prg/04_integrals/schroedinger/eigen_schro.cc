#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>

#include "lib_zero.h"
#include "phys_constants.h"
#include "quadrature.h"

using namespace std;


double eig_even(double E, double V0, double a)
{
  double alpha = sqrt( (E+V0)/Physics::htc2om );
  double beta  = sqrt(     -E/Physics::htc2om );
  // cerr << " " << alpha << " " << beta << " ";
  return alpha * sin( alpha * a) - beta * cos( alpha * a);
}

double eig_odd(double E, double V0, double a)
{
  double alpha = sqrt( (E+V0)/Physics::htc2om );
  double beta  = sqrt(     -E/Physics::htc2om );
  return alpha * cos( alpha * a) + beta * sin( alpha * a);
}

double eig_even_d(double E, double V0, double a)
{
  double alpha = sqrt( (E+V0)/Physics::htc2om );
  double beta  = sqrt(     -E/Physics::htc2om );
  double d_alpha =  1./(2*sqrt( (E+V0) * Physics::htc2om ) );
  double d_beta  = -1./(2*sqrt( (-E)   * Physics::htc2om ) );
  return d_alpha*sin(alpha*a) + a*alpha*cos(alpha*a)*d_alpha
    - a*d_beta*cos(alpha*a) + beta*sin(alpha*a)*d_alpha;
}

double eig_odd_d(double E, double V0, double a)
{
  double alpha = sqrt( (E+V0)/Physics::htc2om );
  double beta  = sqrt(     -E/Physics::htc2om );
  double d_alpha =  1./(2*sqrt( (E+V0) * Physics::htc2om ) );
  double d_beta  = -1./(2*sqrt( (-E)   * Physics::htc2om ) );
  return d_alpha*cos(alpha*a) - a*alpha*sin(alpha*a)*d_alpha
    + d_beta*sin(alpha*a) + a*beta*cos(alpha*a)*d_alpha;
}


double alpha(double E, double V0)
{
  return sqrt( (E+V0)/Physics::htc2om );
}

double beta(double E)
{
  return sqrt(     -E/Physics::htc2om );
}


double E, V0, a;


double eig_even_fix(double E)
{
  return eig_even(E,V0,a);
}

double eig_odd_fix(double E)
{
  return eig_odd(E,V0,a);
}

double eig_even_d_fix(double E)
{
  return eig_even_d(E,V0,a);
}

double eig_odd_d_fix(double E)
{
  return eig_odd_d(E,V0,a);
}



double psi_e(double x)
{
  if( (x<-a) or (x>a) ) return cos( alpha(E,V0)*a ) * exp( beta(E)*(a-abs(x)) ) ;
  else if( (x==a) or (x==-a)) return cos( alpha(E,V0)*a) * exp(beta(E)*(a-abs(x))) ;
  else if ( (x>-a) and (x<a) ) return cos( alpha(E,V0) *x );
}

double mod_psi_e(double x)
{
  return psi_e(x)*psi_e(x);
}

				 
  



	
double f_dot_g(double (*f)(double),double (*g)(double),double x)
{
  return f(x)*g(x);
}

double f_squared(double(*f)(double),double x)
{
  return f_dot_g(f, f, x);
}
		

double trial(double x)
{
  return x*x - x*x*x*x;
}

int main()
{

  /*
  // plot to check function
  double x;
  V0 = 65;
  a = 8;
  int N = 1000;
  int dx = V0/ N ;
  for(int i=0;i<N; i++){
    x = -V0 + V0*i/double(N);
    cout << x << " " << eig_even(x,V0,a) << endl;
  }
  */



  cerr << "Insert a, V0\n";
  cin >> a >> V0;
  double dx = 0.001;
  int n_division = V0/dx;

  int tot_fail;
  //double ev_zero, odd_zero;
  double x_zero;
  double x_acc, y_acc;
  cerr << "Insert desired accuracy in x and in f(x)\n";
  cin >> x_acc >> y_acc;

  double x1e, x2e, x1o, x2o;

  double NORM;
  string fileprefix = "data_eig_";
  stringstream sstring;
  string filename;
  string extension = ".dat";
  int E_counter = 0;
  char E_char;
  fstream outfile;
  
  for(int j=0; j<n_division; j++){
    //EVEN
    x1e = -V0 + (j)   * dx;  
    x2e = -V0 + (j+1) * dx;

   

 
    poorman_bracketing(eig_even_fix, x1e, x2e, tot_fail);
    if(tot_fail == 0) {
      
      x_zero = zero_bisection(eig_even_fix,x1e,x2e,0.001,0.001,tot_fail);
      
      x_zero = zero_newton(eig_even_fix,eig_even_d_fix,x1e,x2e,x_zero,x_acc,y_acc,tot_fail);
      
      if(tot_fail == 0){
	cerr << "An EVEN eigenvalue is in \n#### ";
	cerr << fixed << setprecision(9) <<  x_zero << endl;

	E = x_zero;
	NORM = quad(mod_psi_e,-10,10,0.01,'g');

	
	E_counter++;
	E_char = char (E_counter);
	sstring.str(std::string());
	sstring << fileprefix << "even" << E_counter << extension;
	cerr << sstring.str() << endl;
	filename = sstring.str();
	outfile.open(filename.c_str(),fstream::out);
	for(int i=-100; i<100; i++){
	  outfile << double(i)/10. << " " << psi_e(double(i)/10.)/NORM
		  << endl;
	  //cout << double(i)/10. << " " << psi_e(double(i)/10.)
	  //  << endl;
	}
	outfile.close();


	  
      }


      
      
      
    }
    ////////////////////////////////
    
    
    //ODD

    x1o = -V0 + (j)   * dx;  
    x2o = -V0 + (j+1) * dx;
    
    poorman_bracketing(eig_odd_fix, x1o, x2o, tot_fail);
    if(tot_fail == 0) {
      
      x_zero = zero_bisection(eig_odd_fix,x1o,x2o,0.001,0.001,tot_fail);
     
      x_zero = zero_newton(eig_odd_fix,eig_odd_d_fix,x1o,x2o,x_zero,x_acc,y_acc,tot_fail);
      
      if(tot_fail == 0){
	cerr << "An ODD eigenvalue is in \n#### ";
	cerr <<  fixed << setprecision(9) <<  x_zero << endl;
      }
    }
 
  }



  









  return 0;
}

