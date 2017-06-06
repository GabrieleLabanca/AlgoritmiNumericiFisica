set terminal pngcairo
load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/plot_data_style.gnu"


set output "s_solution.png"
set yrange [-.05:.05]

plot "s_pot.dat" u 1:2 w l 
