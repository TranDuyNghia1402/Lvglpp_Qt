#include "lvobject.h"

LvObject::LvObject(LvObject *parent, int32_t width, int32_t heigth) :
    mParent(parent), mWidth(width), mHeight(heigth)
{
    mLvObj = lv_obj_create(parent->getLvObject());
    this->setSize(width, heigth);
}

LvObject::LvObject()
{
    mLvObj = lv_obj_create(lv_screen_active());
}

LvObject::~LvObject()
{
    if (mLvObj)
    {
        this->destroy();
    }
}

void LvObject::destroy()
{
    lv_obj_clean(mLvObj);
    lv_obj_delete(mLvObj);
}

void LvObject::clean()
{
    lv_obj_clean(mLvObj);
}

void LvObject::hide()
{
    lv_obj_add_flag(mLvObj, LV_OBJ_FLAG_HIDDEN);
}

void LvObject::show()
{
    lv_obj_clear_flag(mLvObj, LV_OBJ_FLAG_HIDDEN);
}

void LvObject::setSize(int32_t width, int32_t height)
{
    lv_obj_set_size(mLvObj, width, height);
    mWidth = width;
    mHeight = height;
}

void LvObject::setWidth(int32_t width)
{
    lv_obj_set_width(mLvObj, width);
    mWidth = width;
}

void LvObject::setHeight(int32_t height)
{
    lv_obj_set_height(mLvObj, height);
    mHeight = height;
}

int32_t LvObject::getWidght()
{
    return mWidth;
}

int32_t LvObject::getHeight()
{
    return mHeight;
}

void LvObject::setX(int32_t x)
{
    lv_obj_set_x(mLvObj, x);
}

void LvObject::setY(int32_t y)
{
    lv_obj_set_y(mLvObj, y);
}

void LvObject::setPos(int32_t x, int32_t y)
{
    lv_obj_set_pos(mLvObj, x, y);
}

void LvObject::center()
{
    lv_obj_center(mLvObj);
}

void LvObject::align(LvAlign align, int32_t x, int32_t y)
{
    lv_obj_align(mLvObj, align, x, y);
}

void LvObject::setAlign(LvAlign align)
{
    lv_obj_set_align(mLvObj, align);
}

void LvObject::setAlignTo(LvObject *ref, LvAlign align, int32_t x, int32_t y)
{
    lv_obj_align_to(mLvObj, ref->getLvObject(), align, x, y);
}

void LvObject::setOVerflowVisible(bool isVisible)
{
    if (isVisible)
        lv_obj_add_flag(mLvObj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
    else
        lv_obj_clear_flag(mLvObj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
}

LvObj *LvObject::getLvObject()
{
    return mLvObj;
}
