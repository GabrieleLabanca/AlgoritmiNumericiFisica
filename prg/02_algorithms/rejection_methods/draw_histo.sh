#insert radium according to precision

r=.005
# echo "number_of_throws number_of_data radium
g++ pi_rej.cc -o pi_rej; echo "1000000 1000 $r" | pi_rej > pi_histo.dat
gnuplot -e "radium=$r" plot_pi_histo.gp
