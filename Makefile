SHELL = /bin/sh

CC = gcc
IDIR = /usr/local/include/allegro5/
HDIR = ./include/
SDIR = ./src/
EXEC = snake
#OBJECTS =
TESTBENCH = game
TBDIR = ./lab/

all:
	$(CC) -g -o $(EXEC) $(SDIR)main.c $(SDIR)game.c $(SDIR)snake.c $(SDIR)cell.c \
	$(SDIR)boundary.c $(SDIR)score.c $(SDIR)apple.c -I$(IDIR) \
	-lallegro -lallegro_main -lallegro_color -lallegro_primitives \
	-lallegro_font -lallegro_ttf

clean:
	rm -rf $(EXEC) $(EXEC).dSYM

test:
	$(CC) -g $(TBDIR)tb_$(TESTBENCH).c $(SDIR)$(TESTBENCH).c -I$(IDIR) \
	-lallegro -lallegro_main -lallegro_color -lallegro_primitives \

sample:
	$(CC) -g $(SDIR)sample.c -I$(IDIR) \
	-lallegro -lallegro_main -lallegro_color -lallegro_primitives \
