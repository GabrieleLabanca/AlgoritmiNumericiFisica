void bracketing(double * f(double), double &x1, double &x2, int ifail)
{
  double h = (x2 - x1)/1000;
  double f1, f2;
  do{
    f1 = *f(x1);
    f2 = *f(x2);
    ++x1;
  }
  while( f1*f2 > 0);
  return;
}

double operation(double * f(double),double x)
{
  return *f(x);
}
