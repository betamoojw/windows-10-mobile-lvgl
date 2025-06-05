#pragma once

#include <Arduino.h>

#include "Arduino_GFX_Library.h"
#include "TouchDrvCSTXXX.hpp"


#define LCD_BL 13

#define LCD_IM0 47
#define LCD_IM1 48

class DisplayWrapper
{
public:
    Arduino_GFX *gfx;
    TouchDrvCST816 touch;

    DisplayWrapper()
    {

        static Arduino_DataBus *bus = new Arduino_ESP32SPIDMA(41 /* DC */, 42 /* CS */, 40 /* SCK */, 45 /* MOSI */, GFX_NOT_DEFINED /* MISO */, SPI2_HOST /* spi_num */);

        gfx = new Arduino_ST7789(
            bus, 39 /* RST */, 4 /* rotation */, true /* IPS */,
            320 /* width */, 480 /* height */);
    }

    bool init(void)
    {
        pinMode(LCD_IM0, OUTPUT);
        digitalWrite(LCD_IM0, HIGH);
        pinMode(LCD_IM1, OUTPUT);
        digitalWrite(LCD_IM1, HIGH);

        ledcAttach(LCD_BL, 12000, 8);

        bool state = gfx->begin();
        touch.setPins(2, 4);
        touch.begin(Wire, 0x2E, 1, 3);

        return state;
    }

    void initDMA(void) {}

    void fillScreen(uint16_t color)
    {
        gfx->fillScreen(color);
    }

    void setRotation(uint8_t rotation)
    {
        gfx->setRotation(rotation + 4);
    }

    void pushImageDMA(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t *data)
    {
        int size = w * h;
        for (int i = 0; i < size; i++) {
            uint16_t red = data[i] & 0b0001111100000000;
            uint16_t green = data[i] & 0b1110000000000111;
            uint16_t blue = data[i] & 0b0000000011111000;
            data[i] = (green) | (red >> 5) | (blue << 5);
        }
        gfx->draw16bitBeRGBBitmap(x, y, data, w, h);
    }

    void startWrite(void) {}

    uint32_t getStartCount(void)
    {
        return 0;
    }

    void endWrite(void) {}

    void setBrightness(uint8_t brightness)
    {
        ledcWrite(LCD_BL, brightness);
    }

    void writePixel(int32_t x, int32_t y, const uint16_t color)
    {
        gfx->writePixel(x, y, color);
    }

    bool getTouch(uint16_t *x, uint16_t *y)
    {
        int16_t x_arr[5], y_arr[5];
        uint8_t touched = touch.getPoint(x_arr, y_arr, touch.getSupportTouchPoint());
        *x = x_arr[0];
        *y = y_arr[0];
        return touched;
    }

};

DisplayWrapper tft;
