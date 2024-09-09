#include "lvscale.h"

LvScale::LvScale(LvBaseObject *parent, int32_t min, int32_t max, bool isShowLabel) :
    LvBaseObject(parent), mMin(min), mMax(max), mIsShowLabel(isShowLabel) { }

void LvScale::create()
{
    isCreated = true;
    if (mParent)
        mLvObj = lv_scale_create(mParent->getLvObject());
    else
        mLvObj = lv_scale_create(lv_screen_active());
    setRange(mMin, mMax);
    if (mIsShowLabel)
        this->showLabel();
    else
        this->hideLabel();
}

void LvScale::showLabel()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return;
    }
    lv_scale_set_label_show(mLvObj, true);
}

void LvScale::hideLabel()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return;
    }
    lv_scale_set_label_show(mLvObj, false);
}

void LvScale::setRange(int32_t min, int32_t max)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return;
    }
    lv_scale_set_range(mLvObj, min, max);
    mMax = max;
    mMin = min;
}

void LvScale::setRotation(uint32_t angle)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return;
    }
    lv_scale_set_rotation(mLvObj, angle);
}

void LvScale::setMode(LvScaleMode mode)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return;
    }
    lv_scale_set_mode(mLvObj, mode);
}
