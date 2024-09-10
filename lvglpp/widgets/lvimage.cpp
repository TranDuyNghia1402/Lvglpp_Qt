#include "lvimage.h"

LvImage::LvImage(LvBaseObject *parent, const void *source) :
    LvBaseObject(parent), mSource(source)
{

}

void LvImage::create()
{
    isCreated = true;
    if (mParent)
        mLvObj = lv_image_create(mParent->getLvObject());
    else
        mLvObj = lv_image_create(lv_screen_active());
}

void LvImage::setSource(const void *src)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_src(mLvObj, src);
}

void LvImage::setOffsetX(const int32_t &x)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_offset_x(mLvObj, x);
}

void LvImage::setOffsetY(const int32_t &y)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_offset_y(mLvObj, y);
}

void LvImage::setRotation(const int32_t &angle)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_rotation(mLvObj, angle);
}

void LvImage::setPivot(const int32_t &x, const int32_t &y)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_pivot(mLvObj, x, y);
}

void LvImage::setScale(const uint32_t &zoom)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_scale(mLvObj, zoom);
}

void LvImage::setScaleX(const uint32_t &zoom)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_scale_x(mLvObj, zoom);
}

void LvImage::setScaleY(const uint32_t &zoom)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_scale_y(mLvObj, zoom);
}

void LvImage::setBlendMode(const LvBlendMode &blendMode)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_blend_mode(mLvObj, blendMode);
}

void LvImage::setAntiAlias(const bool &antiAlias)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_antialias(mLvObj, antiAlias);
}

void LvImage::setInnerAlign(const LvImageAlign &align)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_inner_align(mLvObj, align);
}

void LvImage::setBitmapMapSrc(const LvImageDsc *src)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_bitmap_map_src(mLvObj, src);
}

const void *LvImage::getSource() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return nullptr;
    }
    return mSource;
}

int32_t LvImage::getOffsetX() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return 0;
    }
    return lv_image_get_offset_x(mLvObj);
}

int32_t LvImage::getOffsetY() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return 0;
    }
    return lv_image_get_offset_y(mLvObj);
}

int32_t LvImage::getRotation() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return 0;
    }
    return lv_image_get_rotation(mLvObj);
}

void LvImage::getPivot(LvPoint *pivot)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_get_pivot(mLvObj, pivot);
}

int32_t LvImage::getScale() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return -1;
    }
    return lv_image_get_scale(mLvObj);
}

int32_t LvImage::getScaleX() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return -1;
    }
    return lv_image_get_scale_x(mLvObj);
}

int32_t LvImage::getScaleY() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return -1;
    }
    return lv_image_get_scale_y(mLvObj);
}

LvBlendMode LvImage::getBlendMode() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return LvBlendMode::LV_BLEND_MODE_NORMAL;
    }
    return lv_image_get_blend_mode(mLvObj);
}

bool LvImage::getAntiAlias() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return false;
    }
    return lv_image_get_blend_mode(mLvObj);
}

LvImageAlign LvImage::getInnerAlign() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return LvImageAlign::LV_IMAGE_ALIGN_DEFAULT;
    }
    return lv_image_get_inner_align(mLvObj);
}

const LvImageDsc *LvImage::getBitmapMapSrc() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] Image was not created!";
        return nullptr;
    }
    return lv_image_get_bitmap_map_src(mLvObj);
}
