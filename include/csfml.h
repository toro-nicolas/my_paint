/*
** EPITECH PROJECT, 2023
** Libmy
** File description:
** Store libmy functions prototypes
*/


#ifndef CSFML_H
    #define CSFML_H

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <malloc.h>
    #include <stdlib.h>
    #include <time.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <math.h>
    #include "mylist.h"
    #include "my.h"

    #define MAX(a, b) ((a > b) ? a : b)
    #define MIN(a, b) ((a < b) ? a : b)
    #define TEXTURE "assets/texture.png"
    #define SIZE_B ((sfVector2f) {100, 50})
    #define DECALE_W (1920 / 4)
    #define DECALE_H (1080 / 4)
    #define HOLDED_COLOR (sfColor_fromRGB(50, 50, 50))
    #define HOVER_COLOR (sfColor_fromRGB(32, 38, 38))
    #define NONE_COLOR (sfColor_fromRGB(14, 19, 20))

enum format {
    PNG,
    BMP,
    JPG,
};

enum popup_state {
    NONE_POPUP,
    SAVE_POPUP,
    OPEN_POPUP,
};

enum scene {
    MAIN,
    SAVE_FILE,
    HELP,
    OPEN_FILE,
};

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f origin;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfIntRect initial_rect;
    sfVector2f speed;
    sfClock *clock;

    sfText *text;
    sfCircleShape *circle_hitbox;
    sfRectangleShape *rectangle_hitbox;

    char *id;
} sprite_t;

typedef struct {
    char const *str;

    char const *font;
    int size;
    sfColor color;

    sfColor outline_color;
    float outline_size;

    sfTextStyle style;

    sfVector2f scale;
    sfVector2f position;
} text_t;

typedef struct rect_s {
    sfVector2f *origin;
    sfVector2f *scale;
    sfColor *fill_color;
    sfColor *outline_color;
    float outline_thickness;
    sfVector2f *size;
    float rotation;
} rect_t;

typedef struct {
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfView *view;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2i mouse_pos;
    sfVector2i old_mouse_pos;
    sfClock *clock;
    sfEvent event;
    sfFont *font;
    float resize;
    float delay;
    int framerate;
} window_info_t;

typedef struct variables {
    int standby;
} user_variables_t;

enum button_state {
    NONE,
    HOVER,
    PRESSED,
    CLICKED,
    HOLDED,
};

enum tool {
    NOTOOL,
    PENCIL,
    ERASER,
    BRUSH,
    SELECTION,
};

enum shape {
    CIRCLE,
    SQUARE,
    DIAMOND,
    HEXAGON,
};

typedef struct button {
    sfRectangleShape *rect;
    void (*action)(struct button *);
    bool hover;
    bool clicked;
    sfText *button_text;
    sfSprite *logo;
} button_t;

typedef struct tool_info {
    enum tool tool;
    button_t *tool_button;
    int size;
    sfColor color;
    sfImage *color_image;
    sfSprite *color_sprite;
    enum shape shape;
    button_t *shape_button;
} tool_info_t;

typedef struct button_dropdown {
    button_t *main_button;
    nodes_t *button_options;
} button_dropdown_t;

typedef struct popup_s {
    sprite_t *popup_sprite_info;
    sfText *text;
    nodes_t *buttons_list;
    sfText *input;
    char *input_str;
    enum popup_state state;
} popup_t;

typedef struct layer_info {
    nodes_t *layer_list;
    int layer_id;
} layer_info_t;

typedef struct {
    window_info_t *info_window;
    user_variables_t *user_variables;
    int state;
    bool mouse_is_painting;
    int old_state;

    nodes_t *dropdown_list;
    nodes_t *buttons_list;
    nodes_t *side_menu_list;
    nodes_t *layers_list;
    nodes_t *undo_redo_list;
    int layer_id;
    int undo_redo_id;

    char *file_name;
    int fd;

    enum button_state mouse_state;
    sfView *tview;
    tool_info_t *tool_info;
    popup_t *popup;
    button_t *save_type;

    sfVector2i first_spot;
} game_info_t;



void display_all(game_info_t *game_info);
void display_main(game_info_t *game_info);
void display_save_file(game_info_t *game_info);
void display_help(game_info_t *game_info);
void events_main(game_info_t *game_info, sfEvent event);
void events_save_file(game_info_t *game_info, sfEvent event);
void events_help(game_info_t *game_info, sfEvent event);


    #define FONT get_game_info()->info_window->font

// ANALYSE EVERYTHING
int convert_mouse_pos(game_info_t *game_info);
void analyse_events(game_info_t *game_info);
int analyse_key_pressed(game_info_t *game_info);
int analyse_mouse_pressed(game_info_t *game_info);
int analyse_resize(sfRenderWindow *window, sfEvent event);
int analyse_other_buttons(game_info_t *game_info, nodes_t *button_list);
enum format *get_format(int format2);


game_info_t *get_game_info(void);
void init_game_info(game_info_t *game_info);
void free_game(game_info_t *game_info);

