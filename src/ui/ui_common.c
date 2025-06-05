

#include "ui_common.h"



accent_color_t colors[] = {
    {"Lime", 0xA4C400},
    {"Green", 0x60A917},
    {"Emerald", 0x00BA00},
    {"Teal", 0x00ABA9},
    {"Cyan", 0x1BA1E2},
    {"Cobalt", 0x0050EF},
    {"Indigo", 0x6A00FF},
    {"Violet", 0xAA00FF},
    {"Pink", 0xF472D0},
    {"Magenta", 0xD80073},
    {"Crimson", 0xA20025},
    {"Red", 0xE51400},
    {"Orange", 0xFA6800},
    {"Amber", 0xF0A30A},
    {"Yellow", 0xE3C800},
    {"Brown", 0x825A2C},
    {"Olive", 0x6D8764},
    {"Steel", 0x647687},
    {"Mauve", 0x76608A},
    {"Taupe", 0x87794E},
};


lv_obj_t *cm_create_text(lv_obj_t *parent, const char *text)
{
    lv_obj_t *ui_cm_label = lv_label_create(parent);
    lv_obj_set_width(ui_cm_label, 280);
    lv_obj_set_height(ui_cm_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_cm_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_cm_label, text);
    lv_obj_set_style_text_font(ui_cm_label, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    return ui_cm_label;
}


void ui_event_switch_text(lv_event_t *e)
{
    lv_obj_t *label = (lv_obj_t *)lv_event_get_user_data(e);
    lv_obj_t *target = lv_event_get_target(e);
    _ui_checked_set_text_value(label, target, "On", "Off");
}

lv_obj_t *cm_create_switch(lv_obj_t *parent, const char *text, bool active, void (*callback)(lv_event_t *e))
{
    lv_obj_t *ui_cm_panel = lv_obj_create(parent);
    lv_obj_set_width(ui_cm_panel, 280);
    lv_obj_set_height(ui_cm_panel, LV_SIZE_CONTENT); /// 50
    lv_obj_set_align(ui_cm_panel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_cm_panel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_cm_panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_cm_panel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_cm_switch = lv_switch_create(ui_cm_panel);
    lv_obj_set_width(ui_cm_switch, 50);
    lv_obj_set_height(ui_cm_switch, 25);
    lv_obj_set_align(ui_cm_switch, LV_ALIGN_CENTER);
    if (active)
    {
        lv_obj_add_state(ui_cm_switch, LV_STATE_CHECKED);
    }
    lv_obj_set_style_bg_color(ui_cm_switch, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_switch, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_cm_switch, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_cm_switch, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_switch, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_cm_switch, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_cm_switch, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_cm_switch, 1, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_t *ui_cm_label = lv_label_create(ui_cm_panel);
    lv_obj_set_width(ui_cm_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_cm_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_cm_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_cm_label, text);
    lv_obj_set_style_text_font(ui_cm_label, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_cm_switch, callback, LV_EVENT_VALUE_CHANGED, NULL);

    return ui_cm_switch;
}

lv_obj_t *cm_create_button(lv_obj_t *parent, const char *text)
{
    lv_obj_t *ui_cm_button = lv_btn_create(parent);
    lv_obj_set_width(ui_cm_button, LV_SIZE_CONTENT);  /// 100
    lv_obj_set_height(ui_cm_button, LV_SIZE_CONTENT); /// 50
    lv_obj_set_align(ui_cm_button, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_cm_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_cm_button, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_cm_button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_button, lv_color_hex(0x4A4A4A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_button, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cm_button, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cm_button, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cm_button, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cm_button, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_cm_label = lv_label_create(ui_cm_button);
    lv_obj_set_width(ui_cm_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_cm_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_cm_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_cm_label, text);
    lv_obj_set_style_text_font(ui_cm_label, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    return ui_cm_button;
}

lv_obj_t *cm_create_title(lv_obj_t *parent, const char *text)
{
    lv_obj_t *ui_cm_label = lv_label_create(parent);
    lv_obj_set_width(ui_cm_label, 280);
    lv_obj_set_height(ui_cm_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_cm_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_cm_label, text);
    lv_obj_set_style_text_font(ui_cm_label, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    return ui_cm_label;
}

lv_obj_t *cm_create_text_area(lv_obj_t *parent, const char *placeholder, void (*color)(lv_obj_t *obj))
{
    lv_obj_t *ui_cm_text_area = lv_textarea_create(parent);
    lv_obj_set_width(ui_cm_text_area, 300);
    lv_obj_set_height(ui_cm_text_area, LV_SIZE_CONTENT); /// 70
    lv_obj_set_x(ui_cm_text_area, 0);
    lv_obj_set_y(ui_cm_text_area, -145);
    lv_obj_set_align(ui_cm_text_area, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_cm_text_area, placeholder);
    lv_obj_set_style_radius(ui_cm_text_area, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_text_area, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_text_area, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_cm_text_area, lv_color_hex(0x70A2EF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_cm_text_area, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_cm_text_area, lv_color_hex(0x70A2EF), LV_PART_MAIN| LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_cm_text_area, 250, LV_PART_MAIN| LV_STATE_FOCUSED);

    lv_obj_set_style_text_color(ui_cm_text_area, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    

    color(ui_cm_text_area);

    
    lv_obj_add_event_cb(ui_cm_text_area, ui_event_textarea, LV_EVENT_ALL, NULL);

    return ui_cm_text_area;
}

lv_obj_t *cm_create_slider(lv_obj_t *parent, int value, int min, int max, void (*callback)(lv_event_t *e))
{
    lv_obj_t *ui_cm_slider = lv_slider_create(parent);
    lv_slider_set_range(ui_cm_slider, min, max);
    lv_slider_set_value(ui_cm_slider, value, LV_ANIM_OFF);
    if (lv_slider_get_mode(ui_cm_slider) == LV_SLIDER_MODE_RANGE)
        lv_slider_set_left_value(ui_cm_slider, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_cm_slider, 270);
    lv_obj_set_height(ui_cm_slider, 2);
    lv_obj_set_align(ui_cm_slider, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_cm_slider, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_slider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_cm_slider, 10, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_cm_slider, callback, LV_EVENT_VALUE_CHANGED, NULL);

    return ui_cm_slider;
}

lv_obj_t *cm_create_panel_space(lv_obj_t *parent, int height)
{
    lv_obj_t *ui_cm_panel = lv_obj_create(parent);
    lv_obj_set_width(ui_cm_panel, 280);
    lv_obj_set_height(ui_cm_panel, height);
    lv_obj_set_align(ui_cm_panel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_cm_panel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_cm_panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_cm_panel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    return ui_cm_panel;
}

lv_obj_t *cm_create_bar(lv_obj_t *parent, int value, const char *format)
{
    lv_obj_t *ui_cm_panel = lv_obj_create(parent);
    lv_obj_set_width(ui_cm_panel, 280);
    lv_obj_set_height(ui_cm_panel, LV_SIZE_CONTENT); /// 50
    lv_obj_set_align(ui_cm_panel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_cm_panel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_cm_panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_cm_panel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_label = lv_label_create(ui_cm_panel);
    lv_obj_set_width(ui_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_label, LV_ALIGN_CENTER);
    lv_label_set_text_fmt(ui_label, format, value);
    lv_obj_set_style_text_font(ui_label, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_label, -5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_bar = lv_bar_create(ui_cm_panel);
    lv_bar_set_value(ui_bar, value, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_bar, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_bar, 270);
    lv_obj_set_height(ui_bar, 7);
    lv_obj_set_align(ui_bar, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_bar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bar, lv_color_hex(0x3F3F3F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_bar, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    return ui_cm_panel;
}

void cm_set_bar(lv_obj_t *obj, int value, const char *format)
{
    uint32_t ch = lv_obj_get_child_cnt(obj);
    lv_obj_t *t = lv_obj_get_child(obj, 0);
    lv_obj_t *b = lv_obj_get_child(obj, 1);
    lv_bar_set_value(b, value, LV_ANIM_OFF);
    lv_label_set_text_fmt(t, format, value);
}

lv_obj_t *cm_create_dropdown(lv_obj_t *parent, const char *options, int selected, int width, void (*callback)(lv_event_t *e))
{
    lv_obj_t *ui_cm_dropdown = lv_dropdown_create(parent);
    lv_dropdown_set_options(ui_cm_dropdown, options);
    lv_dropdown_set_selected(ui_cm_dropdown, selected);
    lv_obj_set_width(ui_cm_dropdown, width);
    lv_obj_set_height(ui_cm_dropdown, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_cm_dropdown, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_cm_dropdown, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_set_style_radius(ui_cm_dropdown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_dropdown, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_dropdown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_cm_dropdown, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_cm_dropdown, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_dropdown, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(lv_dropdown_get_list(ui_cm_dropdown), 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(lv_dropdown_get_list(ui_cm_dropdown), lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_dropdown_get_list(ui_cm_dropdown), 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_cm_dropdown, callback, LV_EVENT_VALUE_CHANGED, NULL);

    return ui_cm_dropdown;
}


void cm_ir_tile(lv_obj_t *parent){
    lv_obj_t *ui_cm_panel = lv_obj_create(parent);
    lv_obj_set_width(ui_cm_panel, 35);
    lv_obj_set_height(ui_cm_panel, 35);
    lv_obj_set_align(ui_cm_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_cm_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_panel, lv_color_hex(0xAAAAAA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}
void cm_user_list(lv_obj_t *parent, user_info_t user)
{
    lv_obj_t *ui_cm_user = lv_label_create(parent);
    lv_obj_set_width(ui_cm_user, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_cm_user, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_cm_user, LV_ALIGN_CENTER);
    lv_label_set_text(ui_cm_user, user.username);
    lv_obj_add_flag(ui_cm_user, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_text_font(ui_cm_user, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_cm_user, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_cm_user, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_cm_user, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_user, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cm_user, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cm_user, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cm_user, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cm_user, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_user, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_cm_user, 150, LV_PART_MAIN | LV_STATE_PRESSED);
}

lv_obj_t * cm_quick_action(lv_obj_t *parent, quick_action action, void (*callback)(lv_event_t *e))
{
    lv_obj_t *ui_cm_button = lv_btn_create(parent);
    lv_obj_set_width(ui_cm_button, 58);
    lv_obj_set_height(ui_cm_button, 40);
    lv_obj_set_x(ui_cm_button, -56);
    lv_obj_set_y(ui_cm_button, -23);
    lv_obj_set_align(ui_cm_button, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_cm_button, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_cm_button, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_cm_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    if (action.checkable)
    {
        lv_obj_add_flag(ui_cm_button, LV_OBJ_FLAG_CHECKABLE); /// Flags
    }
    lv_obj_add_state(ui_cm_button, LV_STATE_CHECKED);
    lv_obj_clear_flag(ui_cm_button, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_cm_button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cm_button, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cm_button, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cm_button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cm_button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_cm_button, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_cm_button, lv_color_hex(0x444444), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_cm_button, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_cm_button, 0, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_t *ui_cm_image = lv_img_create(ui_cm_button);
    lv_img_set_src(ui_cm_image, action.icon);
    lv_obj_set_width(ui_cm_image, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_cm_image, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_cm_image, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_cm_image, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_cm_image, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    lv_obj_t *ui_Label30 = lv_label_create(ui_cm_button);
    lv_obj_set_width(ui_Label30, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label30, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label30, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label30, action.name);
    lv_obj_set_style_text_font(ui_Label30, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_cm_button, callback, action.checkable ? LV_EVENT_VALUE_CHANGED : LV_EVENT_CLICKED, (void *)action.code);

    return ui_cm_button;
}

void cm_start_tile(start_tile_t tile, void (*callback)(live_obj_t l), void (*launcher)(lv_event_t *e), void (*start)(lv_obj_t *obj))
{
    lv_obj_t *ui_cm_panel = lv_obj_create(ui_startPanel);
    lv_obj_set_width(ui_cm_panel, tile.wide ? 205 : 100);
    lv_obj_set_height(ui_cm_panel, 76);
    lv_obj_set_align(ui_cm_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_cm_panel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_panel, lv_color_hex(0x136DC8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_panel, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_cm_panel, tile.app.icon, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_cm_label = lv_label_create(ui_cm_panel);
    lv_obj_set_width(ui_cm_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_cm_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_cm_label, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_long_mode(ui_cm_label, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_cm_label, tile.app.name);
    lv_obj_set_style_text_font(ui_cm_label, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cm_label, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cm_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cm_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cm_label, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    if (tile.dir != CM_LIVE_NONE && tile.live != NULL)
    {
        lv_obj_t *ui_cm_image = lv_img_create(ui_cm_panel);
        lv_img_set_src(ui_cm_image, tile.live);
        lv_obj_set_width(ui_cm_image, LV_SIZE_CONTENT);  /// 1
        lv_obj_set_height(ui_cm_image, LV_SIZE_CONTENT); /// 1
        lv_obj_set_x(ui_cm_image, tile.dir == CM_LIVE_VERTICAL ? 0 : 100);
        lv_obj_set_y(ui_cm_image, tile.dir == CM_LIVE_VERTICAL ? 76 : 0);
        lv_obj_set_align(ui_cm_image, tile.dir == CM_LIVE_VERTICAL ? LV_ALIGN_TOP_MID : LV_ALIGN_LEFT_MID);
        lv_obj_add_flag(ui_cm_image, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
        lv_obj_clear_flag(ui_cm_image, LV_OBJ_FLAG_SCROLLABLE); /// Flags
        live_obj_t t = {ui_cm_image, tile.dir};
        callback(t);
    }

    start(ui_cm_panel);

    lv_obj_add_event_cb(ui_cm_panel, launcher, LV_EVENT_CLICKED, (void *)tile.app.code);
}

void cm_app_list(app_info_t app, void (*launcher)(lv_event_t *e), void (*panel)(lv_obj_t *obj))
{
    lv_obj_t *ui_cm_panel = lv_obj_create(ui_appsListPanel);
    lv_obj_set_width(ui_cm_panel, 320);
    lv_obj_set_height(ui_cm_panel, 50);
    lv_obj_set_align(ui_cm_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_cm_panel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_cm_panel_icon = lv_obj_create(ui_cm_panel);
    lv_obj_set_width(ui_cm_panel_icon, 50);
    lv_obj_set_height(ui_cm_panel_icon, 50);
    lv_obj_set_align(ui_cm_panel_icon, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_cm_panel_icon, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_cm_panel_icon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_panel_icon, lv_color_hex(0x1390EA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_panel_icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_cm_panel_icon, app.icon, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_panel_icon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_cm_label = lv_label_create(ui_cm_panel);
    lv_obj_set_width(ui_cm_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_cm_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_cm_label, 65);
    lv_obj_set_y(ui_cm_label, 0);
    lv_obj_set_align(ui_cm_label, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_cm_label, app.name);
    lv_obj_set_style_text_font(ui_cm_label, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    panel(ui_cm_panel_icon);

    lv_obj_add_event_cb(ui_cm_panel, launcher, LV_EVENT_CLICKED, (void *)app.code);
}

void cm_settings_list(lv_obj_t *parent, settings_info_t setting, void (*launcher)(lv_event_t *e), void (*img)(lv_obj_t *obj))
{
    lv_obj_t *ui_cm_panel = lv_obj_create(parent);
    lv_obj_set_width(ui_cm_panel, 320);
    lv_obj_set_height(ui_cm_panel, 50);
    lv_obj_set_align(ui_cm_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_cm_panel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_cm_icon = lv_img_create(ui_cm_panel);
    lv_img_set_src(ui_cm_icon, setting.icon);
    lv_obj_set_width(ui_cm_icon, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_cm_icon, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_cm_icon, 5);
    lv_obj_set_y(ui_cm_icon, 0);
    lv_obj_set_align(ui_cm_icon, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_cm_icon, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_cm_icon, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_img_recolor(ui_cm_icon, lv_color_hex(0x2D87E1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_cm_icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_cm_title = lv_label_create(ui_cm_panel);
    lv_obj_set_width(ui_cm_title, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_cm_title, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_cm_title, 50);
    lv_obj_set_y(ui_cm_title, -12);
    lv_obj_set_align(ui_cm_title, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_cm_title, setting.title);
    lv_obj_set_style_text_font(ui_cm_title, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_cm_info = lv_label_create(ui_cm_panel);
    lv_obj_set_width(ui_cm_info, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_cm_info, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_cm_info, 50);
    lv_obj_set_y(ui_cm_info, 10);
    lv_obj_set_align(ui_cm_info, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_cm_info, setting.desc);
    lv_obj_set_style_text_font(ui_cm_info, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    img(ui_cm_icon);

    lv_obj_add_event_cb(ui_cm_panel, launcher, LV_EVENT_CLICKED, (void *)setting.code);
}

void cm_accent_color(lv_obj_t *parent, accent_color_t color, void (*callback)(lv_event_t *e))
{
    lv_obj_t *ui_cm_color = lv_obj_create(parent);
    lv_obj_set_width(ui_cm_color, 50);
    lv_obj_set_height(ui_cm_color, 50);
    lv_obj_set_align(ui_cm_color, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_cm_color, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_cm_color, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_color, lv_color_hex(color.color), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_color, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_color, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_cm_color, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_color(ui_cm_color, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_opa(ui_cm_color, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_width(ui_cm_color, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_pad(ui_cm_color, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_add_event_cb(ui_cm_color, callback, LV_EVENT_CLICKED, (void *)(uint64_t)color.color);
}

void cm_image_select(lv_obj_t *parent, const lv_img_dsc_t *img, uint64_t index, void (*callback)(lv_event_t *e))
{
    lv_obj_t *ui_cm_panel = lv_obj_create(parent);
    lv_obj_set_width(ui_cm_panel, 50);
    lv_obj_set_height(ui_cm_panel, 100);
    lv_obj_set_x(ui_cm_panel, 0);
    lv_obj_set_y(ui_cm_panel, 32);
    lv_obj_set_align(ui_cm_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_cm_panel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cm_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cm_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_color(ui_cm_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_opa(ui_cm_panel, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_width(ui_cm_panel, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_pad(ui_cm_panel, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_t *ui_cm_image = lv_img_create(ui_cm_panel);
    lv_img_set_src(ui_cm_image, img);
    lv_obj_set_width(ui_cm_image, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_cm_image, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_cm_image, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_cm_image, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_cm_image, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_img_set_zoom(ui_cm_image, 50);

    lv_obj_add_event_cb(ui_cm_panel, callback, LV_EVENT_CLICKED, (void *)index);
}

void set_parent(lv_obj_t *parent)
{
    lv_obj_set_parent(ui_cortanaPanel, parent);
    lv_obj_set_parent(wifi_dialog_panel, parent);
    lv_obj_set_parent(ui_systemKeyboard, parent);
    lv_obj_set_parent(ui_navPanel, parent);
    lv_obj_set_parent(ui_lockScreenPanel, parent);
    lv_obj_set_parent(ui_notificationPanel, parent);
    lv_obj_set_parent(ui_statusPanel, parent);
    lv_obj_set_parent(ui_alertPanel, parent);
}


void cm_create_app_title(lv_obj_t *parent, const char * title, const lv_img_dsc_t *image){
    lv_obj_t *ui_appTitlePanel = lv_obj_create(parent);
    lv_obj_set_width(ui_appTitlePanel, 320);
    lv_obj_set_height(ui_appTitlePanel, 70);
    lv_obj_set_align(ui_appTitlePanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_appTitlePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_appTitlePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_appTitlePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_appTitleName = lv_label_create(ui_appTitlePanel);
    lv_obj_set_width(ui_appTitleName, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_appTitleName, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_appTitleName, 52);
    lv_obj_set_y(ui_appTitleName, 10);
    lv_obj_set_align(ui_appTitleName, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_appTitleName, title);
    lv_obj_set_style_text_font(ui_appTitleName, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_appTitleIcon = lv_img_create(ui_appTitlePanel);
    lv_img_set_src(ui_appTitleIcon, image);
    lv_obj_set_width(ui_appTitleIcon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_appTitleIcon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_appTitleIcon, 10);
    lv_obj_set_y(ui_appTitleIcon, 10);
    lv_obj_set_align(ui_appTitleIcon, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_appTitleIcon, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_appTitleIcon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_img_recolor(ui_appTitleIcon, lv_color_hex(0x2062E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_img_recolor_opa(ui_appTitleIcon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
}


void add_wifi_list(lv_obj_t *parent, wifi_info_t wifi)
{
    lv_obj_t *ui_wifiPanel = lv_obj_create(parent);
    lv_obj_set_width( ui_wifiPanel, 280);
    lv_obj_set_height( ui_wifiPanel, LV_SIZE_CONTENT);   /// 50
    lv_obj_set_align( ui_wifiPanel, LV_ALIGN_CENTER );
    lv_obj_remove_flag( ui_wifiPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_radius(ui_wifiPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wifiPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_opa(ui_wifiPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wifiPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_wifiPanel, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_wifiPanel, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_wifiPanel, 7, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_wifiPanel, 7, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wifiPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
    lv_obj_set_style_bg_opa(ui_wifiPanel, 50, LV_PART_MAIN| LV_STATE_PRESSED);

    lv_obj_t *ui_wifiIcon = lv_image_create(ui_wifiPanel);
    lv_image_set_src(ui_wifiIcon, &ui_img_wifi_icon_png);
    lv_obj_set_width( ui_wifiIcon, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_wifiIcon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align( ui_wifiIcon, LV_ALIGN_LEFT_MID );
    lv_obj_add_flag( ui_wifiIcon, LV_OBJ_FLAG_CLICKABLE );   /// Flags
    lv_obj_remove_flag( ui_wifiIcon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_image_recolor(ui_wifiIcon, lv_color_hex(0x000000), LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(ui_wifiIcon, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

    lv_obj_t *ui_wifiName = lv_label_create(ui_wifiPanel);
    lv_obj_set_width( ui_wifiName, 197);
    lv_obj_set_height( ui_wifiName, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_wifiName, 35 );
    lv_obj_set_y( ui_wifiName, 0 );
    lv_obj_set_align( ui_wifiName, LV_ALIGN_LEFT_MID );
    lv_label_set_long_mode(ui_wifiName,LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_wifiName, wifi.name);
    lv_obj_set_style_text_font(ui_wifiName, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

    lv_obj_t *ui_wifiSecure = lv_image_create(ui_wifiPanel);
    lv_image_set_src(ui_wifiSecure, &ui_img_padlock_png);
    lv_obj_set_width( ui_wifiSecure, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_wifiSecure, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align( ui_wifiSecure, LV_ALIGN_RIGHT_MID );
    lv_obj_add_flag( ui_wifiSecure, LV_OBJ_FLAG_CLICKABLE );   /// Flags
    lv_obj_remove_flag( ui_wifiSecure, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    if (!wifi.secure){
        lv_obj_add_flag( ui_wifiSecure, LV_OBJ_FLAG_HIDDEN );
    }

    lv_obj_add_event_cb(ui_wifiPanel, ui_event_wifi_item_click, LV_EVENT_CLICKED, NULL);

}