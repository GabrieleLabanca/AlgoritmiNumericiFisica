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
