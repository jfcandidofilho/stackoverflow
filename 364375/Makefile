CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror -Wextra

rmv = exemplo_01.c exemplo_02.c

src = $(filter-out $(rmv), $(wildcard *.c))
obj = $(src:.c=.o)

target = exe

$(target):	$(obj)
			$(CC) $(CFLAGS) -o $@ $^
			
			@echo gnutic has been compiled!

clean:
			rm -rf $(obj) $(target)
			
			@echo files have been cleaned!
