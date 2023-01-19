SERVER		= server
CLIENT		= client

CFLAGS		= -g3 -Wall -Werror -Wextra
INCLUDES	= -I./includes -I$(LIBFT_INC)

LIBFT_PATH	= ./libs/libft
LIBFT_INC	= $(LIBFT_PATH)/includes
LIBFT		= $(LIBFT_PATH)/libft.a

S_OBJ	= ./src/$(SERVER).o
C_OBJ	= ./src/$(CLIENT).o
#colors
GRENN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
RESET		= \033[0m

all: $(SERVER) $(CLIENT) 

$(SERVER): $(LIBFT) $(S_OBJ)
	@gcc $(CFLAGS) $(S_OBJ) $(LFLAGS) $(LIBFT) -o $(SERVER)
	@echo " $(CYAN)$(SERVER): $(GRENN)Done!"
	@echo -n "$(RESET)"

$(CLIENT): $(LIBFT) $(C_OBJ)
	@gcc $(CFLAGS) $(C_OBJ) $(LFLAGS) $(LIBFT) -o $(CLIENT)
	@echo " $(CYAN)$(CLIENT): $(GRENN)Done!"
	@echo -n "$(RESET)"

%.o: %.c
	@gcc -c $< -o $@ $(CFLAGS) -g $(INCLUDES)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

clean:
	@make -sC $(LIBFT_PATH) clean
	@rm -rf ./src/$(SERVER).o ./src/$(CLIENT).o

fclean: clean
	@make -sC $(LIBFT_PATH) fclean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all

coffee:
	@make -sC $(LIBFT_PATH) coffee

.PHONY: all clean fclean re coffee