#include "lvdropdownlist.h"

LvDropDownList::LvDropDownList(LvBaseObject *parent) : LvBaseObject(parent) { }

void LvDropDownList::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_dropdown_create(mParent->getLvObject());
    else
        mLvObj = lv_dropdown_create(lv_screen_active());
}

void LvDropDownList::setText(const char *txt)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return;
    }
    lv_dropdown_set_text(mLvObj, txt);
}

void LvDropDownList::setOptions(const char *options)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return;
    }
    lv_dropdown_set_options(mLvObj, options);
}

void LvDropDownList::setOptionsStatic(const char *options)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return;
    }
    lv_dropdown_set_options_static(mLvObj, options);
}

void LvDropDownList::addOption(const char *option, const uint32_t &pos)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return;
    }
    lv_dropdown_add_option(mLvObj, option, pos);
}

void LvDropDownList::clearOption()
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return;
    }
    lv_dropdown_clear_options(mLvObj);
}

void LvDropDownList::setSelected(const uint32_t &idx)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return;
    }
    lv_dropdown_set_selected(mLvObj, idx);
}

void LvDropDownList::setDir(const LvDir &dir)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return;
    }
    lv_dropdown_set_dir(mLvObj, dir);
}

void LvDropDownList::setSelectedHighlight(const bool &en)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return;
    }
    lv_dropdown_set_selected_highlight(mLvObj, en);
}

LvBaseObject *LvDropDownList::getList() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return nullptr;
    }
    LvObj *baseType = lv_dropdown_get_list(mLvObj);
    LvBaseObject *list = new LvBaseObject();
    list->setLvObject(baseType);

    return list;
}

const char *LvDropDownList::getText() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return nullptr;
    }
    return lv_dropdown_get_text(mLvObj);
}

const char *LvDropDownList::getOption() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return nullptr;
    }
    return lv_dropdown_get_options(mLvObj);
}

uint32_t LvDropDownList::getSelected() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return 0;
    }
    return lv_dropdown_get_selected(mLvObj);
}

uint32_t LvDropDownList::getOptionsCount() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return 0;
    }
    return lv_dropdown_get_option_count(mLvObj);
}

QString LvDropDownList::getSelectedString(const uint32_t &buffSize) const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return "";
    }
    char buff[buffSize];
    lv_dropdown_get_selected_str(mLvObj, buff, buffSize);

    return QString(buff);
}

int32_t LvDropDownList::getOptionIndex(const char *option) const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return -1;
    }
    return lv_dropdown_get_option_index(mLvObj, option);
}

QString LvDropDownList::getSymbol() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return "";
    }
    const char *symbol = lv_dropdown_get_symbol(mLvObj);
    return QString(symbol);
}

bool LvDropDownList::getSelectedHighlight() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return false;
    }
    return lv_dropdown_get_selected_highlight(mLvObj);
}

LvDir LvDropDownList::getDir() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return LV_DIR_NONE;
    }
    return lv_dropdown_get_dir(mLvObj);
}

void LvDropDownList::open()
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return;
    }
    lv_dropdown_open(mLvObj);
}

void LvDropDownList::close()
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return;
    }
    lv_dropdown_close(mLvObj);
}

bool LvDropDownList::isOpen() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] DropDown was not created!";
        return false;
    }
    return lv_dropdown_is_open(mLvObj);
}
