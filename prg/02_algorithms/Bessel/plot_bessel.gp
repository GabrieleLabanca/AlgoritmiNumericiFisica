load "/usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/standard_style.gnu"

set terminal pngcairo

infile=system("echo $filedata")
outfile=system("echo $fileplot") 

set output outfile
plot infile u 1:2 w p

