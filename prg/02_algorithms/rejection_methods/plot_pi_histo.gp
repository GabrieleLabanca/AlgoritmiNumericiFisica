load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/standard_style.gnu"

set terminal pngcairo
set output "pi_histo.png"

set xrange [3.14-radium:3.14+radium]
set yrange [0:0.05]
plot "pi_histo.dat" u 1:2 w histeps
