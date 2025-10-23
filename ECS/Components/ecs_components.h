/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** ECS_Components.h
*/

#ifndef ECS_COMPONENTS
    #define ECS_COMPONENTS

    #include <stdbool.h>
    #include <SFML/Graphics.h>

    #define SET_ACTIVE 1
    #define SET_DISPLAY 2

typedef struct global_data_s global_data_t;

typedef struct component_sprite_s {
    sfSprite *sprite;
} component_sprite_t;

typedef struct component_rect_s {
    sfRectangleShape *rect;
} component_rect_t;

typedef struct component_circle_s {
    sfCircleShape *circle;
} component_circle_t;

typedef struct component_position_s {
    float x;
    float y;
} component_position_t;

typedef struct component_rotation_s {
    float angle;
} component_rotation_t;

typedef struct component_scale_s {
    float scale_x;
    float scale_y;
} component_scale_t;

typedef struct component_color_s {
    sfColor fill_color;
    sfColor outline_color;
    float outline_thickness;
} component_color_t;

typedef struct component_box_s {
    sfFloatRect global_box;
    sfFloatRect local_box;
} component_box_t;

typedef struct component_rect_display_s {
    sfIntRect rect;
} component_rect_display_t;

typedef struct component_frame_s {
    sfTime frame_time;
} component_frame_t;

typedef struct component_state_s {
    bool state_active;
    bool state_display;
} component_state_t;

typedef struct component_speed_s {
    float speed;
} component_speed_t;

typedef struct component_health_s {
    int current_health;
    int max_health;
} component_health_t;

typedef struct component_stats_s {
    int attack;
    int defense;
    int endurance;
} component_stats_t;

typedef struct component_inventory_s {
    int inventory[20];
} component_inventory_t;

enum components_types_s {
    COMPONENT_SPRITE,
    COMPONENT_RECT,
    COMPONENT_CIRCLE,
    COMPONENT_POSITION,
    COMPONENT_ROTATION,
    COMPONENT_SCALE,
    COMPONENT_COLOR,
    COMPONENT_BOX,
    COMPONENT_RECT_DISPLAY,
    COMPONENT_FRAME,
    COMPONENT_STATE,
    COMPONENT_SPEED,
    COMPONENT_HEALTH,
    COMPONENT_STATS,
    COMPONENT_INVENTORY
};

enum get_collisions_s {
    GLOBAL,
    LOCAL
};

enum rect_display_action_s {
    LEFT,
    HEIGHT,
    TOP,
    WIDTH
};

enum operation_s {
    ASSIGN,
    ADD,
    SUB
};

enum time_comparison_s {
    INFERIOR,
    SUPERIOR
};

component_sprite_t *set_sprite(void);
void assign_sprite(component_sprite_t *sprite, char *sprite_name,
    global_data_t global_data);
void assign_sprite_position(component_sprite_t *sprite,
    component_position_t *position);
void assign_sprite_scale(component_sprite_t *sprite, component_scale_t *scale);
void display_sprite(component_sprite_t *sprite, sfRenderWindow *window);
void origin_sprite(component_sprite_t *sprite, sfVector2f origin);

component_position_t *set_position(void);
void assign_position(component_position_t *position, float x, float y);

component_scale_t *set_scale(void);
void assign_scale(component_scale_t *scale, float x, float y);

component_speed_t *set_speed(void);
void assign_speed(component_speed_t *speed, float var_speed);

component_color_t *set_color(void);
void assign_fill_color(component_color_t *color, sfColor fill_color);
void assign_outline_color(component_color_t *color, sfColor outline_color);
void assign_outline_thickness(component_color_t *color,
    float outline_thickness);

component_box_t *set_box(void);
void assign_sprite_box(component_box_t *box, component_sprite_t *sprite);
void assign_rect_box(component_box_t *box, component_rect_t *rect);
void assign_circle_box(component_box_t *box, component_circle_t *circle);
bool check_collisions(component_box_t *box_1, component_box_t *box_2,
    enum get_collisions_s get);

bool global_enter_in_collision(component_sprite_t *sprite1,
    component_sprite_t *sprite2);
bool local_enter_in_collision(component_sprite_t *sprite1,
    component_sprite_t *sprite2);

component_rect_display_t *set_rect_display(void);
void change_rect_display_values(component_rect_display_t *rect_display,
    sfFloatRect rect, enum operation_s operation);
void assign_sprite_rect_display(component_rect_display_t *rect_display,
    component_sprite_t *sprite);

component_frame_t *set_clock(void);
void increment_clock_time(component_frame_t *frame, sfClock *clock_process);
bool check_time(component_frame_t *frame, float time,
    enum time_comparison_s comp);
void restart_time(component_frame_t *frame);

void move_position(component_position_t *position, component_frame_t *frame,
    sfVector2f vector);

component_rotation_t *set_rotation(void);
void assign_rotation(component_rotation_t *rotation, float angle);
void assign_sprite_rotation(component_sprite_t *sprite,
    component_rotation_t *rotation);
void change_rotation(component_rotation_t *rotation, float value,
    enum operation_s operation);

component_health_t *set_health(void);
void assign_max_health(component_health_t *health, int value);
void change_health(component_health_t *health, int value);
bool check_health(component_health_t *health, int threshold);

component_state_t *set_state(void);
void change_state(component_state_t *state, int setting, ...);
bool check_active(component_state_t *state);
bool check_display(component_state_t *state);

#endif
