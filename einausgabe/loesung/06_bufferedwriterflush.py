#!/usr/bin/env python3

with open("output.txt", "w") as f:
    f.write("Gepufferte Zeile\n")
    f.flush()
    input("Enter drücken zum Beenden...")
