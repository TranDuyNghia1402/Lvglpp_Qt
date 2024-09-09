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

    LvLabel *label = new LvLabel(base, "This is a text");
    label->create();
    label->setAlign(LV_ALIGN_TOP_MID);

    LvLabel *label2 = new LvLabel();
    label2->create();
    label2->setText("This is a text");
    label2->setAlign(LV_ALIGN_TOP_MID);

    LvScale *scale = new LvScale(base, -100, 100);
    scale->create();
    scale->setMode(LV_SCALE_MODE_VERTICAL_LEFT);
    scale->setAlign(LV_ALIGN_BOTTOM_MID);

    LvScale *scale2 = new LvScale();
    scale2->create();
    scale2->setRange(-200, 200);
    scale2->setAlign(LV_ALIGN_TOP_MID);
}

void Graphic::onLvTickHandler()
{
    lv_tick_inc(5);
}

void Graphic::onLvTimerHandler()
{
    lv_timer_handler();
}
