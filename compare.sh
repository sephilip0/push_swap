#!/bin/bash

if [ -d outputs ]; then
	echo "Redoing outputs"
	rm -r ./outputs
        mkdir "outputs"
else
	echo "First time GLHF"
        mkdir "outputs"
fi

for i in {1..100}; do
        test=$(seq -300 300 | shuf -n $i)
        echo "For: $i"

        # Generate output for version 1
        oper1=$(./push_swap $test)
        printf "%s" "$oper1" >> ./outputs/$i.1

        # Generate output for version 2
        oper2=$(../../42IC_Ring02_Push_swap/push_swap/./push_swap $test)
        printf "%s" "$oper2" >> ./outputs/$i.2

        # Check for differences
        if [ -n "$(diff ./outputs/$i.1 ./outputs/$i.2)" ]; then
            echo -e "\e[31mAQUI\e[0m"
        fi
	#diff ./outputs/$i.1 ./outputs/$i.2
done
