# many_graphs.sh n_iteration prog_name "prog_args"
# N.B. prog_args inside " " and separated by blank spaces

#while getopts :sm: option
#do
#    case "$option" in
#    s)
#         opt=0
#         ;;
#    m)
#         opt=1
#         ;;
#    esac
#done


rm -f *.dat
args=("$@")

for (( i=1; i <= $1; i++ ))
do
    filename="$2_$i.dat"
    #if[$opt=0]; then
	a=${args[3+$i-2]}
    #elif['$opt'='1']; then
#	a=${args[3]}
 #   fi
    echo $a
    echo $a | $2 > $filename
    sleep 1
done

gnuplot -e "filename='$2_';N=$1" /usr/users/edu2016/gabriele.labanca/AlgoritmiNumericiFisica/prg/00/gpl_many.gp
# gpl_many.gp
