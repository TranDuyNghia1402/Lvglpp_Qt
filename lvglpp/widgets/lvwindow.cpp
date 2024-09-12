#include "lvwindow.h"

LvWindow::LvWindow(LvBaseObject *parent) : LvBaseObject(parent)
{

}

void LvWindow::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_win_create(mParent->getLvObject());
    else
        mLvObj = lv_win_create(lv_screen_active());
}
