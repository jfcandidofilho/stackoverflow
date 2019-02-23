CC = g++
CFLAGS = -Wall -pedantic -ansi -Werror -Wextra

rmv = 

src = $(filter-out $(rmv), $(wildcard *.cpp))
obj = $(src:.cpp=.o)

target = exe

$(target):	$(obj)
			$(CC) $(CFLAGS) -o $@ $^
			
			@echo gnutic has been compiled!

clean:
			rm -rf $(obj) $(target)
			
			@echo files have been cleaned!
