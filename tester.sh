#!/bin/bash

echo "3 NUMBERS:"
for i in {1..5}; do
	test=$(seq -30 30 | shuf -n 3)
	check=$(./push_swap $test | ./checker_linux $test)
	oper=$(./push_swap $test | wc -l)
	if [[ $oper -le 11 && "$check" = "OK" ]]; then
		echo -e "\e[32mOK\e[0m"
	else
		echo -e "\e[31mKO\e[0m"
	fi
done

echo "4 NUMBERS:"
for i in {1..5}; do
	test=$(seq -30 30 | shuf -n 4)
	check=$(./push_swap $test | ./checker_linux $test)
	oper=$(./push_swap $test | wc -l)
	if [[ $oper -le 7 && "$check" = "OK" ]]; then
		echo -e "\e[32mOK\e[0m"
	else
		echo -e "\e[31mKO\e[0m"
	fi
done

#WOULD BE COOL TO TEST WITH MAX_INT AND MIN_INT
echo "5 NUMBERS:"
for i in {1..5}; do
	test=$(seq -30 30 | shuf -n 5)
	check=$(./push_swap $test | ./checker_linux $test)
	oper=$(./push_swap $test | wc -l)
	if [[ $oper -le 11 && "$check" = "OK" ]]; then
		echo -e "\e[32mOK\e[0m"
	else
		echo -e "\e[31mKO\e[0m"
	fi
done

echo "100 NUMBERS:"
for i in {1..5}; do
	test=$(seq -300 300 | shuf -n 100)
	check=$(./push_swap $test | ./checker_linux $test)
	oper=$(./push_swap $test | wc -l)
	if [[ $oper -le 1084 && "$check" = "OK" ]]; then
		echo -e "\e[32mOK\e[0m"
	elif [ $check = "OK" ]; then
		echo -e "\e[33mSLOW\e[0m"
	else
		echo -e "\e[31mKO\e[0m"
	fi
done

echo "500 NUMBERS:"
for i in {1..5}; do
	test=$(seq -500 500 | shuf -n 500)
	check=$(./push_swap $test | ./checker_linux $test)
	oper=$(./push_swap $test | wc -l)
	if [[ $oper -le 6785 && "$check" = "OK" ]]; then
		echo -e "\e[32mOK\e[0m"
	elif [ $check = "OK" ]; then
		echo -e "\e[33mSLOW\e[0m"
	else
		echo -e "\e[31mKO\e[0m"
	fi
done
