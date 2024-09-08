#include "lvcuractivescreen.h"

LvObj *LvCurrentActScreen::mCurrentActiveScreen;

void LvCurrentActScreen::init()
{
    mCurrentActiveScreen = lv_screen_active();
}

LvObj *LvCurrentActScreen::getActiveScreen()
{
    return mCurrentActiveScreen;
}

void LvCurrentActScreen::setScreenColor(LvColor color, LvSelector selector)
{
    lv_obj_set_style_bg_color(mCurrentActiveScreen, color, selector);
}
