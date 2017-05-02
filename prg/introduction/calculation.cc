#include <iostream>
#include <iomanip>



int main()
{
  using namespace std;
  cout << "This program performs calculations\n Insert two numbers:\n";
  float M, N;
  cin >> M >> N;
  cout
    << setw(10) << left << "sum" << M+N << endl
    << setw(10) << left << "dif" << M-N << endl
    << setw(10) << left << "pro" << M*N << endl;
  if( N != 0 ) cout << setw(10) << left << "div" << M/N << endl;
  else cout << "Division by zero!\n";

  cout << "Now let us explore some issues with integers\n Insert two integers\n";
  int A, B;
  cin >> A >> B;
  cout
    << setw(10) << left << "sum" << A+B << endl
    << setw(10) << left << "dif" << A-B << endl
    << setw(10) << left << "pro" << A*B << endl;
  if( B != 0 ) cout
    << setw(20) << left << "div (NO CAST)" << A/B << endl
    << setw(20) << left << "div (CAST)" << float(A)/B << endl;
  else cout << "Division by zero!\n";
    

  
  return 0;
}
