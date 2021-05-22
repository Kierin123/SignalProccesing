CC = gcc
CFLAGS = -g -Wall -Wpedantic
SOURCES = main.c filter.c
OBJECTS = $(SOURCES:.c=.o)
NAME = output

#Rule which build all project
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

$(OBJECTS):
	$(CC) -c $(CFLAGS) $(SOURCES)

clean: 
	rm -f $(OBJECTS)
	rm -f $(NAME)