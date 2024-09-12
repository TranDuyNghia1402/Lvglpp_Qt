#include "lvspinbox.h"

LvSpinbox::LvSpinbox(LvBaseObject *parent) : LvBaseObject(parent) { }

void LvSpinbox::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent != nullptr)
        mLvObj = lv_spinbox_create(mParent->getLvObject());
    else
        mLvObj = lv_spinbox_create(lv_screen_active());
}
