rm -f *.dat

g++ hh_projection.cc -o hhproj
#     tfin  dt    energy       x   y   py 
# energie interessanti: 1/12, 1/6
echo "10000 0.01  0.11 0.3 0.1 0.1" | hhproj > hpr1.dat
echo "10000 0.01  0.11 0.1 0   0.1" | hhproj > hpr2.dat

echo "10000 0.01  0.15 0.1  0.1 0.1" | hhproj > hpr3.dat
# hyperbolic points
echo "10000 0.001  0.11   0.5 0.5 0.6" | hhproj > hpr4.dat 








#echo "100 0.01    0.001 0. 0.001 0.2" | hhexe >> hh1.dat
#echo "100 0.1   0.  0.1 0. 0.1" | hhexe >> hh2.dat
#echo "100 0.1   0.  0.1 0.1 0" | hhexe >> hh3.dat
#echo "100 0.1   0.  0.1 0.1 0" | hhexe >> hh4.dat
#echo "100 0.1   0.  0.1 0.1 0" | hhexe >> hh5.dat
#echo "100 0.1   0.  0.1 0.2 0" | hhexe >> hh6.dat
#echo "100 0.1   0.  0.1 0.3 0" | hhexe >> hh7.dat

gnuplot plot_proj.gp
