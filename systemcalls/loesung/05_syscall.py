import ctypes
import os

# Zugriff auf die C-Standardbibliothek
libc = ctypes.CDLL("libc.so.6")

# Syscall-Nummern
SYS_OPENAT = 257
SYS_WRITE  = 1
SYS_CLOSE  = 3

# Konstanten für openat
AT_FDCWD = -100
O_CREAT = os.O_CREAT
O_WRONLY = os.O_WRONLY
O_CLOEXEC = os.O_CLOEXEC
MODE_777 = 0o777

filename = b"beispiel.txt"
fd = libc.syscall(SYS_OPENAT, AT_FDCWD, filename, O_CREAT | O_WRONLY | O_CLOEXEC, MODE_777)

if fd < 0:
    print("Fehler beim Öffnen der Datei")
else:
    message = b"Hallo, Betriebssystem!"
    libc.syscall(SYS_WRITE, fd, message, len(message))

    libc.syscall(SYS_CLOSE, fd)
