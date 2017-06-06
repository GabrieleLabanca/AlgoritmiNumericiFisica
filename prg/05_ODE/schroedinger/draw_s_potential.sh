rm *.png 
g++ s_potential.cc -o s_pot
echo "0.1 2.046" | s_pot > s_pot.dat

gnuplot plot_s.gp