//Init sprite
sprite_t *my_sprite(sprite_t *info_sprite);

//Text creation
sfText *my_text(text_t *info_text);

//Sound creation
sfSound *my_sound(char const *filename);
sfMusic *my_music(char const *filename);

//Init Shape
sfCircleShape *my_circle(sfVector2f position, float radius, sfColor color);
sfRectangleShape *my_rectangle(sfVector2f position, sfVector2f size,
    sfColor color, int outline);
sfRectangleShape *create_rectangle_shape(rect_t *rectangle_shape,
    sfVector2f position);

//Color
bool compare_color(sfColor color1, sfColor color2);

/////////////////////////////////////////:

//BUTTON FCT
int reset_state_hover(nodes_t *dropdown_list, sfVector2i mousepos);
button_t *init_button(sfVector2f position, sfVector2f size,
    sfText *text, void (*action)(button_t *));
sfBool is_clicked(button_t *button, sfMouseButtonEvent mouse);
sfBool is_hover(button_t *button, sfVector2i pos);
void handle_hover(game_info_t *game_info);
int handle_click(game_info_t *game_info);
void display_if_clicked(game_info_t *game_info);
void display_sub_buttons(game_info_t *game_info, nodes_t **);

button_t *sub_button_is_clicked(nodes_t *buttons_list,
    sfMouseButtonEvent mouse);
button_dropdown_t *dropdown_is_clicked(nodes_t *dropdown_list,
    sfMouseButtonEvent mouse);


// INIT 'MUST' DROPDOWN
int init_dropdown(nodes_t **dropdown_list);
button_dropdown_t *init_file_dropdown(void);
button_dropdown_t *init_edit_dropdown(void);
button_dropdown_t *init_help_dropdown(void);

// INIT 'MUST' SIDE MENU
int init_side_menu(nodes_t **list);
button_t *init_current_color(void);

// INIT 'MUST' BUTTONS
// BTN FILE
void button_file(button_t *button);
void button_new(button_t *button);
void button_open(button_t *button);
void button_save(button_t *button);
void button_jpg(button_t *button);

// BTN EDIT
void button_edit(button_t *button);
void button_pencil(button_t *button);
void button_eraser(button_t *button);
void button_brush(button_t *button);
void button_selection(button_t *button);
sfRectangleShape *get_selection_frame(void);

// BTN HELP
void button_help(button_t *button);
void button_about(button_t *button);
void button_usage(button_t *button);
void button_icon(button_t *button);

// BTN REDO UNDO
void button_redo(button_t *button);
void button_undo(button_t *button);

// BTN ADD DELETE LAYER
void button_add_layer(button_t *button);
void button_delete_layer(button_t *button);

// BTN SIZE
void button_plus_size(button_t *button);
void button_minus_size(button_t *button);

// BTN SHAPE
void button_square_shape(button_t *button);
void button_circle_shape(button_t *button);
void button_diamond_shape(button_t *button);
void button_hexagon_shape(button_t *button);

// BTN OTHER
button_t *init_pencil_button(void);
button_t *init_eraser_button(void);
button_t *init_square_shape(void);
button_t *init_circle_shape(void);
void init_redo_button(game_info_t *game_info);
void init_undo_button(game_info_t *game_info);
int init_add_delete_layer_button(game_info_t *game_info);
void init_size_button(game_info_t *game_info);
void init_shape_button(game_info_t *game_info);
void init_other_buttons(game_info_t *game_info);

//BTN COLOR
void init_color_button(void);
void button_color(button_t *button);
int mouse_on_color(game_info_t *game_info);
void update_color(game_info_t *game_info);

//BTN ZOOM
int init_zoom_button(game_info_t *game_info);
void init_zoom_out(game_info_t *game_info);
void init_zoom_in(game_info_t *game_info);
void button_zoom_out(button_t *button);
void button_zoom_in(button_t *button);

/////////////////////////////////////////////:

//LAYER
sfSprite *img_to_sprite(sfImage *img, sfVector2f pos);
void display_all_layers(nodes_t *layers_list, sfRenderWindow *window);
sfImage *get_layer(nodes_t *layers_list, int id);
int mouse_on_layer(game_info_t *game_info);

//DISPLAY
void display_all_dropdown(nodes_t *dropdown_list, sfRenderWindow *window);
void display_all_buttons(nodes_t *buttons_list, sfRenderWindow *window);
void display_side_menu(nodes_t *list, sfRenderWindow *window);
void display_image_color(void);

//TOOLS
void do_tools(game_info_t *game_info);
void do_size(game_info_t *game_info);
void pencil_tool(game_info_t *game_info);

//SIZE
sfText *display_size(void);
sfText *display_color(void);
void display_mouse(game_info_t *game_info);
sfText *display_layers_text(void);

//POPUP
int init_popup(game_info_t *game_info);
button_t *init_png_format(void);
button_t *init_jpg_format(void);
button_t *init_bmp_format(void);

void save_in_undo_redo(game_info_t *game_info);

#endif //CSFML_H
