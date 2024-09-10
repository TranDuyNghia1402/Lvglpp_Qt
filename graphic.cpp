#include "graphic.h"
#include <QDebug>

Graphic::Graphic()
{
    lvTickTimer = new QTimer();
    lvTimeTimer = new QTimer();

    lvTickTimer->setSingleShot(false);
    lvTimeTimer->setSingleShot(false);

    connect(lvTickTimer, &QTimer::timeout, this, &Graphic::onLvTickHandler);
    connect(lvTimeTimer, &QTimer::timeout, this, &Graphic::onLvTimerHandler);

    lvTickTimer->start(5);
    lvTimeTimer->start(5);

    halInit();

    drawSomething();
}

void Graphic::halInit()
{
    lv_init();
    lv_sdl_window_create(MONITOR_WIDTH, MONITOR_HEIGHT);
}

void Graphic::drawSomething()
{
//    LvCurrentActScreen::init();
//    LvCurrentActScreen::setScreenColor(LvColorBlack(), LV_PART_MAIN);

//    LV_IMAGE_DECLARE(bg_map);
//    LvImage *backgroundImage = new LvImage();
//    backgroundImage->create();
//    backgroundImage->setSource(&bg_map);
//    backgroundImage->center();

    LV_IMAGE_DECLARE(bg);
    lv_obj_t * img1 = lv_image_create(lv_screen_active());
    lv_image_set_src(img1, &bg);
    lv_obj_set_scrollbar_mode(img1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_center(img1);

    lv_obj_t * img2 = lv_image_create(lv_screen_active());
    lv_image_set_src(img2, LV_SYMBOL_OK "Accept");
    lv_obj_align_to(img2, img1, LV_ALIGN_CENTER, 0, 20);
    lv_obj_set_scrollbar_mode(img2, LV_SCROLLBAR_MODE_OFF);

}

void Graphic::onLvTickHandler()
{
    lv_tick_inc(5);
}

void Graphic::onLvTimerHandler()
{
    lv_timer_handler();
}
