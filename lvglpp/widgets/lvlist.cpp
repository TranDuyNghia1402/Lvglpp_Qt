#include "lvlist.h"

LvList::LvList(LvBaseObject *parent) : LvBaseObject(parent) { }

void LvList::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_list_create(mParent->getLvObject());
    else
        mLvObj = lv_list_create(lv_screen_active());
}

LvBaseObject *LvList::addText(const char *txt)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] List was not created!";
        return nullptr;
    }
    LvObj* baseTypeLabel = lv_list_add_text(mLvObj, txt);
    LvBaseObject *label = new LvBaseObject();
    label->setLvObject(baseTypeLabel);

    return label;
}

LvBaseObject *LvList::addButton(const void *icon, const char *txt)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] List was not created!";
        return nullptr;
    }
    LvObj* baseTypeButton = lv_list_add_button(mLvObj, icon, txt);
    LvBaseObject *btn = new LvBaseObject();
    btn->setLvObject(baseTypeButton);

    return btn;
}

const char *LvList::getButtonText(LvBaseObject *btn) const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] List was not created!";
        return nullptr;
    }
    return lv_list_get_button_text(mLvObj, btn->getLvObject());
}

void LvList::setButtonText(LvBaseObject *button, const char *txt)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] List was not created!";
        return;
    }
    lv_list_set_button_text(mLvObj, button->getLvObject(), txt);
}
