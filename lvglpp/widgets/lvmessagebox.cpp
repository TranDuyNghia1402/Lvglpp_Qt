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

LvBaseObject *LvMessageBox::addTitle(const char *title)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return nullptr;
    }
    LvObj *baseType = lv_msgbox_add_title(mLvObj, title);
    LvBaseObject *titleObj = new LvBaseObject();
    titleObj->setLvObject(baseType);

    return titleObj;
}

LvBaseObject *LvMessageBox::addHeaderButton(const void *icon)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return nullptr;
    }
    LvObj *baseType = lv_msgbox_add_header_button(mLvObj, icon);
    LvBaseObject *button = new LvBaseObject();
    button->setLvObject(baseType);

    return button;
}

LvBaseObject *LvMessageBox::addText(const char *text)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return nullptr;
    }
    LvObj* baseType = lv_msgbox_add_text(mLvObj, text);
    LvBaseObject *button = new LvBaseObject();
    button->setLvObject(baseType);

    return button;
}

LvBaseObject *LvMessageBox::addFooterButton(const char *text)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return nullptr;
    }
    LvObj* baseType = lv_msgbox_add_footer_button(mLvObj, text);
    LvBaseObject *button = new LvBaseObject();
    button->setLvObject(baseType);

    return button;
}
