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

void LvScale::setRange(const int32_t &min, const int32_t &max)
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

void LvScale::setRotation(const int32_t &angle)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return;
    }
    lv_scale_set_rotation(mLvObj, angle);
}

void LvScale::setMode(const LvScaleMode &mode)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return;
    }
    lv_scale_set_mode(mLvObj, mode);
}

void LvScale::setTotalTickCount(const uint32_t &totalTickCnt)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return;
    }
    lv_scale_set_total_tick_count(mLvObj, totalTickCnt);
}

void LvScale::setMajorTickEvery(const uint32_t &majorTickEvery)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return;
    }
    lv_scale_set_major_tick_every(mLvObj, majorTickEvery);
}

void LvScale::setAngleRange(const uint32_t &angleRange)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    lv_scale_set_angle_range(mLvObj, angleRange);
}

void LvScale::setLineNeedleValue(LvBaseObject *needleLine, const int32_t &needleLen, const int32_t &value)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    lv_scale_set_line_needle_value(mLvObj, needleLine->getLvObject(), needleLen, value);
}

void LvScale::setImageNeedleValue(LvBaseObject *needleImg, const int32_t &value)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    lv_scale_set_image_needle_value(mLvObj, needleImg->getLvObject(), value);
}

void LvScale::setTextSrc(const char **txtSrc)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    lv_scale_set_text_src(mLvObj, txtSrc);
}

void LvScale::setPosDraw(const bool &en)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    lv_scale_set_post_draw(mLvObj, en);
}

void LvScale::setDrawTickOnTop(const bool &en)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    lv_scale_set_draw_ticks_on_top(mLvObj, en);
}

void LvScale::addSection()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    lv_scale_add_section(mLvObj);
}

void LvScale::setSectionRange(LvScaleSection *scaleSec, const int32_t &minorRange, const int32_t &majorRange)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    lv_scale_section_set_range(scaleSec, minorRange, majorRange);
}

void LvScale::setSectionStyle(LvScaleSection *scaleSec, const LvPart &part, LvStyle *sectionPartStyle)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    lv_scale_section_set_style(scaleSec, part, sectionPartStyle);
}

LvScaleMode LvScale::getMode() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    return lv_scale_get_mode(mLvObj);
}

int32_t LvScale::getTotalTickCount() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
    }
    return lv_scale_get_total_tick_count(mLvObj);
}

int32_t LvScale::getMajorTickEvery() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return -1;
    }
    return lv_scale_get_major_tick_every(mLvObj);
}

bool LvScale::getLabelShow() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return false;
    }
    return lv_scale_get_label_show(mLvObj);
}

uint32_t LvScale::getAngleRange() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return 0;
    }
    return lv_scale_get_angle_range(mLvObj);
}

int32_t LvScale::getRangeMin() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return 0;
    }
    return lv_scale_get_range_min_value(mLvObj);
}

int32_t LvScale::getRangeMax() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] scale was not created!";
        return 0;
    }
    return lv_scale_get_range_max_value(mLvObj);
}



