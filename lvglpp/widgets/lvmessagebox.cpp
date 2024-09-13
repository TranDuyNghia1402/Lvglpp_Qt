#include "lvmessagebox.h"

LvMessageBox::LvMessageBox(LvBaseObject *parent) : LvBaseObject(parent) { }

void LvMessageBox::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_msgbox_create(mParent->getLvObject());
    else
        mLvObj = lv_msgbox_create(lv_screen_active());
}
