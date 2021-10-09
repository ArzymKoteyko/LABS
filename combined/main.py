from ctypes import *

libc = CDLL("./primes.so")
print(libc)
libc.main()
