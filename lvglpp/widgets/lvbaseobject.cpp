#include "lvbaseobject.h"

LvBaseObject::LvBaseObject(LvBaseObject *parent) : mParent(parent) { }

LvBaseObject::LvBaseObject(LvBaseObject *parent, const int32_t &width, const int32_t &height) :
    mParent(parent), mWidth(width), mHeight(height) { }

LvBaseObject::~LvBaseObject()
{
    if (mLvObj)
        this->destroy();
}

void LvBaseObject::create()
{
    isCreated = true;
    if (mParent)
        mLvObj = lv_obj_create(mParent->getLvObject());
    else
        mLvObj = lv_obj_create(lv_screen_active());
    this->setSize(mWidth, mHeight);
}

void LvBaseObject::destroy()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_clean(mLvObj);
    lv_obj_delete(mLvObj);
}

void LvBaseObject::clean()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_clean(mLvObj);
}

void LvBaseObject::hide()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_add_flag(mLvObj, LV_OBJ_FLAG_HIDDEN);
}

void LvBaseObject::show()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_clear_flag(mLvObj, LV_OBJ_FLAG_HIDDEN);
}

void LvBaseObject::addPropFlag(const LvPropFlag &props)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_add_flag(mLvObj, props);
}

void LvBaseObject::clearPropFlag(const LvPropFlag &props)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_clear_flag(mLvObj, props);
}

void LvBaseObject::setSize(const int32_t &width, const int32_t &height)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_size(mLvObj, width, height);
    mWidth = width;
    mHeight = height;
}

void LvBaseObject::setWidth(const int32_t &width)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_width(mLvObj, width);
    mWidth = width;
}

void LvBaseObject::setHeight(const int32_t &height)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_height(mLvObj, height);
    mHeight = height;
}

int32_t LvBaseObject::getWidth() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return -1;
    }
    return mWidth;
}

int32_t LvBaseObject::getHeight() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return -1;
    }
    return mHeight;
}

void LvBaseObject::setX(const int32_t &x)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_x(mLvObj, x);
}

void LvBaseObject::setY(const int32_t &y)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_y(mLvObj, y);
}

void LvBaseObject::setPos(const int32_t &x, const int32_t &y)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_pos(mLvObj, x, y);
}

void LvBaseObject::center()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_center(mLvObj);
}

void LvBaseObject::align(const LvAlign &align, const int32_t &x, const int32_t &y)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_align(mLvObj, align, x, y);
}

void LvBaseObject::setAlign(const LvAlign &align)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_align(mLvObj, align);
}

void LvBaseObject::setAlignTo(LvBaseObject *ref, const LvAlign &align, const int32_t &x, const int32_t &y)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_align_to(mLvObj, ref->getLvObject(), align, x, y);
}

void LvBaseObject::setOVerflowVisible(const bool &isVisible)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    if (isVisible)
        lv_obj_add_flag(mLvObj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
    else
        lv_obj_clear_flag(mLvObj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
}

void LvBaseObject::addStyle(LvObjectStyle &style, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_add_style(mLvObj, style.getStyle(), selector);
}

void LvBaseObject::removeStyle(LvObjectStyle &style, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_remove_style(mLvObj, style.getStyle(), selector);
}

void LvBaseObject::removeAllStyle()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_remove_style_all(mLvObj);
}

void LvBaseObject::setScrollBarMode(const ScrollBarMode &mode)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    switch (mode)
    {
        case ScrollBarMode::OFF:
            lv_obj_set_scrollbar_mode(mLvObj, LV_SCROLLBAR_MODE_OFF);
            break;
        case ScrollBarMode::ON:
            lv_obj_set_scrollbar_mode(mLvObj, LV_SCROLLBAR_MODE_ON);
            break;
        case ScrollBarMode::ACTIVE:
            lv_obj_set_scrollbar_mode(mLvObj, LV_SCROLLBAR_MODE_ACTIVE);
            break;
        case ScrollBarMode::AUTO:
            lv_obj_set_scrollbar_mode(mLvObj, LV_SCROLLBAR_MODE_AUTO);
            break;
    }
}

