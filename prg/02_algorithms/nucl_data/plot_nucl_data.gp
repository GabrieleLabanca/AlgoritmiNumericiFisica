load "../../gnuplot/standard_style.gnu"
set terminal pngcairo

set output "diff_n0.png"

plot "nd_5000.dat" u 1:2 w l, \
"nd_1000.dat" u 1:2 w l, \
"nd_500.dat" u 1:2 w l, \
"nd_100.dat" u 1:2 w l, \
"nd_80.dat" u 1:2 w l, \
"nd_30.dat" u 1:2 w l, \
"nd_10.dat" u 1:2 w l






set output "low_n0.png"
plot "nd_30.dat" u 1:2 w l, \
"nd_30a.dat" u 1:2 w l, \
"nd_30b.dat" u 1:2 w l, \
"nd_30c.dat" u 1:2 w l, \
"nd_30d.dat" u 1:2 w l, \
"nd_30e.dat" u 1:2 w l


set output "high_n0.png"
plot "nd_5000.dat" u 1:2 w l, \
"nd_5000a.dat" u 1:2 w l, \
"nd_5000b.dat" u 1:2 w l, \
"nd_5000c.dat" u 1:2 w l, \
"nd_5000d.dat" u 1:2 w l, \
"nd_5000e.dat" u 1:2 w l

