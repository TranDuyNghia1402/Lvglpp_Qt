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
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_obj_create(mParent->getLvObject());
    else
        mLvObj = lv_obj_create(lv_screen_active());
    this->setSize(mWidth, mHeight);
}

void LvBaseObject::destroy()
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_clean(mLvObj);
    lv_obj_delete(mLvObj);
}

void LvBaseObject::clean()
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_clean(mLvObj);
}

void LvBaseObject::hide()
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_add_flag(mLvObj, LV_OBJ_FLAG_HIDDEN);
}

void LvBaseObject::show()
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_clear_flag(mLvObj, LV_OBJ_FLAG_HIDDEN);
}

void LvBaseObject::addPropFlag(const LvPropFlag &props)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_add_flag(mLvObj, props);
}

void LvBaseObject::clearPropFlag(const LvPropFlag &props)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_clear_flag(mLvObj, props);
}

void LvBaseObject::updatePropFlag(const LvPropFlag &prop, const bool &v)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_update_flag(mLvObj, prop, v);
}

void LvBaseObject::setSize(const int32_t &width, const int32_t &height)
{
    if (!isCreated || !mLvObj)
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
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_width(mLvObj, width);
    mWidth = width;
}

void LvBaseObject::setHeight(const int32_t &height)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_height(mLvObj, height);
    mHeight = height;
}

int32_t LvBaseObject::getWidth() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return -1;
    }
    return mWidth;
}

int32_t LvBaseObject::getHeight() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return -1;
    }
    return mHeight;
}

void LvBaseObject::setX(const int32_t &x)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_x(mLvObj, x);
}

void LvBaseObject::setY(const int32_t &y)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_y(mLvObj, y);
}

void LvBaseObject::setPos(const int32_t &x, const int32_t &y)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_pos(mLvObj, x, y);
}

void LvBaseObject::center()
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_center(mLvObj);
}

void LvBaseObject::align(const LvAlign &align, const int32_t &x, const int32_t &y)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_align(mLvObj, align, x, y);
}

void LvBaseObject::setAlign(const LvAlign &align)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_align(mLvObj, align);
}

void LvBaseObject::setAlignTo(LvBaseObject *ref, const LvAlign &align, const int32_t &x, const int32_t &y)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_align_to(mLvObj, ref->getLvObject(), align, x, y);
}

void LvBaseObject::setOVerflowVisible(const bool &isVisible)
{
    if (!isCreated || !mLvObj)
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
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_add_style(mLvObj, style.getStyle(), selector);
}

void LvBaseObject::removeStyle(LvObjectStyle &style, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_remove_style(mLvObj, style.getStyle(), selector);
}

void LvBaseObject::removeAllStyle()
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_remove_style_all(mLvObj);
}

void LvBaseObject::setScrollBarMode(const ScrollBarMode &mode)
{
    if (!isCreated || !mLvObj)
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
    if (!isCreated || !mLvObj)
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
    if (!isCreated || !mLvObj)
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

void LvBaseObject::setScrollSnapX(const LvScrollSnap &align)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_scroll_snap_x(mLvObj, align);
}

void LvBaseObject::setScrollSnapY(const LvScrollSnap &align)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_scroll_snap_y(mLvObj, align);
}

void LvBaseObject::scrollBy(const int32_t &x, const int32_t &y, const LvAnimEnable &animEn)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_scroll_by(mLvObj, x, y, animEn);
}

void LvBaseObject::scrollTo(const int32_t &x, const int32_t &y, const LvAnimEnable &animEn)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_scroll_to(mLvObj, x, y, animEn);
}

void LvBaseObject::scrollToX(const int32_t &x, const LvAnimEnable &animEn)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_scroll_to_x(mLvObj, x, animEn);
}

void LvBaseObject::scrollToY(const int32_t &y, const LvAnimEnable &animEn)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_scroll_to_y(mLvObj, y, animEn);
}

