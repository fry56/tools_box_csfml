##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

SRC = \
	src/sprite/functions/new_sprite.c \
	src/sprite/functions/set_pos.c \
	src/sprite/functions/set_texture.c \
	src/sprite/functions/destroy.c \
	src/sprite/functions/update.c \
	\
	src/sprite/animator/new_animator.c \
	src/sprite/animator/play_animation.c \
	src/sprite/animator/set_default.c \
	src/sprite/animator/remove_animation.c \
	src/sprite/animator/add_animation.c \
	src/sprite/animator/have_animation.c \
	src/sprite/animator/update_frame.c \
	src/sprite/animator/callback.c \
	src/sprite/animator/add_callback.c \
	src/sprite/animator/remove_callback.c \
	\
	src/sprite/animation/add_sprite.c \
	src/sprite/animation/new_animation.c \
	src/sprite/animation/destroy.c \
	src/sprite/animation/set_loop.c \
	src/sprite/animation/set_frame_rate.c \
	\
	src/sprite/events/add_event.c \
	src/sprite/events/remove_event.c \
	src/sprite/events/use_event.c \
	\
	src/sprite/events/handling/is_mouse_over.c \
	src/sprite/events/handling/is_mouse_click.c \
	\
	src/window/new_window.c \
	src/window/change_scene.c \
	src/window/update.c \
	src/window/new_scene.c \
	\
	src/scene/add_clock_update_function.c \
	src/scene/add_event_update_function.c \
	src/scene/remove_clock_update_function.c \
	src/scene/remove_event_update_function.c

OBJ = $(SRC:.c=.o)

GCC = gcc

INCLUDE_FLAGS = \
	-I include/ \
	-I ../tools_box/include/

C_WARNING_FLAGS = -Wextra -Wall
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: tools_box_csfml.a
.PHONY : all

tools_box_csfml.a: $(OBJ)
	@ar rc $@ $(OBJ)
.PHONY : tools_box_csfml.a

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete
.PHONY : clean
