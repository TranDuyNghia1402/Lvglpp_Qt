#include "currentactscreen.h"

LvObj *CurrentActScreen::mCurrentActiveScreen;

void CurrentActScreen::init()
{
    mCurrentActiveScreen = lv_screen_active();
}

LvObj *CurrentActScreen::getActiveScreen()
{
    return mCurrentActiveScreen;
}

void CurrentActScreen::setScreenColor(LvColor color, LvSelector selector)
{
    lv_obj_set_style_bg_color(mCurrentActiveScreen, color, selector);
}
