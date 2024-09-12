#include "lvline.h"

LvLine::LvLine(LvBaseObject *parent) : LvBaseObject(parent)
{

}

void LvLine::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_line_create(mParent->getLvObject());
    else
        mLvObj = lv_line_create(lv_screen_active());
}

void LvLine::setPoint(const LvPointPrecise points[], const int32_t &pointNum)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Line was not created!";
        return;
    }
    lv_line_set_points(mLvObj, points, pointNum);
}

void LvLine::invertY(const bool &en)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Line was not created!";
        return;
    }
    lv_line_set_y_invert(mLvObj, en);
}

bool LvLine::isInvertY() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Line was not created!";
        return false;
    }
    return lv_line_get_y_invert(mLvObj);
}
