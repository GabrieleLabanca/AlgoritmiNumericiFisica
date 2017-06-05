rm *.png

#                              y   v  theta(deg) m A
g++ cannon.cc -o cannon; echo "1.5 20 45         0.147 0.01 " | cannon > cannon.dat

gnuplot plot_cannon.gp
