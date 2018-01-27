# GNU makefile (clang)

CC = gcc
CFLAGS = -Werror -Wall
#CFLAGS = -Werror -Wall -Wextra

TARGET = main.out
TESTER = test.out

OBJS=

all: $(TARGET)

$(TARGET): $(OBJS) main.o
	$(CC) -o $@ $^

$(TESTER): $(OBJS) test.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

###

clean:
	$(RM) *.o
	$(RM) $(TARGET)
	$(RM) $(TESTER)

run: $(TARGET)
	./$(TARGET)

test: $(TESTER)
	./$(TESTER)
