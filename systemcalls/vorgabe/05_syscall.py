import ctypes
import os

# Zugriff auf die C-Standardbibliothek
libc = ctypes.CDLL("libc.so.6")

# Syscall-Nummern
SYS_OPENAT = #TODO
SYS_WRITE  = #TODO
SYS_CLOSE  = #TODO

# Konstanten für openat
AT_FDCWD = -100
O_CREAT = os.O_CREAT
O_WRONLY = os.O_WRONLY
O_CLOEXEC = os.O_CLOEXEC
MODE_777 = 0o777

filename = b"beispiel.txt"
fd = libc.syscall(SYS_OPENAT, ) # TODO 

if fd < 0:
    print("Fehler beim Öffnen der Datei")
else:
    message = b"Hallo, Betriebssystem!"
    libc.syscall(SYS_WRITE, ) #TODO

    libc.syscall(SYS_CLOSE, ) #TODO 
