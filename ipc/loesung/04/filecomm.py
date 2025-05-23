#!/usr/bin/env python3

if __name__ == '__main__':

    FILENAME = "shared_file.txt"
    choice = ""
    while (choice != "q"):
        print("What do you want to do?")
        print("w) Write to file")
        print("r) Read from file")
        print("q) Quit")
        choice = input("Selection: ")
        if choice == "w":
            msg = input("Please enter a message:\n")
            with open(FILENAME, "w") as outfile:
                outfile.write(msg)
        if choice == "r":
            with open(FILENAME, "r") as infile:
                content = infile.read()
            print(content)

