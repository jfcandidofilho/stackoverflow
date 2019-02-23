CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror -Wextra

rmv = 

src = $(filter-out $(rmv), $(wildcard *.c))
obj = $(src:.c=.o)

target = exe

$(target):	$(obj)
			$(CC) $(CFLAGS) -o $@ $^
			
			@echo program has been compiled!

clean:
			rm -rf $(obj) $(target)
			
			@echo files have been cleaned!
