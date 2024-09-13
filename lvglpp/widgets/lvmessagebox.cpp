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

void LvMessageBox::addTitle(const char *title)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return;
    }
    lv_msgbox_add_title(mLvObj, title);
}

void LvMessageBox::addHeaderButton(const void *icon)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return;
    }
    lv_msgbox_add_header_button(mLvObj, icon);
}
