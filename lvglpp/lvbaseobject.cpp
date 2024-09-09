#include "lvbaseobject.h"

LvBaseObject::LvBaseObject(LvBaseObject *parent, int32_t width, int32_t heigth) :
    mParent(parent)
{
    mLvObj = lv_obj_create(parent->getLvObject());
    this->setSize(width, heigth);
}

LvBaseObject::LvBaseObject(int32_t width, int32_t heigth)
{
    mLvObj = lv_obj_create(lv_screen_active());
    this->setSize(width, heigth);
}

LvBaseObject::~LvBaseObject()
{
    if (mLvObj)
    {
        this->destroy();
    }
}

void LvBaseObject::destroy()
{
    lv_obj_clean(mLvObj);
    lv_obj_delete(mLvObj);
}

void LvBaseObject::clean()
{
    lv_obj_clean(mLvObj);
}

void LvBaseObject::hide()
{
    lv_obj_add_flag(mLvObj, LV_OBJ_FLAG_HIDDEN);
}

void LvBaseObject::show()
{
    lv_obj_clear_flag(mLvObj, LV_OBJ_FLAG_HIDDEN);
}

void LvBaseObject::setSize(int32_t width, int32_t height)
{
    lv_obj_set_size(mLvObj, width, height);
    mWidth = width;
    mHeight = height;
}

void LvBaseObject::setWidth(int32_t width)
{
    lv_obj_set_width(mLvObj, width);
    mWidth = width;
}

void LvBaseObject::setHeight(int32_t height)
{
    lv_obj_set_height(mLvObj, height);
    mHeight = height;
}

int32_t LvBaseObject::getWidght()
{
    return mWidth;
}

int32_t LvBaseObject::getHeight()
{
    return mHeight;
}

void LvBaseObject::setX(int32_t x)
{
    lv_obj_set_x(mLvObj, x);
}

void LvBaseObject::setY(int32_t y)
{
    lv_obj_set_y(mLvObj, y);
}

void LvBaseObject::setPos(int32_t x, int32_t y)
{
    lv_obj_set_pos(mLvObj, x, y);
}

void LvBaseObject::center()
{
    lv_obj_center(mLvObj);
}

void LvBaseObject::align(LvAlign align, int32_t x, int32_t y)
{
    lv_obj_align(mLvObj, align, x, y);
}

void LvBaseObject::setAlign(LvAlign align)
{
    lv_obj_set_align(mLvObj, align);
}

void LvBaseObject::setAlignTo(LvBaseObject *ref, LvAlign align, int32_t x, int32_t y)
{
    lv_obj_align_to(mLvObj, ref->getLvObject(), align, x, y);
}

void LvBaseObject::setOVerflowVisible(bool isVisible)
{
    if (isVisible)
        lv_obj_add_flag(mLvObj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
    else
        lv_obj_clear_flag(mLvObj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
}

LvObj *LvBaseObject::getLvObject()
{
    return mLvObj;
}

void LvBaseObject::setLvObject(LvObj *obj)
{
    lv_obj_delete(mLvObj);
    mLvObj = obj;
}
