CPPC = g++
CPPFLAGS = -Wall -pedantic -ansi -Werror -Wextra

rmv = 

src = $(filter-out $(rmv), $(wildcard *.cpp))
obj = $(src:.cpp=.o)

target = exe

$(target):	$(obj)
			$(CPPC) $(CPPFLAGS) -o $@ $^
			
			@echo program has been compiled!

clean:
			rm -rf $(obj) $(target)
			
			@echo files have been cleaned!
