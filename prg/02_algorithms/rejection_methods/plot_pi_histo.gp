load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/standard_style.gnu"

set terminal pngcairo
set output "pi_histo.png"

set xrange [3.14159265-radium:3.14159265+radium]
set yrange [0:height]
plot "pi_histo_many.dat" u 1:2 w histeps, \
     "pi_histo_few.dat" u 1:2 w histeps
