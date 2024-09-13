#include "lvslider.h"

LvSlider::LvSlider(LvBaseObject *parent) : LvBaseObject(parent) { }

void LvSlider::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_slider_create(mParent->getLvObject());
    else
        mLvObj = lv_slider_create(lv_screen_active());
}

void LvSlider::setValue(const int32_t &value, const LvAnimEnable &anim)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return;
    }
    lv_slider_set_value(mLvObj, value, anim);
}

void LvSlider::setLeftValue(const int32_t &value, const LvAnimEnable &anim)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return;
    }
    lv_slider_set_left_value(mLvObj, value, anim);
}

void LvSlider::setRange(const int32_t &min, const int32_t &max)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return;
    }
    lv_slider_set_range(mLvObj, min, max);
}

void LvSlider::setMode(const LvSliderMode &mode)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return;
    }
    lv_slider_set_mode(mLvObj, mode);
}

int32_t LvSlider::getValue() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return 0;
    }
    return lv_slider_get_value(mLvObj);
}

int32_t LvSlider::getLeftValue() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return 0;
    }
    return lv_slider_get_left_value(mLvObj);
}

int32_t LvSlider::getMin() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return 0;
    }
    return lv_slider_get_min_value(mLvObj);
}

int32_t LvSlider::getMax() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return 0;
    }
    return lv_slider_get_max_value(mLvObj);
}

bool LvSlider::isDragged() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return false;
    }
    return lv_slider_is_dragged(mLvObj);
}

LvSliderMode LvSlider::getMode() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return LV_SLIDER_MODE_NORMAL;
    }
    return lv_slider_get_mode(mLvObj);
}

bool LvSlider::isSymmetrical() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] slider was not created!";
        return false;
    }
    return lv_slider_is_symmetrical(mLvObj);
}
