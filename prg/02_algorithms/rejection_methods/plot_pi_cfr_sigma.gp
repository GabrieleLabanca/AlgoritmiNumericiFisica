load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/standard_style.gnu"

set terminal pngcairo
set output "pi_cfr_sigma.png"

#set xrange [3.14159265-radium:3.14159265+radium]
#set yrange [0:height]
plot "pi_cfr.dat" u 1:3 w p, \
     1.7/sqrt(x)
     
   