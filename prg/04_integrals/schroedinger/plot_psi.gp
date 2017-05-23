load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/standard_style.gnu"

set terminal pngcairo

set output "psi.png"

# plot for [i=1:1000] 'data'.i.'.txt' using 1:2 title 'Flow '.i
#plot 'data_eig_even1.dat' 
plot for[i=0:5] 'data_eig_even'.i.'.dat' u 1:2 w p title 'even '.i

#plot 'prova.dat'

