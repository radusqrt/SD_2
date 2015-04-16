#!/bin/bash

#Checkerul public

make clean
make build

mkdir output &> /dev/null

no_tests=27
for i in $(seq 1 $(($no_tests))); do
	./checker "input/test"$i".in" "output/test"$i".out" > /dev/null
done

grade=0
for i in $(seq 1 $(($no_tests))); do
	if [[ -z $(diff "output/test"$i".out" "ref/test"$i".ref") ]]; then 
		grade=$(($grade+1));
		echo ""
		echo "test"$i"............. OK"
	else
		echo ""
		echo "test"$i"............. X"
		diff "output/test"$i".out" "ref/test"$i".ref"
	fi
done

no_errors=0
for i in $(seq 1 $((no_tests))); do
	valgrind -q --log-file=a.out ./checker "input/test"$i".in" "output/test"$i".out" >/dev/null
	if [[ -z $(cat a.out) ]]; then
		no_errors=$((no_errors + 1));
	else
		cat a.out
		rm -rf a.out
		break
	fi
	rm -rf a.out
done

echo ""

if [ $no_errors -eq $no_tests ]; then
	echo "GRADE..............................$grade"
else 
	echo "Valgrind has errors, no grade for you my friend"
fi

echo ""

no_leaks=0
for i in $(seq 1 $((no_tests))); do
	valgrind -q --leak-check=full --log-file=a.out ./checker "input/test"$i".in" "output/test"$i".out" > /dev/null
	if [[ -z $(cat a.out) ]]; then
		no_leaks=$((no_leaks + 1));
	else
		echo "Your homework has leaks... :(. Try again ;)"
		rm -rf a.out;
		break;
	fi
	rm -rf a.out
done

if [ $grade == $no_tests ] && [ $no_leaks -eq $no_tests ]; then
	echo "Congratulations!"
    echo "You have passed all the public tests and your homework does not have any memory leaks"
	echo "If you also pass the private tests, you'll get a BONUS ;)"
fi
