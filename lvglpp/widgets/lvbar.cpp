#include "lvbar.h"

LvBar::LvBar(LvBaseObject *parent) : LvBaseObject(parent) { }

void LvBar::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_bar_create(mParent->getLvObject());
    else
        mLvObj = lv_bar_create(lv_screen_active());
}

void LvBar::setValue(const int32_t &value, const LvAnimEnable &anim)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return;
    }
    lv_bar_set_value(mLvObj, value, anim);
}

void LvBar::setStartValue(const int32_t &startVal, const LvAnimEnable &anim)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return;
    }
    lv_bar_set_start_value(mLvObj, startVal, anim);
}

void LvBar::setRange(const int32_t &min, const int32_t &max)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return;
    }
    lv_bar_set_range(mLvObj, min, max);
}

void LvBar::setMode(const LvBarMode &mode)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return;
    }
    lv_bar_set_mode(mLvObj, mode);
}

void LvBar::setOrientation(const LvBarOrientation &orientation)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return;
    }
    lv_bar_set_orientation(mLvObj, orientation);
}

int32_t LvBar::getValue() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return 0;
    }
    return lv_bar_get_value(mLvObj);
}

int32_t LvBar::getStart() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return 0;
    }
    return lv_bar_get_start_value(mLvObj);
}

int32_t LvBar::getMin() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return 0;
    }
    return lv_bar_get_min_value(mLvObj);
}

int32_t LvBar::getMax() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return 0;
    }
    return lv_bar_get_max_value(mLvObj);
}

LvBarMode LvBar::getMode() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return LV_BAR_MODE_NORMAL;
    }
    return lv_bar_get_mode(mLvObj);
}

LvBarOrientation LvBar::getOrientation() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return LV_BAR_ORIENTATION_AUTO;
    }
    return lv_bar_get_orientation(mLvObj);
}

bool LvBar::isSymmetrical() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Bar was not created!";
        return LV_BAR_ORIENTATION_AUTO;
    }
    return lv_bar_is_symmetrical(mLvObj);
}
