rm -f *.dat

g++ henonheiles.cc -o hhexe
#     tfin  dt     x   px  y   py 
echo "100 0.01    0.1  0.1 0.1 0.3" | hhexe > hh.dat

#echo "100 0.01    0.001 0. 0.001 0.2" | hhexe >> hh1.dat
#echo "100 0.1   0.  0.1 0. 0.1" | hhexe >> hh2.dat
#echo "100 0.1   0.  0.1 0.1 0" | hhexe >> hh3.dat
#echo "100 0.1   0.  0.1 0.1 0" | hhexe >> hh4.dat
#echo "100 0.1   0.  0.1 0.1 0" | hhexe >> hh5.dat
#echo "100 0.1   0.  0.1 0.2 0" | hhexe >> hh6.dat
#echo "100 0.1   0.  0.1 0.3 0" | hhexe >> hh7.dat

gnuplot plot_hh.gp
