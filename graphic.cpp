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

//    autoPressTimer->start(1000);
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
    base->setBorderWidth(3);
    base->setBorderColor(lv_color_black());

    LvObjectStyle tabviewStyle;
    tabviewStyle.setBorderWidth(2);
    tabviewStyle.setBorderSide(LV_BORDER_SIDE_INTERNAL);

    tabview = new LvTabview(base);
    tabview->create();
    tabview->align(LV_ALIGN_TOP_LEFT, 0, 50);
    tabview->setSize(400, 350);
    tabview->setBgColor(lv_palette_lighten(LV_PALETTE_RED, 2));
    tabview->setTabBarPosition(LV_DIR_LEFT);
    tabview->setTabBarSize(80);
    tabview->setRadius(10);

    LvButtonMaxtrix *tabButtons = (LvButtonMaxtrix*)tabview->getTabBar();
    tabButtons->setBgColor(lv_palette_darken(LV_PALETTE_GREY, 3));
    tabButtons->setTextColor(lv_color_hex(0xffccaa));
    tabButtons->addStyle(tabviewStyle, LV_PART_ITEMS);

    LvBaseObject *tab1 = tabview->addTab("Tab 1");
    LvBaseObject *tab2 = tabview->addTab("Tab 2");
    LvBaseObject *tab3 = tabview->addTab("Tab 3");

    LvObjectStyle labelStyle;
    labelStyle.setBgOpa(LV_OPA_0);
    labelStyle.setBorderWidth(2);
    labelStyle.setRadius(5);
    labelStyle.setBorderColor(lv_color_hex(0xffccaa));
    labelStyle.setTextColor(lv_color_hex(0xffccaa));
    labelStyle.setAlign(LV_ALIGN_TOP_MID);

    LvLabel *labelOfTab1 = new LvLabel(tab1, "This is the first tab!");
    labelOfTab1->create();
    labelOfTab1->addStyle(labelStyle);

    LvLabel *labelOfTab2 = new LvLabel(tab2, "This is the second tab!");
    labelOfTab2->create();
    labelOfTab2->addStyle(labelStyle);

    LvLabel *labelOfTab3 = new LvLabel(tab3, "This is the third tab!");
    labelOfTab3->create();
    labelOfTab3->addStyle(labelStyle);

    tab1Button = new LvButton(base, 75, 50, "Next");
    tab1Button->create();
    tab1Button->align(LV_ALIGN_TOP_RIGHT, 0, 50);

    tab2Button = new LvButton(base, 75, 50, "Button 2");
    tab2Button->create();
    tab2Button->setAlignTo(tab1Button, LV_ALIGN_OUT_BOTTOM_MID, 0, 50);

    tab3Button = new LvButton(base, 75, 50, "Button 3");
    tab3Button->create();
    tab3Button->setAlignTo(tab2Button, LV_ALIGN_OUT_BOTTOM_MID, 0, 50);

    LvList *list = new LvList(tab1);
    list->create();
    list->center();
    list->setHeight(280);
    list->setBgColor(lv_palette_darken(LV_PALETTE_GREY, 3));
    list->setTextColor(lv_color_hex(0xffccaa));
    list->setBorderColor(lv_color_hex(0xffccaa));

    LvObjectStyle listButtonStyle;
    listButtonStyle.setBgColor(lv_palette_lighten(LV_PALETTE_RED, 2));
    listButtonStyle.setHeight(30);

    list->addText("Files");
    LvBaseObject *button = new LvBaseObject();
    button = list->addButton(LV_SYMBOL_FILE, "New");
    button->addStyle(listButtonStyle);
    button = list->addButton(LV_SYMBOL_DIRECTORY, "Open");
    button->addStyle(listButtonStyle);
    button = list->addButton(LV_SYMBOL_SAVE, "Save");
    button->addStyle(listButtonStyle);
    button = list->addButton(LV_SYMBOL_CLOSE, "Delete");
    button->addStyle(listButtonStyle);

    list->addText("Connectivity");
    button = list->addButton(LV_SYMBOL_BLUETOOTH, "Bluetooth");
    button->addStyle(listButtonStyle);
    button = list->addButton(LV_SYMBOL_GPS, "Navigation");
    button->addStyle(listButtonStyle);
    button = list->addButton(LV_SYMBOL_USB, "USB");
    button->addStyle(listButtonStyle);
    button = list->addButton(LV_SYMBOL_BATTERY_FULL, "Battery");
    button->addStyle(listButtonStyle);

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
    tabview->moveToNextTab();
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
    tab1Button->press();
}
