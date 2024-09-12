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

void LvRoller::setOption(const char *option, const LvRollerMode &mode)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Roller was not created!";
        return;
    }
    lv_roller_set_options(mLvObj, option, mode);
}

void LvRoller::next(const LvAnimEnable &anim)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Roller was not created!";
        return;
    }
    mOptionIdx++;
    if (mOptionIdx >= this->getOptionsCount())  mOptionIdx = 0;
    this->setSelected(mOptionIdx, anim);
}

void LvRoller::previous(const LvAnimEnable &anim)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Roller was not created!";
        return;
    }
    mOptionIdx--;
    if (mOptionIdx < 0)  mOptionIdx = this->getOptionsCount() - 1;
    this->setSelected(mOptionIdx, anim);
}

void LvRoller::setSelected(const uint32_t &idx, const LvAnimEnable &anim)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Roller was not created!";
        return;
    }
    lv_roller_set_selected(mLvObj, idx, anim);
    mOptionIdx = idx;
}

void LvRoller::setVisibleRows(const uint32_t rowCnt)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Roller was not created!";
        return;
    }
    lv_roller_set_visible_row_count(mLvObj, rowCnt);
}

uint32_t LvRoller::getSelected() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Roller was not created!";
        return 0;
    }
    return lv_roller_get_selected(mLvObj);
}

QString LvRoller::getSelectedString(const uint32_t &buffSize) const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Roller was not created!";
        return "";
    }
    char buff[buffSize];
    lv_roller_get_selected_str(mLvObj, buff, buffSize);

    return QString(buff);
}

const char *LvRoller::getOptions() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Roller was not created!";
        return nullptr;
    }
    return lv_roller_get_options(mLvObj);
}

uint32_t LvRoller::getOptionsCount() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Roller was not created!";
        return 0;
    }
    return lv_roller_get_option_count(mLvObj);
}
