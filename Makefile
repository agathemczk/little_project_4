all : test

test : cat.o pixel.o main.o
	gcc -o test cat.o pixel.o main.o

main.o : main.c
	gcc -c main.c main.o -Wall

cat.o : cat.c
	gcc -c cat.c cat.o -Wall

pixel.o : pixel.c
	gcc -c pixel.c pixel.o -Wall