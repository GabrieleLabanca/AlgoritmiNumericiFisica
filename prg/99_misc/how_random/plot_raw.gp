load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/standard_style.gnu"

set terminal pngcairo
set output "rnd_distr.png"

plot "raw_data.dat" u 1:2 w p