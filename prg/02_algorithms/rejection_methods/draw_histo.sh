rm -f *.dat

#insert radium according to precision
r=.05
height=0.5
#echo "number_of_throws number_of_data radium
g++ pi_rej.cc -o pi_rej; echo "1000000 1000 $r" | pi_cfr > pi_histo_many.dat
g++ pi_rej.cc -o pi_rej; echo "100000 1000 $r" | pi_cfr > pi_histo_few.dat
gnuplot -e "radium=$r; height=$height" plot_pi_histo.gp








