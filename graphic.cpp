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

    LvBaseObject *firstObject = new LvBaseObject(LvCurrentActScreen::getActiveScreen());

    LvObjectStyle firstObjStyle;
    firstObjStyle.setSize(500, 500);
    firstObjStyle.setBgColor(LvColorBlack());
    firstObjStyle.setBorderWidth(10);
    firstObjStyle.setBorderColor(LvColorHex(0xffaacc));
    firstObjStyle.setAlign(LV_ALIGN_CENTER);

    firstObject->addStyle(firstObjStyle, LV_PART_MAIN);

    LvBaseObject *secondObject = new LvBaseObject(firstObject, 200, 200);
    secondObject->setBgColor(LvColorHex(0xff0000));
    secondObject->setOVerflowVisible(true);
    secondObject->setBorderWidth(0);

    LvBaseObject *thirdObject = new LvBaseObject(firstObject, 200, 200);
    thirdObject->setAlignTo(secondObject, LV_ALIGN_OUT_RIGHT_MID, 50, 0);
    thirdObject->setBgColor(LvColorHex(0x0000ff));
    thirdObject->setBorderWidth(3);
    thirdObject->setBorderColor(LvColorHex(0x00ff00));

    LvBaseObject *fouthObject = new LvBaseObject(secondObject, 100, 100);
    fouthObject->center();

    secondObject->getChilds(0)->setBgColor(LvColorHex(0x00ff00));
    secondObject->getChilds(0)->setSize(50, 50);

    LvBaseObject *fithObject = new LvBaseObject(secondObject, 100, 100);
    fithObject->setBgColor(LvColorBlack());
    fithObject->setY(100);

    fithObject->setParent(thirdObject);
    thirdObject->getChilds(0)->setSize(50, 50);
    thirdObject->getChilds(0)->setBgColor(LvColorHex(0xffccaa));
    thirdObject->getChilds(0)->center();

    fouthObject->setParent(thirdObject);
    thirdObject->getChilds(1)->setAlign(LV_ALIGN_BOTTOM_LEFT);
    thirdObject->getChilds(1)->setBgOpa(LV_OPA_30);

}

void Graphic::onLvTickHandler()
{
    lv_tick_inc(5);
}

void Graphic::onLvTimerHandler()
{
    lv_timer_handler();
}
