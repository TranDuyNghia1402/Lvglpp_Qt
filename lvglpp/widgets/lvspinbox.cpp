#include "lvspinbox.h"

LvSpinbox::LvSpinbox(LvBaseObject *parent) : LvBaseObject(parent) { }

void LvSpinbox::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent != nullptr)
        mLvObj = lv_spinbox_create(mParent->getLvObject());
    else
        mLvObj = lv_spinbox_create(lv_screen_active());
}

void LvSpinbox::setValue(const int32_t &value)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_set_value(mLvObj, value);
}

void LvSpinbox::setRollOver(const bool &rollover)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_set_rollover(mLvObj, rollover);
}

void LvSpinbox::setDigitFormat(const uint32_t &digitCnt, const uint32_t &sepPos)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_set_digit_format(mLvObj, digitCnt, sepPos);
}

void LvSpinbox::setStep(const uint32_t &step)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_set_step(mLvObj, step);
}

void LvSpinbox::setRange(const int32_t &min, const int32_t &max)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_set_range(mLvObj, min, max);
}

void LvSpinbox::setRange(const int32_t &min, const int32_t &max, const uint32_t &step)
{
    this->setRange(min, max);
    this->setStep(step);
}

void LvSpinbox::setCursorPos(const uint32_t &pos)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_set_cursor_pos(mLvObj , pos);
}

void LvSpinbox::setDigitStepDirection(const LvDir &direction)
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_set_digit_step_direction(mLvObj, direction);
}

void LvSpinbox::stepNext()
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_step_next(mLvObj);
}

void LvSpinbox::stepPrv()
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_step_prev(mLvObj);
}

void LvSpinbox::increase()
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_increment(mLvObj);
    emit valueChanged(this->getValue());
}

void LvSpinbox::decrease()
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return;
    }
    lv_spinbox_decrement(mLvObj);
    emit valueChanged(this->getValue());
}

void LvSpinbox::select()
{
    emit selected(this->getValue());
}

bool LvSpinbox::getRollOver() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return false;
    }
    return lv_spinbox_get_rollover(mLvObj);
}

int32_t LvSpinbox::getValue() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return 0;
    }
    return lv_spinbox_get_value(mLvObj);
}

int32_t LvSpinbox::getStep() const
{
    if (!mLvObj || !isCreated)
    {
        qDebug() << "[Warning] Spinbox was not created!";
        return 0;
    }
    return lv_spinbox_get_step(mLvObj);
}
