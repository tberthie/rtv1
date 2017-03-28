# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 23:13:05 by tberthie          #+#    #+#              #
#    Updated: 2017/03/29 00:26:13 by tberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(addsuffix .c, main parse parse_elem run render ray)

OBJS = $(addprefix objs/,$(SRCS:.c=.o))

NAME = rtv1
FLAGS = -Wall -Wextra -O3
INCS = -I includes -I libft -I SDL

all: objs $(NAME)

objs:
	mkdir objs

$(NAME): $(OBJS)
	make -C libft
	gcc $(INCS) $(FLAGS) -o $(NAME) libft/libft.a SDL/libSDL2-2.0.0.dylib $(OBJS)

objs/%.o: srcs/%.c
	gcc $(FLAGS) $(INCS) -o $@ -c $<

clean:
	rm -rf objs

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
