NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g3 -fsanitize=address
INCLUDES = -I./include
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/algorithm.c \
       $(SRC_DIR)/parse.c \
       $(SRC_DIR)/push_operations.c \
       $(SRC_DIR)/reverse_rt_op.c \
       $(SRC_DIR)/rotate_operations.c \
       $(SRC_DIR)/sort.c \
       $(SRC_DIR)/sort_ksort.c \
       $(SRC_DIR)/split.c \
       $(SRC_DIR)/stack_operations.c \
       $(SRC_DIR)/swap_opetations.c \
       $(SRC_DIR)/utils.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADERS = $(INC_DIR)/push_swap.h

all: $(NAME)
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(CYAN)Creating object directory...$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean $(NAME)
	@echo "$(MAGENTA)Debug version compiled!$(RESET)"

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(RED)Object files removed.$(RESET)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED)$(NAME) removed.$(RESET)"; \
	fi

re: fclean all

test: $(NAME)
	@echo "$(BLUE)Running tests...$(RESET)"
	@echo "$(CYAN)Test 1: Simple case$(RESET)"
	@./$(NAME) 2 1 3 6 5 8
	@echo ""
	@echo "$(CYAN)Test 2: Already sorted$(RESET)"
	@./$(NAME) 1 2 3 4 5
	@echo ""
	@echo "$(CYAN)Test 3: Reverse order$(RESET)"
	@./$(NAME) 5 4 3 2 1

test-performance: $(NAME)
	@echo "$(BLUE)Performance test with 100 random numbers:$(RESET)"
	@ARG=$$(shuf -i 1-1000 -n 100 | tr '\n' ' '); \
	MOVES=$$(./$(NAME) $$ARG | wc -l); \
	echo "$(YELLOW)Moves used: $$MOVES$(RESET)"; \
	if [ $$MOVES -lt 700 ]; then \
		echo "$(GREEN)✓ Performance test passed! (< 700 moves)$(RESET)"; \
	else \
		echo "$(RED)✗ Performance test failed! (>= 700 moves)$(RESET)"; \
	fi

test-500: $(NAME)
	@echo "$(BLUE)Performance test with 500 random numbers:$(RESET)"
	@ARG=$$(shuf -i 1-5000 -n 500 | tr '\n' ' '); \
	MOVES=$$(./$(NAME) $$ARG | wc -l); \
	echo "$(YELLOW)Moves used: $$MOVES$(RESET)"; \
	if [ $$MOVES -lt 5500 ]; then \
		echo "$(GREEN)✓ Performance test passed! (< 5500 moves)$(RESET)"; \
	else \
		echo "$(RED)✗ Performance test failed! (>= 5500 moves)$(RESET)"; \
	fi

help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)              - Build the program"
	@echo "  $(GREEN)clean$(RESET)            - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)           - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)               - Rebuild everything"
	@echo "  $(GREEN)debug$(RESET)            - Build with debug flags"
	@echo "  $(GREEN)test$(RESET)             - Run basic tests"
	@echo "  $(GREEN)test-performance$(RESET) - Test with 100 numbers"
	@echo "  $(GREEN)test-500$(RESET)         - Test with 500 numbers"
	@echo "  $(GREEN)help$(RESET)             - Show this help"

.PHONY: all clean fclean re debug test test-performance test-500 help
.PRECIOUS: $(OBJ_DIR)/%.o