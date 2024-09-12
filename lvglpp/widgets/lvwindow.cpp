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

LvBaseObject *LvWindow::addTitle(const char *txt)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Window was not created!";
        return nullptr;
    }
    LvObj *baseType = lv_win_add_title(mLvObj, txt);
    LvBaseObject *title = new LvBaseObject();
    title->setLvObject(baseType);

    return title;
}

LvBaseObject *LvWindow::addButton(const void *icon, const int32_t &btnWidth)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Window was not created!";
        return nullptr;
    }
    LvObj *baseType = lv_win_add_button(mLvObj, icon, btnWidth);
    LvBaseObject *btn = new LvBaseObject();
    btn->setLvObject(baseType);

    return btn;
}

LvBaseObject *LvWindow::getHeader() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Window was not created!";
        return nullptr;
    }
    LvObj *baseType = lv_win_get_header(mLvObj);
    LvBaseObject *header = new LvBaseObject();
    header->setLvObject(baseType);

    return header;
}

LvBaseObject *LvWindow::getContent() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Window was not created!";
        return nullptr;
    }
    LvObj *baseType = lv_win_get_content(mLvObj);
    LvBaseObject *content = new LvBaseObject();
    content->setLvObject(baseType);

    return content;
}
