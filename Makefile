# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:07:46 by fmoulin           #+#    #+#              #
#    Updated: 2025/07/18 16:18:50 by fmoulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME	= pipex

# Sources
SRCS	= main.c pipex.c get_cmd_path.c read_from_infile.c write_on_outfile.c execute_cmd.c \
		free.c

# Objets
OBJS_DIR = obj
OBJS	= $(OBJS_DIR)/main.o $(OBJS_DIR)/pipex.o $(OBJS_DIR)/get_cmd_path.o \
		$(OBJS_DIR)/read_from_infile.o $(OBJS_DIR)/write_on_outfile.o $(OBJS_DIR)/execute_cmd.o \
		$(OBJS_DIR)/free.o

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
IFLAGS = -Iinclude -Ilibft
RM = rm -f

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Règle par défaut
all: $(LIBFT) $(NAME)

# Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Exécutable principal
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

# Compilation des objets
$(OBJS_DIR)/%.o: src/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
# $(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
