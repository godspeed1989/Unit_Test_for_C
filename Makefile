NAME=tester

all: $(NAME)

Main.o: Main.c
	gcc -c $<
Tester.o: Tester.c CuTest.h
	gcc -c $<
CuTest.o: CuTest.c CuTest.h
	gcc -c $<

$(NAME): Main.o Tester.o CuTest.o
	gcc $+ -o $@

run:
	./$(NAME)

clean:
	rm -rf *.o