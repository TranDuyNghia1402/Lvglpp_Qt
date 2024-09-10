#include "graphic.h"
#include <QDebug>

Graphic::Graphic()
{
    lvTickTimer = new QTimer();
    lvTimeTimer = new QTimer();

    autoPressTimer = new QTimer();

    lvTickTimer->setSingleShot(false);
    lvTimeTimer->setSingleShot(false);
    autoPressTimer->setSingleShot(false);

    connect(lvTickTimer, &QTimer::timeout, this, &Graphic::onLvTickHandler);
    connect(lvTimeTimer, &QTimer::timeout, this, &Graphic::onLvTimerHandler);
    connect(autoPressTimer, &QTimer::timeout, this, &Graphic::onAutoPressTimerHandler);

    lvTickTimer->start(5);
    lvTimeTimer->start(5);

    halInit();

    drawSomething();

    autoPressTimer->start(1000);
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

    LV_IMAGE_DECLARE(bg);
    backGround = new LvImage(LvCurrentActScreen::getActiveScreen(), &bg);
    backGround->create();
    backGround->setOpa(LV_OPA_100);

    base = new LvBaseObject(backGround, 500, 500);
    base->create();
    base->center();
    base->setScrollBarMode(ScrollBarMode::OFF);
    base->setBgColor(LvColorHex(0xffccaa));
    base->setPadAll(5);

    tabview = new LvTabview(base);
    tabview->create();
    tabview->align(LV_ALIGN_TOP_LEFT, 0, 50);
    tabview->setSize(400, 350);

    LvBaseObject *tab1 = tabview->addTab("Tab 1");
    LvBaseObject *tab2 = tabview->addTab("Tab 2");
    LvBaseObject *tab3 = tabview->addTab("Tab 3");

    LvLabel *labelOfTab1 = new LvLabel(tab1, "This is the first tab!");
    labelOfTab1->create();
    LvLabel *labelOfTab2 = new LvLabel(tab2, "This is the second tab!");
    labelOfTab2->create();
    LvLabel *labelOfTab3 = new LvLabel(tab3, "This is the third tab!");
    labelOfTab3->create();

    tab1Button = new LvButton(base, 75, 50, "Button 1");
    tab1->setBgColor(lv_color_black(), LV_PART_SELECTED);
    tab1Button->create();
    tab1Button->setAlign(LV_ALIGN_TOP_RIGHT);

    tab2Button = new LvButton(base, 75, 50, "Button 2");
    tab2Button->create();
    tab2Button->setAlignTo(tab1Button, LV_ALIGN_OUT_BOTTOM_MID, 0, 50);

    tab3Button = new LvButton(base, 75, 50, "Button 3");
    tab3Button->create();
    tab3Button->setAlignTo(tab2Button, LV_ALIGN_OUT_BOTTOM_MID, 0, 50);

    connect(tab1Button, &LvButton::pressed, this, &Graphic::onButton1Pressed);
    connect(tab2Button, &LvButton::pressed, this, &Graphic::onButton2Pressed);
    connect(tab3Button, &LvButton::pressed, this, &Graphic::onButton3Pressed);

    scale = new LvScale(base);
    scale->create();
    scale->setSize(350, 30);
    scale->setRange(-100, 100);
    scale->setTotalTickCount(21);
    scale->align(LV_ALIGN_BOTTOM_LEFT, 15, 0);
}

void Graphic::onLvTickHandler()
{
    lv_tick_inc(5);
}

void Graphic::onLvTimerHandler()
{
    lv_timer_handler();
}

void Graphic::onButton1Pressed()
{
    tabview->setActive(0);
}

void Graphic::onButton2Pressed()
{
    tabview->setActive(1);
}

void Graphic::onButton3Pressed()
{
    tabview->setActive(2);
}

void Graphic::onAutoPressTimerHandler()
{
    static uint8_t btnPressedIdx = 0;
    btnPressedIdx++;
    if (btnPressedIdx == 3)  btnPressedIdx = 0;
    switch (btnPressedIdx)
    {
        case 0:
            tab1Button->press();
            break;
        case 1:
            tab2Button->press();
            break;
        case 2:
            tab3Button->press();
            break;
    }
}
