NAME=		libft.a

SRCS=		ft_atoi.c \
			ft_isascii.c \
			ft_memcmp.c \
			ft_putendl_fd.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strtrim.c \
			ft_bzero.c \
			ft_isdigit.c \
			ft_memcpy.c \
			ft_putnbr_fd.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_substr.c \
			ft_calloc.c \
			ft_isprint.c \
			ft_memmove.c \
			ft_putstr_fd.c \
			ft_strjoin.c \
			ft_strncmp.c \
			ft_tolower.c \
			ft_isalnum.c \
			ft_itoa.c \
			ft_memset.c \
			ft_split.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_toupper.c \
			ft_isalpha.c \
			ft_memchr.c \
			ft_putchar_fd.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strrchr.c \
			ft_split_utils.c
ifdef BONUS
SRCS :=		$(SRCS) \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c
endif

OBJDIR=		.obj

OBJS=		$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

INCLUDES=	libft.h
MAKEFILE=	Makefile

CC=			cc
CFLAGS=		-Wall -Wextra -Werror

AR=			ar
ARFLAGS=	rcs

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES) $(MAKEFILE)
	$(AR) $(ARFLAGS) $@ $^

bonus:
	$(MAKE) BONUS=1 all

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(INCLUDES).gch

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
