set terminal x11 size 500,500 enhanced font 'Verdana,10' persist
# Line width of the axes
set border linewidth .1
# Line styles
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 2
# Axes label
set xlabel 'x'
set ylabel 'y'

# Add light grid to plot
#
# AUTHOR: Hagen Wierstorf
set style line 102 lc rgb '#d6d7d9' lt 0 lw 1
set grid back ls 102
