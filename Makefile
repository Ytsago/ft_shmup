CFLAGS = -Wall -Wextra -Werror -lncurses
CC = cc
AR = ar
ARFLAG = -rcs

FILE = enemy.c display.c main.c ft_shmup_utils.c

INC = ft_shmup.h

SRCS = $(FILE)

BSRCS = $(SRCS) $(BONUSES)

OBJDIR = .Obj/

OBJS = $(SRCS:%.c=$(OBJDIR)%.o)

BOBJS = $(BSRCS:%.c=$(OBJDIR)%.o)

NAME = ft_shmup

all: $(NAME)

$(NAME) : $(OBJS)
	$(cc) $(CFLAG) $< -o $@

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) -c $(CFLAGS) -I. $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: clean fclean re all bonus