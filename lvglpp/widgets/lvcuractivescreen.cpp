#include "lvcuractivescreen.h"

LvObj *LvCurrentActScreen::mCurrentScreen;
LvBaseObject *LvCurrentActScreen::mCurrentActScreen;

void LvCurrentActScreen::init()
{
    mCurrentScreen = lv_screen_active();

    mCurrentActScreen = new LvBaseObject();
    mCurrentActScreen->setLvObject(mCurrentScreen);
}

LvBaseObject *LvCurrentActScreen::getActiveScreen()
{
    return mCurrentActScreen;
}

void LvCurrentActScreen::setScreenColor(LvColor color, LvSelector selector)
{
    lv_obj_set_style_bg_color(mCurrentScreen, color, selector);
}
