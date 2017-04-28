/* strange_calculator.cc
 * this program acts like a normal calculator, but summing from left to right
 * es. 3+4*5 = 35
 */
#include<iostream>

using namespace std;

int main()
{
  cout << "Insert expression\n";

  float n1, n2;
  char op;

  cin >> n1 >> op;
  
  while( op != '='){
    cin >> n2;
    switch(op)
      {
      case '+':
	n1 += n2;
	break;
      case '-':
	n1 -= n2;
	break;
      case '*':
	n1 *= n2;
	break;
      case '/':
	if (n2 != 0) n1 /= n2;
	else cout << "Division by zero!\n";
	break;
      default:
	cout << "Input error!\n";
	return 1;
      }
    cin >> op;
  }

  cout << "Result:\n"
       << n1
       << endl;
  
    

  

  


  return 0;
}
