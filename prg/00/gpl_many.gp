load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/standard_style.gnu"

set terminal pngcairo
set output "plot_many.png"

plot for [i=1:N] filename.i.".dat" u 1:2 w l title filename.i