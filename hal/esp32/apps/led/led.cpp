

#include <lvgl.h>
#include "ui/ui.h"

#include "../app_hal.h"
#include "../../core/app_manager.h"

#include <WS2812FX.h>

LV_IMAGE_DECLARE(image_lumia);

#define LED_COUNT 1
#define LED_PIN 0

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

/* app info */
static app_info_t led_info = {
    .code = 0x0000,
    .name = "LED",
    .icon = &image_lumia}; /* App icon recommeded size 32x32 */

/* Start tile info */
static start_tile_t led_tile = {
    .app = led_info,
    .wide = false,
    .live = NULL,
    .dir = CM_LIVE_NONE};

static lv_obj_t *led_app_screen; /* Main screen object */

lv_timer_t *led_loop_timer = NULL;


static void led_launch_event(lv_event_t *e);
static void led_page_events(lv_event_t *e);
static void led_app_screen_init(void);
void register_led_app();
void led_app_timer_cb(lv_timer_t *timer);


static void led_launch_event(lv_event_t *e)
{
    if (!led_app_screen)
    {
        /* Initialize screen */
        led_app_screen_init();
    }

    lv_screen_load_anim(led_app_screen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false);
}

static void led_page_events(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_SCREEN_LOADED)
    {
        set_parent(led_app_screen); /* Set the main components to current screen (Navigation bar, status bar etc)*/
        // Other startup actions goes here

        ws2812fx.init();
        ws2812fx.setBrightness(255);
        ws2812fx.setSpeed(1000);
        ws2812fx.setColor(RED);
        ws2812fx.setMode(FX_MODE_STATIC);
        ws2812fx.start();

        led_loop_timer = lv_timer_create(led_app_timer_cb, 50, NULL);
        lv_timer_set_repeat_count(led_loop_timer, -1);

    }
    if (event_code == LV_EVENT_SCREEN_UNLOADED)
    {
        // Other cleanup actions goes here

        if (led_loop_timer != NULL)
        {
            lv_timer_delete(led_loop_timer);
            led_loop_timer = NULL;
        }

        ws2812fx.stop();


        set_back_handler(NULL); /* Release the back button handler if set prevously */
        /* Delete the screen */
        lv_obj_delete(led_app_screen);
        led_app_screen = NULL;
    }
}

void on_brightness_change(lv_event_t *e)
{
    lv_obj_t *target = (lv_obj_t *)lv_event_get_target(e);
    int32_t value = lv_slider_get_value(target);
    ws2812fx.setBrightness(value);
}

void on_mode_change(lv_event_t *e)
{
    lv_obj_t *obj = (lv_obj_t *)lv_event_get_target(e);
    uint16_t sel = lv_dropdown_get_selected(obj);
    ws2812fx.setMode(sel);
}

void on_speed_change(lv_event_t *e)
{
    lv_obj_t *slider = (lv_obj_t *)lv_event_get_target(e);
    int32_t v = lv_slider_get_value(slider);
    ws2812fx.setSpeed(v);
}

void on_color_change(lv_event_t *e)
{
    uint32_t color = (uint32_t)((uint64_t)lv_event_get_user_data(e));
    ws2812fx.setColor(color);
}

static void led_app_screen_init(void)
{
    led_app_screen = lv_obj_create(NULL);
    lv_obj_remove_flag(led_app_screen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(led_app_screen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(led_app_screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(led_app_screen, led_page_events, LV_EVENT_ALL, NULL);

    /* Add the app top header title if needed */
    cm_create_app_title(led_app_screen, led_info.name, led_info.icon);

    /* Add content as needed */

    lv_obj_t *led_panel = lv_obj_create(led_app_screen);
    lv_obj_set_width(led_panel, 320);
    lv_obj_set_height(led_panel, 410);
    lv_obj_set_x(led_panel, 0);
    lv_obj_set_y(led_panel, 70);
    lv_obj_set_align(led_panel, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(led_panel, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(led_panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_set_scrollbar_mode(led_panel, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(led_panel, LV_DIR_VER);
    lv_obj_set_style_radius(led_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(led_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(led_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(led_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(led_panel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(led_panel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(led_panel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(led_panel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    
    cm_create_text(led_panel, "Brightness");
    cm_create_slider(led_panel, 255, 0, 255, on_brightness_change);

    cm_create_panel_space(led_panel, 5);
    cm_create_text(led_panel, "Speed");
    cm_create_slider(led_panel, 1000, 200, 5000, on_speed_change);

    cm_create_panel_space(led_panel, 5);
    // cm_create_text(led_panel, "Mode");
    lv_obj_t *dropdown = cm_create_dropdown(led_panel, "Static\nBlink", 0, 200, on_mode_change);

    String modes;
    for (int i = 0; i < ws2812fx.getModeCount() - 8; i++)
    {
        String name = ws2812fx.getModeName(i);
        modes += name;
        if (i < ws2812fx.getModeCount() - 9)
        {
        modes += "\n";
        }
    }

    lv_dropdown_set_options(dropdown, modes.c_str());


    lv_obj_t *color_panel = lv_obj_create(led_panel);
    lv_obj_set_width(color_panel, 300);
    lv_obj_set_height(color_panel, LV_SIZE_CONTENT);
    lv_obj_set_align(color_panel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(color_panel, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(color_panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(color_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(color_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(color_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(color_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(color_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(color_panel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    for (int a = 0; a < 15; a++)
    {
        cm_accent_color(color_panel, colors[a], on_color_change);
    }
    cm_create_panel_space(led_panel, 20);

    // lv_obj_t *color_wheel = lv_colorwheel_create(led_panel,true);
    // lv_colorwheel_set_mode_fixed(color_wheel, true);
    // lv_obj_set_width(color_wheel, 200);
    // lv_obj_set_height(color_wheel, 200);
    // lv_obj_set_align(color_wheel, LV_ALIGN_CENTER );
    

}

void led_app_timer_cb(lv_timer_t *timer)
{
    ws2812fx.service();
}


/**
 * This function will be called by the app manager. Here we register/add the app icons in the start and app list
 */
void register_led_app()
{
    /* Add app to the app list and set launch callback */
    cm_app_list(led_info, led_launch_event, register_panel);

    /* Add app tile to the start menu and set launch callback */
    cm_start_tile(led_tile, NULL, led_launch_event, register_start);

}

#ifdef VIEWE
/* Needed for app manager to automatically register the app */
struct LedAppRegister
{
    LedAppRegister()
    {
        AppManager::registerApp(register_led_app); /* Set the function that will be called to register the app */
    }
};

static LedAppRegister led_app;

#endif