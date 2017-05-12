N_throws=$1
g++ how_rnd.cc  -o how_rnd; echo $N_throws | how_rnd 

gnuplot plot_raw.gp
gnuplot plot_histo.gp
