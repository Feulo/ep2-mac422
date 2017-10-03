#!/bin/sh

RUN=/usr/bin/time


for i in 10 30 50 
	do
	#exec 3<> ep2_out_n_${i}.txt	
	for j in `seq 1 30`
		do
		echo "Arquivo ${j} n=${i}\n"
		{ ${RUN} -f \"%e\" ./ep2 20 $i 30; } 2>> ./outputs/ep2_out_n_${i}.txt 		 

	done
#exec 3>&-
done
#echo fim
