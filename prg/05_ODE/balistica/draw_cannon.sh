rm -f *.png

#                            y v theta (deg) m A
g++ cannon.cc -o cannon; echo "1.5 10 0.147 0.0042" | cannon > cannon.dat

gnuplot plot_cannon.gp
