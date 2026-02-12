CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ivendor/raylib/include
LDFLAGS = -Lvendor/raylib/lib -lraylib -lGL -lX11 -lXcursor -lXinerama -lXi -lXrandr -lm -lpthread -ldl -lrt -Wl,-rpath,$(PWD)/vendor/raylib/lib

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/menu.c $(SRC_DIR)/game.c
OBJS = $(SRCS:.c=.o)

all: game

game: $(OBJS)
	$(CC) $(CFLAGS) -o game $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o game