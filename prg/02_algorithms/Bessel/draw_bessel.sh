g++ bessel.cc -o bessel
alpha=05
precision=0.01
export filedata="bes"$alpha".dat"
export fileplot="bes"$alpha".png"
echo $filedata
echo $fileplot

echo "$alpha $precision" | bessel > $filedata

echo "__________________________________"
echo "Call GNUPLOT"
gnuplot plot_bessel.gp #-e "outfile=$fileplot" plot_bessel.gp #; outfile=$fileplot" plot_bessel.gp
