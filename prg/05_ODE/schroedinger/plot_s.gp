set terminal pngcairo
load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/plot_data_style.gnu"

set output 'dispE.png'

set yrange [-5:5]
plot 'dispE.dat' u 1:2 w l


#set output "s_solution.png"
#set yrange [-.05:.05]

#plot for [i=1:1] 's_pot'.i.'.dat' using 1:2 title 'psi_u'.i,\
#     for [i=1:1] 's_pot'.i.'.dat' using 1:3 title 'psi_d'.i

