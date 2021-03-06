set terminal pngcairo
load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/plot_data_style.gnu"

#datafile 

set output "trajectory.png"
set xlabel "x(m)"
set ylabel "y(m)"
plot "cannon.dat" u 2:3 w l title "trajectory with friction",\
     "" 	  u 6:7 w l title "trajectory without friction"

set output "velocities_friction.png"
set xlabel "time (s)"
set ylabel "velocity (m/s)"
plot "cannon.dat" u 1:4 w l title "vx",\
     ""		  u 1:5 w l title "vy"

#set output "velocities_frictionless.png"
#set xlabel "time (s)"
#set ylabel "velocity (m/s)"
#plot "cannon.dat" u 1:8 w l title "vx",\
#     ""		  u 1:9 w l title "vy"

#set output "pos_vel.png"
#set ylabel "m or m/s"
#set xlabel "time (s)"
#plot "cannon.dat" u 1:2 w l title "x",\
#     ""		  u 1:3 w l title "y",\
#     ""		  u 1:4 w l title "vx",\
#     ""		  u 1:5 w l title "vy"
