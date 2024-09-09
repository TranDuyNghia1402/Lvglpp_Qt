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
    LvCurrentActScreen::init();
    LvCurrentActScreen::setScreenColor(lv_color_black(), LV_PART_MAIN);

    LvBaseObject *firstObject = new LvBaseObject(LvCurrentActScreen::getActiveScreen());
    firstObject->setSize(500, 500);
    firstObject->center();

    LvBaseObject *secondObject = new LvBaseObject(firstObject);
    secondObject->setSize(100, 100);
    secondObject->setOVerflowVisible(true);
    secondObject->setX(200);

    LvBaseObject *thirdObject = new LvBaseObject(firstObject);
    thirdObject->setSize(50, 50);
    thirdObject->setAlignTo(secondObject, LV_ALIGN_OUT_BOTTOM_MID, 20, 20);

    LvBaseObject *fouthObject = new LvBaseObject(secondObject, 30, 30);
    fouthObject->align(LV_ALIGN_BOTTOM_LEFT, 20, 30);
}

void Graphic::onLvTickHandler()
{
    lv_tick_inc(5);
}

void Graphic::onLvTimerHandler()
{
    lv_timer_handler();
}
