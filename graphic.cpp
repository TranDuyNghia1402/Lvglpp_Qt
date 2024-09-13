#include "graphic.h"
#include <QDebug>

#define BG_COLOR    0x181818
#define GUI_COLOR   0x00E8E8

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
//    csdspSimulator();
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

    static LvObjectStyle tabviewStyle;
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

    static LvObjectStyle labelStyle;
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

    button = new LvButton(base, 75, 50, "Next");
    button->create();
    button->align(LV_ALIGN_TOP_RIGHT, 0, 50);

    spinbox = new LvSpinbox(base);
    spinbox->create();
    spinbox->setWidth(80);
    spinbox->setDigitFormat(3, 3);
    spinbox->setRollOver(true);
    spinbox->setRange(-100, 200);
    spinbox->setAlignTo(button, LV_ALIGN_OUT_BOTTOM_MID, 0, 50);

    const char *option = "January\n"
                         "February\n"
                         "March\n"
                         "April\n"
                         "May\n"
                         "June\n"
                         "July\n"
                         "August\n"
                         "September\n"
                         "October\n"
                         "November\n"
                         "December";
    roller = new LvRoller(base);
    roller->create();
    roller->setOption(option, LV_ROLLER_MODE_INFINITE);
    roller->setVisibleRows(3);
    roller->setSize(80, 70);
    roller->setRadius(0);
    roller->setAlignTo(spinbox, LV_ALIGN_OUT_BOTTOM_MID, 0, 50);

    LvList *list = new LvList(tab1);
    list->create();
    list->align(LV_ALIGN_CENTER, 0, 20);
    list->setHeight(280);
    list->setBgColor(lv_palette_darken(LV_PALETTE_GREY, 3));
    list->setTextColor(lv_color_hex(0xffccaa));
    list->setBorderColor(lv_color_hex(0xffccaa));

    LvDropDownList *dropdown = new LvDropDownList(tab2);
    dropdown->create();
    dropdown->align(LV_ALIGN_CENTER, 0, 20);
    dropdown->setOptions("Apple\n"
                         "Banana\n"
                         "Orange\n"
                         "Cherry\n"
                         "Grape\n"
                         "Raspberry\n"
                         "Melon\n"
                         "Orange\n"
                         "Lemon\n"
                         "Nuts");

    static LvObjectStyle listButtonStyle;
    listButtonStyle.setBgColor(lv_palette_lighten(LV_PALETTE_RED, 2));
    listButtonStyle.setHeight(30);

    LvBaseObject * listText = list->addText("Files");
    listText->setBgColor(lv_color_hex(0xffccaa));
    LvBaseObject *listButton = new LvBaseObject();
    listButton = list->addButton(LV_SYMBOL_FILE, "New");
    listButton->addStyle(listButtonStyle);
    listButton = list->addButton(LV_SYMBOL_DIRECTORY, "Open");
    listButton->addStyle(listButtonStyle);
    listButton = list->addButton(LV_SYMBOL_SAVE, "Save");
    listButton->addStyle(listButtonStyle);
    listButton = list->addButton(LV_SYMBOL_CLOSE, "Delete");
    listButton->addStyle(listButtonStyle);

    listText = list->addText("Connectivity");
    listText->setBgColor(lv_color_hex(0xffccaa));
    listButton = list->addButton(LV_SYMBOL_BLUETOOTH, "Bluetooth");
    listButton->addStyle(listButtonStyle);
    listButton = list->addButton(LV_SYMBOL_GPS, "Navigation");
    listButton->addStyle(listButtonStyle);
    listButton = list->addButton(LV_SYMBOL_USB, "USB");
    listButton->addStyle(listButtonStyle);
    listButton = list->addButton(LV_SYMBOL_BATTERY_FULL, "Battery");
    listButton->addStyle(listButtonStyle);

    connect(button, &LvButton::pressed, this, &Graphic::onButton1Pressed);

    scale = new LvScale(base);
    scale->create();
    scale->setSize(350, 30);
    scale->setRange(-100, 100);
    scale->setTotalTickCount(21);
    scale->align(LV_ALIGN_BOTTOM_LEFT, 15, 0);

    bar = new LvBar(base);
    bar->create();
    bar->setAlign(LV_ALIGN_TOP_MID);
    bar->setRange(0, 100);

    autoPressTimer->start(1000);
}

void Graphic::csdspSimulator()
{
    LV_IMAGE_DECLARE(bg);
    backGround = new LvImage(LvCurrentActScreen::getActiveScreen(), &bg);
    backGround->create();

    LvObjectStyle labelStyle;
    labelStyle.setWidth(60);
    labelStyle.setBorderWidth(1);
    labelStyle.setRadius(3);
    labelStyle.setTextAlign(LV_TEXT_ALIGN_CENTER);
    labelStyle.setBorderColor(lv_color_hex(GUI_COLOR));
    labelStyle.setBgOpa(LV_OPA_COVER);
    labelStyle.setBgColor(lv_color_hex(BG_COLOR));
    labelStyle.setTextColor(lv_color_hex(GUI_COLOR));

    LvLabel *lbCameraChannel = new LvLabel(LvCurrentActScreen::getActiveScreen(), "DAY");
    lbCameraChannel->create();
    lbCameraChannel->addStyle(labelStyle);

    LvLabel *lbZoomLevel = new LvLabel(LvCurrentActScreen::getActiveScreen(), "1X");
    lbZoomLevel->create();
    lbZoomLevel->setAlign(LV_ALIGN_TOP_RIGHT);
    lbZoomLevel->addStyle(labelStyle);

    LvLabel *lbLaserResult = new LvLabel(LvCurrentActScreen::getActiveScreen(), "DISTANCE:");
    lbLaserResult->create();
    lbLaserResult->setAlign(LV_ALIGN_TOP_MID);
    lbLaserResult->setWidth(200);
    lbLaserResult->addStyle(labelStyle);
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

void Graphic::onAutoPressTimerHandler()
{
    button->press();
    static int barValue = 0;
    barValue += 10;
    if (barValue > 100) barValue = 0;
    bar->setValue(barValue);
    spinbox->increase();
    roller->next();
}
