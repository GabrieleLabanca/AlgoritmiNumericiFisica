#Insert initial y, v, theta (deg):
#Insert m, M:
g++ cannon.cc -o cannon; echo "10 40 90 0.1 0.4" | cannon > cannon.dat

gnuplot plot_cannon.gp
