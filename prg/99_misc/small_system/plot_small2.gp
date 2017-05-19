load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/standard_style.gnu"

set terminal pngcairo
set output "small_plot2.png"

plot "small2.dat" u 1:2 w p title "mice" ls 1,\
     "small2.dat" u 1:3 w p title "cats" ls 2