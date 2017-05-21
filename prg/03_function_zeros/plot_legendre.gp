#load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/standard_style.gnu"

set terminal pngcairo

set output "legendre.png"

plot "pol_leg.dat" u 1:2 w l title "N=1", \
       "pol_leg.dat" u 1:3 w l title "N=2", \
       "pol_leg.dat" u 1:4 w l title "N=3", \
       "pol_leg.dat" u 1:5 w l title "N=4", \
       "pol_leg.dat" u 1:6 w l title "N=5", \
       "pol_leg.dat" u 1:7 w l title "N=6", \
       "pol_leg.dat" u 1:8 w l title "N=7", \
       "pol_leg.dat" u 1:9 w l title "N=8" 













