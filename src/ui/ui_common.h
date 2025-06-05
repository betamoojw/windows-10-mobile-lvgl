

#ifndef _W10M_UI_COMMON_H
#define _W10M_UI_COMMON_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ui.h"

typedef enum
{
    CM_LIVE_NONE = -1,
    CM_LIVE_VERTICAL,
    CM_LIVE_HORIZONTAL
} cm_live_dir_t;

typedef enum
{
    TM_BG_COLOR = (1 << 0),
    TM_BORDER_COLOR = (1 << 1),
    TM_IMAGE_TINT = (1 << 2),

    TM_ALL = 0xFF
} theme_type_t;

typedef struct _app_info_t
{
    uint64_t code;
    const char *name;
    const lv_img_dsc_t *icon;
} app_info_t;

typedef struct _start_tile_t
{
    app_info_t app;
    bool wide;
    const lv_img_dsc_t *live;
    cm_live_dir_t dir;
} start_tile_t;

typedef struct _user_info_t
{
    const char *username;
    const lv_img_dsc_t *icon;
} user_info_t;

typedef struct _live_obj_t
{
    lv_obj_t *obj;
    cm_live_dir_t dir;
} live_obj_t;

typedef struct _quick_action
{
    uint64_t code;
    const char *name;
    const lv_img_dsc_t *icon;
    bool checkable;
} quick_action;

typedef struct _settings_info_t
{
    uint64_t code;
    const char *title;
    const char *desc;
    const lv_img_dsc_t *icon;
} settings_info_t;

typedef struct _accent_color_t
{
    const char* name;
    uint32_t color;
} accent_color_t;

typedef struct _themeable_t
{
    lv_obj_t *obj;
    theme_type_t type;
} themeable_t;

typedef struct _wifi_info_t
{
    int32_t rssi;
    bool secure;
    char name[33];
} wifi_info_t;


extern accent_color_t colors[];


lv_obj_t *cm_create_text(lv_obj_t *parent, const char *text);
lv_obj_t *cm_create_switch(lv_obj_t *parent, const char* text, bool active, void (*callback)(lv_event_t *e));
lv_obj_t *cm_create_button(lv_obj_t *parent, const char *text);
lv_obj_t *cm_create_title(lv_obj_t *parent, const char *text);
lv_obj_t *cm_create_text_area(lv_obj_t *parent, const char *placeholder, void (*color)(lv_obj_t *obj));
lv_obj_t *cm_create_slider(lv_obj_t *parent, int value, int min, int max, void (*callback)(lv_event_t *e));
lv_obj_t *cm_create_panel_space(lv_obj_t *parent, int height);
lv_obj_t *cm_create_bar(lv_obj_t *parent, int value, const char* format);
void cm_set_bar(lv_obj_t *obj, int value, const char* format);
lv_obj_t *cm_create_dropdown(lv_obj_t *parent, const char* options, int selected, int width, void (*callback)(lv_event_t *e));

void cm_ir_tile(lv_obj_t *parent);


void cm_user_list(lv_obj_t *parent, user_info_t user);

lv_obj_t * cm_quick_action(lv_obj_t *parent, quick_action action, void (*callback)(lv_event_t *e));

void cm_start_tile(start_tile_t tile, void(*callback)(live_obj_t l), void (*launcher)(lv_event_t * e), void(*start)(lv_obj_t *obj));
void cm_app_list(app_info_t app, void(*launcher)(lv_event_t *e), void(*panel)(lv_obj_t *obj));

void cm_settings_list(lv_obj_t *parent, settings_info_t setting, void (*launcher)(lv_event_t * e), void(*img)(lv_obj_t *obj));
void cm_accent_color(lv_obj_t *parent, accent_color_t color, void (*callback)(lv_event_t *e));
void cm_image_select(lv_obj_t *parent, const lv_img_dsc_t *img, uint64_t index, void (*callback)(lv_event_t *e));

void cm_create_app_title(lv_obj_t *parent, const char * title, const lv_img_dsc_t *image);

void set_parent(lv_obj_t *parent);




void add_wifi_list(lv_obj_t *parent, wifi_info_t wifi);



#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif