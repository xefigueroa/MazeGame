# Compiler.
CC = gcc
# Source files (names).
SRC = *.c
# Object files (names same as source files).
OBJ = $(SRC:.c=.o)
# Name of executable file.
NAME = maze
# Remove files.
RM = rm -f
# Compiler flags.
CFLAGS = -Wall -Werror -Wextra -pedantic
# Linker flags.
LFLAGS = -lSDL2 -lSDL2_image -lm



# Compilation of executable.
all: $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LFLAGS) -o $(NAME)
# Remove temporary files and executable.
clean:
	$(RM) *~ $(NAME)
# Remove object files.
oclean:
	$(RM) $(OBJ)
# Remove temp, object, and executable files.
fclean: clean oclean
# Remove all created files and re-compile all.
re: oclean all
