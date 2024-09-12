#include "lvroller.h"

LvRoller::LvRoller(LvBaseObject *parent) : LvBaseObject(parent) { }

void LvRoller::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_roller_create(mParent->getLvObject());
    else
        mLvObj = lv_roller_create(lv_screen_active());
}
