CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror

src = $(wildcard *.c)
obj = $(src:.c=.o)

target = exe

$(target):	$(obj)
			$(CC) $(CFLAGS) -o $@ $^
			
			@echo gnutic has been compiled!

clean:
			rm -rf $(obj) $(target)
			
			@echo files have been cleaned!
