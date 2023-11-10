# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:12:12 by sbelomet          #+#    #+#              #
#    Updated: 2023/11/10 11:57:17 by sbelomet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		=	push_swap
HEADERS		=	-I push_swap.h
OBJ_DIR		=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# Colors

RED 		=	\033[1;91m
YELLOW		=	\033[1;93m
GREEN		=	\033[1;92m
BLUE		=	\033[1;94m
PURPLE		=	\033[1;95m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
MAGENTA		=	\033[0;95m
CYAN		=	\033[1;96m
WHITE		=	\033[0;97m
RAINBOW		=	$(RED)-$(YELLOW)-$(GREEN)-$(CYAN)-$(BLUE)-$(PURPLE)-

#Emojis

CLOWN		=	\xf0\x9f\xa4\xa1
DROOLING	=	\xf0\x9f\xa4\xa4
STEAMY		=	\xf0\x9f\xa5\xb5
UMACCTULY	=	\xf0\x9f\xa4\x93
POINT_UP	=	\xe2\x98\x9d\xef\xb8\x8f
MOONBOY		=	\xf0\x9f\x8c\x9d
CHILLY		=	\xf0\x9f\xa5\xb6

#Sources

SRC_RAW		=	main stack_utils1 stack_utils2 utils1 libft_utils1 libft_utils2 \
				split swap_commands push_commands rotate_commands reverse_rotate_commands

SRCS		=	$(addsuffix .c, $(SRC_RAW))
OBJS		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_RAW)))

###

all:			$(OBJ_DIR) $(NAME)

$(NAME):		$(OBJS)
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo ""
				@echo "$(GREEN)$(NAME) est compilé !$(DEF_COLOR)$(CHILLY)$(CHILLY)$(CHILLY)"
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c	
				@echo "$(YELLOW)$< est dans le four...$(DEF_COLOR)$(STEAMY)$(STEAMY)$(STEAMY)"
				@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@rm -rf $(OBJ_DIR)
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
				@echo "$(BLUE)à la poubelle les .o$(DEF_COLOR)$(UMACCTULY)$(UMACCTULY)$(UMACCTULY)"

fclean:			clean
				@rm -f $(NAME)
				@echo "$(CYAN)à la poubelle l'exec$(DEF_COLOR)$(DROOLING)$(DROOLING)$(DROOLING)"
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"

re:				fclean all

.PHONY:			all clean fclean re
