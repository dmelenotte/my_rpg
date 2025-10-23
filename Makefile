##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for my_radar project
##

SRC	:=	./src/main.c											\
		./ECS/Entity/functions/load_entity.c					\
		./ECS/Components/functions/set_sprite_origin.c			\
		./ECS/Entity/functions/erase_entity.c					\
		./ECS/Entity/functions/find_entity.c					\
		./ECS/ECS_List_Components/functions/append_component.c	\
		./ECS/ECS_List_Components/functions/free_components.c	\
		./ECS/ECS_List_Components/functions/find_component.c	\
		./ECS/Data/functions/init_global_data.c					\
		./ECS/Data/functions/load_texture.c						\
		./ECS/Data/functions/load_sprite.c						\
		./ECS/Data/functions/read_config.c						\
		./ECS/Data/functions/destroy_global_data.c				\
		./ECS/Components/functions/system_sprite.c				\
		./ECS/Components/functions/system_position.c			\
		./ECS/Components/functions/system_scale.c				\
		./ECS/Components/functions/system_speed.c				\
		./ECS/Components/functions/system_color.c				\
		./ECS/Components/functions/system_box.c					\
		./ECS/Components/functions/system_rect_display.c		\
		./ECS/Components/functions/system_clock.c				\
		./ECS/Components/functions/system_rotation.c			\
		./ECS/Components/functions/system_health.c				\
		./ECS/Components/functions/system_state.c				\
		./ECS/Components/functions/system_collision.c			\
		./src/loading_screen.c									\
		./src/load_map.c 										\
		./src/event_handler.c									\
		./src/init.c 											\
		./src/quest.c 											\
		./src/mc_mouvement.c 									\
		./src/map_reading.c										\
		./src/collisions.c										\
		./src/world_map_mouve.c									\
		./src/city_move.c										\
		./src/ice_cave_mouve.c									\
		./src/handle_clock.c									\
		./src/sword_attack.c									\
		./src/main_menu.c										\
		./src/boss_mouve.c										\
		./src/display_pnj.c										\
		./src/init_pnj.c										\
		./src/pause_menu.c										\
		./src/init_boat.c										\
		./src/inventory.c										\
		./src/hearts.c 											\
		./src/game_over.c										\
		./src/init_enemies.c									\
		./src/handle_enemies.c									\
		./src/handle_move_enemies.c								\
		./src/handle_animation_enemies.c						\
		./src/init_particle.c									\
		./src/spawn_enemies.c									\
		./src/init_boss.c										\
		./src/handle_boss.c										\

OBJ	:=	${SRC:.c=.o}

BINARY	:=	my_rpg

CFLAGS	:=	-g3

all:	compile

compile: $(OBJ)
	$(CC) $(OBJ) -o $(BINARY) -lcsfml-window	\
		-lcsfml-graphics -lcsfml-system -lm -lcsfml-audio

debug:	$(OBJ)
	$(CC) $(OBJ) -o $(BINARY) -lcsfml-window	\
		-lcsfml-graphics -lcsfml-system -lcsfml-audio -lm $(CFLAGS)

clean:
	rm -f -r $(OBJ)

fclean: clean
	rm -f $(BINARY)

re:	fclean compile

.PHONY: all compile debug clean fclean re
