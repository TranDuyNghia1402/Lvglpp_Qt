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

LvBaseObject *LvMessageBox::addCloseButton()
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return nullptr;
    }
    LvObj* baseType = lv_msgbox_add_close_button(mLvObj);
    LvBaseObject *button = new LvBaseObject();
    button->setLvObject(baseType);

    return button;
}

LvBaseObject *LvMessageBox::getHeader() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return nullptr;
    }
    LvObj* baseType = lv_msgbox_get_header(mLvObj);
    LvBaseObject *header = new LvBaseObject();
    header->setLvObject(baseType);

    return header;
}

LvBaseObject *LvMessageBox::getFooter() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return nullptr;
    }
    LvObj* baseType = lv_msgbox_get_footer(mLvObj);
    LvBaseObject *footer = new LvBaseObject();
    footer->setLvObject(baseType);

    return footer;
}

LvBaseObject *LvMessageBox::getContent() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return nullptr;
    }
    LvObj* baseType = lv_msgbox_get_content(mLvObj);
    LvBaseObject *content = new LvBaseObject();
    content->setLvObject(baseType);

    return content;
}

LvBaseObject *LvMessageBox::getTitle() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return nullptr;
    }
    LvObj* baseType = lv_msgbox_get_title(mLvObj);
    LvBaseObject *title = new LvBaseObject();
    title->setLvObject(baseType);

    return title;
}

void LvMessageBox::close()
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return;
    }
    lv_msgbox_close(mLvObj);
}

void LvMessageBox::closeAsync()
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] MessageBox was not created!";
        return;
    }
    lv_msgbox_close_async(mLvObj);
}
