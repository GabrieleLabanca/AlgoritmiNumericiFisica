#include <iostream>
#include <cmath>

int fact(int number)
{
  if (number == 0) return 1;
  return number*fact(number - 1 );
}

double l_fact(int number)
{
  if (number == 0) return 0;
  return log(number) + l_fact(number-1);
}

int main()
{
  using namespace std;

  cout << "Insert integer number\n";
  int n;
  cin >> n;
  cout << "Il fattoriale di " << n << " e' "
       << fact(n) << endl
       << " mentre l_fact e' "
       << l_fact(n) << endl;
  return 0;
}
