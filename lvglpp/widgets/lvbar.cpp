#include "lvbar.h"

LvBar::LvBar(LvBaseObject *parent) : LvBaseObject(parent) { }

void LvBar::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_bar_create(mParent->getLvObject());
    else
        mLvObj = lv_bar_create(lv_screen_active());
}
