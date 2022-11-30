##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

LIB_SRC = \
	sprite/functions/new_sprite.c \
	sprite/functions/set_pos.c \
	sprite/functions/set_texture.c \
	sprite/functions/destroy.c \
	\
	sprite/animator/new_animator.c \
	sprite/animator/play_animation.c \
	sprite/animator/set_default.c \
	sprite/animator/remove_animation.c \
	sprite/animator/add_animation.c \
	sprite/animator/have_animation.c \
	sprite/animator/update_frame.c \
	\
	sprite/animation/add_sprite.c \
	sprite/animation/new_animation.c \
	sprite/animation/destroy.c \
	sprite/animation/set_loop.c \
	sprite/animation/set_frame_rate.c \
	\
	sprite/Events/update.c \
	\
	temp/mem/calloc.c \
	temp/mem/memcpy.c \
	temp/mem/memmove.c \
	temp/mem/memset.c \
	temp/mem/realloc.c \
	temp/string/str_cmp.c \
	temp/string/str_len.c

LIB = tools_box_csfml.a
OBJ_LIB = $(LIB_SRC:.c=.o)

GCC = gcc

C_WARNING_FLAGS = -Wextra -Wall

INCLUDE_FLAGS = -I includes

LIB_FLAGS = -L ../ -l:tools_box.a

C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS) $(LIB_FLAGS)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: $(OBJ_LIB)
	@ar rc $(LIB) $(OBJ_LIB)
	cp $(LIB) ../
	mkdir ../../includes/tools_box_csfml
	cp -f -R includes/* ../../includes/tools_box_csfml/
	@find . \( -name "*.o" -or -name "*.a" \) -delete
.PHONY : all

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete
.PHONY : clean