void LvBaseObject::setScrollable(const bool &isScrollable)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    if (isScrollable)
    {
        lv_obj_add_flag(mLvObj, LV_OBJ_FLAG_SCROLLABLE);
    }
    else
    {
        lv_obj_clear_flag(mLvObj, LV_OBJ_FLAG_SCROLLABLE);
    }
}

void LvBaseObject::setScrollDir(const ScrollDirection &direction)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    switch (direction)
    {
        case ScrollDirection::TOP:
            lv_obj_set_scroll_dir(mLvObj, LV_DIR_TOP);
            break;
        case ScrollDirection::LEFT:
            lv_obj_set_scroll_dir(mLvObj, LV_DIR_LEFT);
            break;
        case ScrollDirection::BOTTOM:
            lv_obj_set_scroll_dir(mLvObj, LV_DIR_BOTTOM);
            break;
        case ScrollDirection::RIGHT:
            lv_obj_set_scroll_dir(mLvObj, LV_DIR_RIGHT);
            break;
        case ScrollDirection::HOR:
            lv_obj_set_scroll_dir(mLvObj, LV_DIR_HOR);
            break;
        case ScrollDirection::VER:
            lv_obj_set_scroll_dir(mLvObj, LV_DIR_VER);
            break;
        case ScrollDirection::ALL:
            lv_obj_set_scroll_dir(mLvObj, LV_DIR_ALL);
            break;
    }
}

void LvBaseObject::scrollBy(const int32_t &x, const int32_t &y, const LvAnimEnable &animEn)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_scroll_by(mLvObj, x, y, animEn);
}

void LvBaseObject::scrollTo(const int32_t &x, const int32_t &y, const LvAnimEnable &animEn)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_scroll_to(mLvObj, x, y, animEn);
}

void LvBaseObject::scrollToX(const int32_t &x, const LvAnimEnable &animEn)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_scroll_to_x(mLvObj, x, animEn);
}

void LvBaseObject::scrollToY(const int32_t &y, const LvAnimEnable &animEn)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_scroll_to_y(mLvObj, y, animEn);
}

void LvBaseObject::setParent(LvBaseObject *parent)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    mParent = parent;
    lv_obj_set_parent(mLvObj, mParent->getLvObject());
}

LvBaseObject *LvBaseObject::getParent() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return nullptr;
    }
    return mParent;
}

LvBaseObject *LvBaseObject::getChilds(const int32_t &index)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return nullptr;
    }
    LvObj *baseChild = lv_obj_get_child(mLvObj, index);
    LvBaseObject *children = new LvBaseObject();
    children->setLvObject(baseChild);
    return children;
}

void LvBaseObject::setBgColor(const LvColor &color, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_bg_color(mLvObj, color, selector);
}

void LvBaseObject::setBgOpa(const LvOpa &opa, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_bg_opa(mLvObj, opa, selector);
}

void LvBaseObject::setBorderWidth(const int32_t &width, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_border_width(mLvObj, width, selector);
}

void LvBaseObject::setBorderColor(const LvColor &color, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_border_color(mLvObj, color, selector);
}

void LvBaseObject::setBorderOpa(const LvOpa &opa, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_border_opa(mLvObj, opa, selector);
}

void LvBaseObject::setBorderSide(const LvBorderSide &borderside, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_border_side(mLvObj, borderside, selector);
}

void LvBaseObject::setBorderPost(const bool &value, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_border_post(mLvObj, value, selector);
}

void LvBaseObject::setRadius(const int32_t &radius, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_radius(mLvObj, radius, selector);
}

LvObj *LvBaseObject::getLvObject() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return nullptr;
    }
    return mLvObj;
}

void LvBaseObject::setLvObject(LvObj *obj)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    if (mLvObj)
        lv_obj_delete(mLvObj);
    mLvObj = obj;
}
