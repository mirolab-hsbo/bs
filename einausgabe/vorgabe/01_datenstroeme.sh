#!/bin/bash

# Umleitung von stdout mittels >
echo "Hello World!" > datei.txt

# Umleitung von stdin mittels <
cat < datei.txt

# Umleitung von stderr mittels 2>
ls /root 2> fehler.txt
# cat fehler.txt: zeigt an, dass Berechtigungen fehlen