void LvBaseObject::scrollToView(const LvAnimEnable &animEn)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_scroll_to_view(mLvObj, animEn);
}

void LvBaseObject::scrollToViewRecursive(const LvAnimEnable &animEn)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_scroll_to_view_recursive(mLvObj, animEn);
}

void LvBaseObject::setTextFont(const LvFont &font, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_text_font(mLvObj, &font, selector);
}

void LvBaseObject::setTextColor(const LvColor &color, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_text_color(mLvObj, color, selector);
}

void LvBaseObject::setParent(LvBaseObject *parent)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    mParent = parent;
    lv_obj_set_parent(mLvObj, mParent->getLvObject());
}

LvBaseObject *LvBaseObject::getParent() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return nullptr;
    }
    return mParent;
}

LvBaseObject *LvBaseObject::getChilds(const int32_t &index)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return nullptr;
    }

    if (index >= lv_obj_get_child_count(mLvObj))
    {
        qDebug() << "[Error] child is not existed!";
        return nullptr;
    }

    LvObj *baseChild = lv_obj_get_child(mLvObj, index);
    LvBaseObject *children = new LvBaseObject();
    children->setLvObject(baseChild);
    return children;
}

void LvBaseObject::setBgColor(const LvColor &color, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_bg_color(mLvObj, color, selector);
}

void LvBaseObject::setBgOpa(const LvOpa &opa, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_bg_opa(mLvObj, opa, selector);
}

void LvBaseObject::setBorderWidth(const int32_t &width, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_border_width(mLvObj, width, selector);
}

void LvBaseObject::setBorderColor(const LvColor &color, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_border_color(mLvObj, color, selector);
}

void LvBaseObject::setBorderOpa(const LvOpa &opa, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_border_opa(mLvObj, opa, selector);
}

void LvBaseObject::setBorderSide(const LvBorderSide &borderside, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_border_side(mLvObj, borderside, selector);
}

void LvBaseObject::setBorderPost(const bool &value, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_border_post(mLvObj, value, selector);
}

void LvBaseObject::setRadius(const int32_t &radius, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_radius(mLvObj, radius, selector);
}

void LvBaseObject::setPadLeft(const int32_t &value, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_pad_left(mLvObj, value, selector);
}

void LvBaseObject::setPadRight(const int32_t &value, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_pad_right(mLvObj, value, selector);
}

void LvBaseObject::setPadTop(const int32_t &value, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_pad_top(mLvObj, value, selector);
}

void LvBaseObject::setPadBottom(const int32_t &value, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_pad_bottom(mLvObj, value, selector);
}

void LvBaseObject::setPadAll(const int32_t &value, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return;
    }
    lv_obj_set_style_pad_all(mLvObj, value, selector);
}

int32_t LvBaseObject::getScrollX() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return 0;
    }
    return lv_obj_get_scroll_x(mLvObj);
}

int32_t LvBaseObject::getScrollY() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return 0;
    }
    return lv_obj_get_scroll_y(mLvObj);
}

int32_t LvBaseObject::getScrollTop() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return 0;
    }
    return lv_obj_get_scroll_top(mLvObj);
}

int32_t LvBaseObject::getScrollBottom() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return 0;
    }
    return lv_obj_get_scroll_bottom(mLvObj);
}

int32_t LvBaseObject::getScrollLeft() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return 0;
    }
    return lv_obj_get_scroll_left(mLvObj);
}

int32_t LvBaseObject::getScrollRight() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return 0;
    }
    return lv_obj_get_scroll_right(mLvObj);
}

LvObj *LvBaseObject::getLvObject() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] object was not created!";
        return nullptr;
    }
    return mLvObj;
}

void LvBaseObject::setLvObject(LvObj *obj)
{
    if (mLvObj)
        lv_obj_delete(mLvObj);
    mLvObj = obj;
    isCreated = true;
}
