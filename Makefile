CC      = gcc
CFLAGS  = -Wall -Wextra -g
LIBS    = -lm

TARGET  = main
SRCS    = main.c utils.c lattice.c model.c metropolis.c
OBJS    = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
