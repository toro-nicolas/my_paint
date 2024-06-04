##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## The main Makefile of our project
##

COLORS = $$(seq 1 7 | shuf -n 1)
RED = $$(tput setaf $(COLORS))
GREEN = $$(tput setaf $(COLORS))
YELLOW = $$(tput setaf $(COLORS))
RESET = $$(tput sgr0)
MAKEFLAGS += --no-print-directory

CFLAGS = -I./include -Werror -Wpedantic -Wextra
CFLAGS += -g -g3 -lm
CFLAGS += -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
LFLAGS = -L./lib -lmy -llist
TEST_FLAGS = --coverage -lcriterion -lgcov


SRC	=	src/main.c
SRC += src/analyse_events.c

SRC += src/display_main.c
SRC += src/display_save_file.c
SRC += src/display_help.c
SRC += src/events_main.c
SRC += src/events_save_file.c
SRC += src/events_help.c


SRC += src/action/button_file.c
SRC += src/action/button_formats.c
SRC += src/action/button_edit.c
SRC += src/action/button_help.c
SRC += src/action/button_redo_undo.c
SRC += src/action/button_zoom_in_out.c
SRC += src/action/button_layers.c
SRC += src/action/button_color.c
SRC += src/action/button_size.c
SRC += src/action/button_shape.c
SRC += src/action/tools.c

SRC += src/gui/button_functions.c
SRC += src/gui/button_display.c
SRC += src/gui/init_dropdown.c
SRC += src/gui/init_dropdown_file.c
SRC += src/gui/init_dropdown_edit.c
SRC += src/gui/init_dropdown_help.c
SRC += src/gui/init_other_buttons.c
SRC += src/gui/init_redo_undo.c
SRC += src/gui/init_add_delete_layer.c
SRC += src/gui/init_side_menu.c
SRC += src/gui/init_game.c
SRC += src/gui/init_size.c
SRC += src/gui/init_shape.c
SRC += src/gui/layers.c
SRC += src/gui/display_functions.c
SRC += src/gui/init_zoom_button.c
SRC += src/gui/init_color.c
SRC += src/gui/init_mouse.c
SRC += src/gui/init_popup.c

SRC += src/csfml/my_text.c
SRC += src/csfml/my_sprite.c
SRC += src/csfml/my_sound.c
SRC += src/csfml/my_rectangleshape.c
SRC += src/csfml/my_music.c
SRC += src/csfml/my_circleshape.c
SRC += src/csfml/my_color.c


OBJ	=	$(SRC:.c=.o)

NAME = my_paint

all: libmy liblist $(NAME)
	@echo "$(RESET)"

libmy:
	@echo "$(RED)------------------"
	@echo "$(RED)doing libmy"
	@make -s -C ./lib/my/
	@echo "$(RED)------------------"

liblist:
	@echo "$(RED)------------------"
	@echo "$(GREEN)doing liblist"
	@make -s -C ./lib/list/
	@echo "$(RED)------------------"

$(NAME): $(OBJ)
	@gcc $(SRC) -o $(NAME) -g3 $(CFLAGS) $(LFLAGS)

valgrind: $(OBJ)
	@gcc $(SRC) -g3 $(CFLAGS) $(LFLAGS)
	@valgrind -s ./$(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

clean_lib:
	@make fclean -C./lib/my/
	@make fclean -C./tests/

re:	clean_lib fclean all

unit_tests: re
	make unit_tests -C ./tests/

tests_run: re
	make -C ./tests/
	@gcovr
