# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 17:52:51 by diolivei          #+#    #+#              #
#    Updated: 2025/05/27 15:28:45 by ppassos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler flags
FLGS = -Wall -Wextra -Werror

# Commands
CC = cc -g
RM = rm -f

# Supress makefile messages
MAKEFLAGS += -s

# Source files
SRCS = dinner.c main.c monitor.c philo_init.c safe_function.c utils.c g_setters.c parsing.c s_utils.c write.c

# Object files
OBJDIR = Objs
OBJS = $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRCS))

# Output
NAME = philo

# Create object directory if it doesn't exist
$(shell mkdir -p $(OBJDIR))

# Main target
$(NAME): $(OBJS)
	@$(CC) $(FLGS) $(OBJS) -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"

# Compile all source files
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(OBJDIR)
	@ $(CC) -c $(FLGS) -o $@ $<

# Phony targets
.PHONY: all clean fclean re exec norm normi

all: $(NAME)

clean:
	@$(RM) -r $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all