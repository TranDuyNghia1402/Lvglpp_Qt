#include "lvslider.h"

LvSlider::LvSlider(LvBaseObject *parent) { }

void LvSlider::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_slider_create(mParent->getLvObject());
    else
        mLvObj = lv_slider_create(lv_screen_active());
}
