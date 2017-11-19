# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 23:13:05 by tberthie          #+#    #+#              #
#    Updated: 2017/11/19 19:07:23 by tberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(addsuffix .o, $(addprefix objs/, main parse run))

NAME = rtv1
FLAGS = -Wall -Wextra -Ofast
INCS = -I includes -I libft -I SDL

all: objs $(NAME)

objs:
	mkdir objs

$(NAME): $(OBJS)
	make -C libft
	gcc $(FLAGS) -o $(NAME) libft/libft.a SDL/SDL_lib SDL/SDL_libttf $(OBJS)

objs/%.o: srcs/%.c
	gcc $(FLAGS) $(INCS) -o $@ -c $<

clean:
	rm -rf objs

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
