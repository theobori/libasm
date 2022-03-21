##
## EPITECH PROJECT, 2022
## minilibc
## File description:
## makefile
##

LD			=	ld
CC			=	gcc
ASM			=	nasm

SRC 		=	src/strchr.asm \
				src/memset.asm \
				src/memcpy.asm \
				src/strcmp.asm \
				src/memmove.asm \
				src/strcasecmp.asm \
				src/strstr.asm \
				src/strpbrk.asm \
				src/strcspn.asm \
				src/strrchr.asm \
				src/ffs.asm \
				src/strfry.asm \
				src/memfrob.asm

OBJS		=	$(SRC:.asm=.o)
NAME 		=	libasm.so

LDFLAGS 	=	-shared
ASMFLAGS 	=	-f elf64

TARGET_TEST = $(wildcard tests/*.c)

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJS)

tests_run: fclean $(NAME)
	$(CC) -o test $(TARGET_TEST) --coverage -lcriterion -ldl
	./test

clean:
	$(RM) $(OBJS)
	$(RM) main.o

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(RUN)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) test

re:	fclean all

%.o: %.asm
	$(ASM) $(ASMFLAGS) -o $@ $<
