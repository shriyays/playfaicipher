#target files:source files
#<tab>commands
a:main.o func.o endecrypt.o keysquare.o
	gcc main.o func.o endecrypt.o keysquare.o
main.o:main.c
	gcc -c main.c
func.o:func.c
	gcc -c func.c
endecrypt.o:endecrypt.c
	gcc -c endecrypt.c
keysquare.o:keysquare.c
	gcc -c keysquare.c
