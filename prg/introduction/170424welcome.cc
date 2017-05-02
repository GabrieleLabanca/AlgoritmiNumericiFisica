#include <iostream>

using namespace std;

int main()
{
  cout << "Welcome\n" 
       << "second line\n" 
       << "third line\n";
  cout.width(10);
  cout << 100 << endl;
  cout.fill('_');
  cout.width(10);
  cout << left
       << "a" << 100 << endl
       << "b" << 110 << endl;

  return 0;
       
}
