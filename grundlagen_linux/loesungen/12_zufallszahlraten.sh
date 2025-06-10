#!/bin/bash

zahl=$((1 + $RANDOM % 10))
eingabe=""

while [[ $zahl != $eingabe ]]; do
	echo "Zahl eingeben:"
	read eingabe
	if [[ $zahl == $eingabe ]]; then
		echo "Richtig geraten!"
	else
		echo "Falsche Zahl, bitte versuchen Sie es erneut."
	fi
done
