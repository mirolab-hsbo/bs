import os

# Flags: O_CREAT (create if not exist), O_WRONLY (write only)
fd = os.open("beispiel.txt", os.O_CREAT | os.O_WRONLY)

# os.write erwartet Bytes!
os.write(fd, b"Hallo, Betriebssystem!")
os.close(fd)

