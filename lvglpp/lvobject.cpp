#include "lvobject.h"

LvObject::LvObject(LvObject *parent) : mParent(parent)
{
    mLvObj = lv_obj_create(parent->getLvObject());
}

LvObject::LvObject()
{
    mLvObj = lv_obj_create(lv_screen_active());
}

LvObj *LvObject::getLvObject()
{
    return mLvObj;
}
