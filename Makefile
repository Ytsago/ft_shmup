# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: secros <secros@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 05:20:49 by jaubry--          #+#    #+#              #
#    Updated: 2024/11/24 12:14:00 by secros           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		ft_shmup

SRCSDIR=	srcs
SRCS=		main.c \
			engine.c \
			window.c \
			vector.c \
			menu.c \
			stat.c \
			game.c \
			entity.c
			
ifdef BONUS
SRCS:=		$(SRCS) \
			ft_lstnew_bonus.c
endif

OBJDIR=		.obj

OBJS=		$(addprefix $(OBJDIR)/, $(SRCS:srcs/%.c=%.o))

SRCS:=		$(addprefix $(SRCSDIR)/, $(SRCS))

LIBDIR=		libft
LIBFT=		$(LIBDIR)/libft.a

INCDIR=		includes

INCLUDES=	bullet.h \
			entity.h \
			game.h \
			game_data.h \
			vector.h \
			engine.h \
			shmup.h \
			window.h

INCLUDES:=	$(addprefix $(INCDIR)/, $(INCLUDES)) \
			$(addprefix $(LIBDIR)/, libft.h)

vpath %.h	$(INCDIR) $(LIBDIR)
vpath %.c	$(SRCSDIR)
vpath %.o	$(OBJDIR)

MAKEFILE=	Makefile

CC=			cc
CFLAGS=		-Wall -Wextra -Werror
INCFLAGS=	-I$(INCDIR) -I$(LIBDIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) | $(INCLUDES)
	$(CC) $(CFLAGS) $(INCFLAGS) -lncurses $? -o $@ 

$(LIBFT):
	make bonus -C $(LIBDIR)

bonus:
	$(MAKE) BONUS=1 all

$(OBJDIR)/%.o: %.c $(MAKEFILE) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

hclean:
	rm -rf $(addsuffix .gch, $(INCLUDES))

clean: hclean
	rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
	@make -C $(LIBDIR) re


.PHONY: all clean fclean re hclean

