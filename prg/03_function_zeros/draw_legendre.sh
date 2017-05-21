g++ legendre_zero.cc -o legendre; 

echo "0.0000000 0.000001" | ./legendre > pol_leg.dat

gnuplot plot_legendre.gp


