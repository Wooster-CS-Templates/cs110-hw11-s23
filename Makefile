CFLAGS=-std=gnu99 -Wall

best_pizza_value: main.o pizza.o
	gcc $(CFLAGS) main.o pizza.o -o best_pizza_value -lm

main.o: main.c pizza.h
	gcc $(CFLAGS) -c main.c 

pizza.o: pizza.c pizza.h
	gcc $(CFLAGS) -c pizza.c 

test: test.o pizza.o
	gcc $(CFLAGS) test.o pizza.o -o test -lm

test.o: tests/test.c pizza.h
	gcc $(CFLAGS) -c tests/test.c 

gh-test-pizza: clean test
	./test

clean:
	rm -f test best_pizza_value *.o
