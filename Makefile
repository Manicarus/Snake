SHELL = /bin/sh

CC = gcc
IDIR = /usr/local/include/allegro5/
HDIR = ./include/
SDIR = ./src/
#EXEC =
#OBJECTS =
TESTBENCH = game
TBDIR = ./lab/

clean:
	rm -f

test:
	$(CC) -g $(TBDIR)tb_$(TESTBENCH).c $(SDIR)$(TESTBENCH).c $(HDIR)$(TESTBENCH).h -I$(IDIR) -lallegro -lallegro_main
	# $(CC) -g $(TBDIR)tb_$(TESTBENCH).c $(SDIR)$(TESTBENCH).c $(HDIR)$(TESTBENCH).h -I$(IDIR) -lallegro
