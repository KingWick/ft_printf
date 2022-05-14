# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/07 15:21:24 by akdjebal          #+#    #+#              #
#    Updated: 2022/05/13 15:07:17 by akdjebal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_printf.c \
		ft_util_printf.c \

NAME = libftprintf.a 

LIBFT_DIRECTION = libft/

OBJETS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : ${OBJETS}
	@$(MAKE) -C $(LIBFT_DIRECTION)
	@ echo "Compilation Libft OK"
	@ ar rc $(NAME) $^
	@ ranlib $(NAME)
	@ echo "Compilation OK"

clean: 
	@ rm -rf ${OBJETS} 
	$(MAKE) clean -C $(LIBFT_DIRECTION)
	@ echo "Clean Printf OK"

fclean: 
	@ rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIRECTION)
	@ echo "fclean Printf OK"

re: fclean all 

.PHONY: all clean fclean re 