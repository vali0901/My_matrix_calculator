OBJ = main free load multiplication print print_all remove save_elements scale sum transposition utils

build: $(OBJ)
	gcc ./bin/*.o -o main

main: main.c
	gcc -c main.c -o ./bin/main.o

free: ./src/free.c
	gcc -c ./src/free.c -o ./bin/free.o

load: ./src/load.c
	gcc -c ./src/load.c -o ./bin/load.o

multiplication: ./src/multiplication.c
	gcc -c ./src/multiplication.c -o ./bin/multiplication.o

print: ./src/print.c
	gcc -c ./src/print.c -o ./bin/print.o

print_all: ./src/print_all.c
	gcc -c ./src/print_all.c -o ./bin/print_all.o

remove: ./src/remove.c
	gcc -c ./src/remove.c -o ./bin/remove.o

save_elements: ./src/save_elements.c
	gcc -c ./src/save_elements.c -o ./bin/save_elements.o

scale: ./src/scale.c
	gcc -c ./src/scale.c -o ./bin/scale.o

sum: ./src/sum.c
	gcc -c ./src/sum.c -o ./bin/sum.o

transposition: ./src/transposition.c
	gcc -c ./src/transposition.c -o ./bin/transposition.o

utils: ./src/utils.c
	gcc -c ./src/utils.c -o ./bin/utils.o

clean: 
	rm ./bin/*