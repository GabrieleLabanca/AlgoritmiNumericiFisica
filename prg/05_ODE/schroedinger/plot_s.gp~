set terminal pngcairo
load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/plot_data_style.gnu"

# .dat: t x px y py

set output "trajectory.png"
plot "hh.dat" u 2:4 w l   #x,y

set output "y_py.png"
plot "hh.dat" u 4:5 w p pointtype 0

#set output "multiple_ideas.png"
#plot for [i=1:7] 'hh'.i.'.dat' using 2:3 w l title "".i

