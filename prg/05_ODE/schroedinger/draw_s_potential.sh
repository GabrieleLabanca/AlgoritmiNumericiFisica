g++ s_potential.cc -o s_pot


echo "0.001 2.00698" | s_pot > s_pot1.dat
#echo "0.1 2.0" | s_pot > s_pot2.dat
#echo "0.1 2.04745" | s_pot > s_pot3.dat
#echo "0.1 2.1" | s_pot > s_pot4.dat
#echo "0.1 2.2" | s_pot > s_pot5.dat

gnuplot plot_s.gp


# 2.00698 6.82769 12.8493 
