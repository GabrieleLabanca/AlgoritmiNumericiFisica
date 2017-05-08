echo 10   | nuclear > nucl_data/nd_10.dat

echo 30   | nuclear > nucl_data/nd_30.dat
sleep 1
echo 30   | nuclear > nucl_data/nd_30a.dat
sleep 1
echo 30   | nuclear > nucl_data/nd_30b.dat
sleep 1
echo 30   | nuclear > nucl_data/nd_30c.dat
sleep 1
echo 30   | nuclear > nucl_data/nd_30d.dat
sleep 1
echo 30   | nuclear > nucl_data/nd_30e.dat

echo 80   | nuclear > nucl_data/nd_80.dat
echo 100   | nuclear > nucl_data/nd_100.dat
echo 500   | nuclear > nucl_data/nd_500.dat
echo 1000   | nuclear > nucl_data/nd_1000.dat

echo 5000   | nuclear > nucl_data/nd_5000.dat
sleep 1
echo 5000   | nuclear > nucl_data/nd_5000a.dat
sleep 1
echo 5000   | nuclear > nucl_data/nd_5000b.dat
sleep 1
echo 5000   | nuclear > nucl_data/nd_5000c.dat
sleep 1
echo 5000   | nuclear > nucl_data/nd_5000d.dat
sleep 1
echo 5000   | nuclear > nucl_data/nd_5000e.dat

cd nucl_data
gnuplot "plot_nucl_data.gp"
cd ..



