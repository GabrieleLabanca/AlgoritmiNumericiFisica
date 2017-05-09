rm -f *.dat

# law of sigma
echo  1000 
echo "1000 1000 0.8" | pi_cfr >> pi_cfr.dat
echo  10000
echo "10000 1000 0.7" | pi_cfr >> pi_cfr.dat
echo  15000 
echo "15000 1000 0.7" | pi_cfr >> pi_cfr.dat
echo  30000 
echo "30000 1000 0.7" | pi_cfr >> pi_cfr.dat
echo  50000 
echo "50000 1000 0.5" | pi_cfr >> pi_cfr.dat
echo  70000
echo "70000 1000 0.5" | pi_cfr >> pi_cfr.dat
echo  80000
echo "80000 1000 0.5" | pi_cfr >> pi_cfr.dat
echo  90000
echo "90000 1000 0.5" | pi_cfr >> pi_cfr.dat
#echo  500000 >> pi_cfr.dat
#echo "5000000 1000 0.01" | pi_cfr >> pi_cfr.dat

gnuplot plot_pi_cfr_sigma.gp
