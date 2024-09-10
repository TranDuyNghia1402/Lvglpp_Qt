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
    LvCurrentActScreen::setScreenColor(LvColorBlack(), LV_PART_MAIN);

    LvBaseObject *base = new LvBaseObject(LvCurrentActScreen::getActiveScreen(), 500, 500);
    base->create();
    base->center();
    base->setRadius(0);

    LvBaseObject *needle = new LvBaseObject(base, 30, 10);
    needle->create();
    needle->setScrollBarMode(ScrollBarMode::OFF);
    needle->setBgColor(lv_color_black());

    LvLabel *label = new LvLabel(base, "This is a text");
    label->create();
    label->setAlign(LV_ALIGN_TOP_MID);

    LvScale *scale = new LvScale(base, -100, 100);
    scale->create();
    scale->setSize(lv_pct(100), lv_pct(100));
    scale->setTotalTickCount(101);
    scale->setMajorTickEvery(10);
    scale->setMode(LV_SCALE_MODE_VERTICAL_LEFT);
    scale->center();

}

void Graphic::onLvTickHandler()
{
    lv_tick_inc(5);
}

void Graphic::onLvTimerHandler()
{
    lv_timer_handler();
}
