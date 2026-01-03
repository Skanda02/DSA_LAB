CC = gcc
CFLAGS = -Wall

OBJ = main.o stack.o palindrome.o

stack_palindrome: $(OBJ)
	$(CC) $(CFLAGS) -o stack_palindrome $(OBJ)

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

palindrome.o: palindrome.c stack.h
	$(CC) $(CFLAGS) -c palindrome.c

clean:
	rm -f *.o stack_palindrome
