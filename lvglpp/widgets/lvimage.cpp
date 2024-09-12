#include "lvimage.h"

LvImage::LvImage(LvBaseObject *parent, const void *source) :
    LvBaseObject(parent), mSource(source)
{

}

void LvImage::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_image_create(mParent->getLvObject());
    else
        mLvObj = lv_image_create(lv_screen_active());
    setSource(mSource);

    lv_style_init(&mImageStyle);
}

void LvImage::setSource(const void *src)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_src(mLvObj, src);
}

void LvImage::setOffsetX(const int32_t &x)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_offset_x(mLvObj, x);
}

void LvImage::setOffsetY(const int32_t &y)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_offset_y(mLvObj, y);
}

void LvImage::setRotation(const int32_t &angle)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_rotation(mLvObj, angle * 10);
}

void LvImage::setPivot(const int32_t &x, const int32_t &y)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_pivot(mLvObj, x, y);
}

void LvImage::setScale(const uint32_t &zoom)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_scale(mLvObj, zoom);
}

void LvImage::setScaleX(const uint32_t &zoom)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_scale_x(mLvObj, zoom);
}

void LvImage::setScaleY(const uint32_t &zoom)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_scale_y(mLvObj, zoom);
}

void LvImage::setBlendMode(const LvBlendMode &blendMode)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_blend_mode(mLvObj, blendMode);
}

void LvImage::setAntiAlias(const bool &antiAlias)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_antialias(mLvObj, antiAlias);
}

void LvImage::setInnerAlign(const LvImageAlign &align)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_inner_align(mLvObj, align);
}

void LvImage::setBitmapMapSrc(const LvImageDsc *src)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_set_bitmap_map_src(mLvObj, src);
}

void LvImage::setOpa(const LvOpa &opa)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_style_set_image_opa(&mImageStyle, opa);
    lv_obj_add_style(mLvObj, &mImageStyle, LV_PART_MAIN);
}

const void *LvImage::getSource() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return nullptr;
    }
    return mSource;
}

int32_t LvImage::getOffsetX() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return 0;
    }
    return lv_image_get_offset_x(mLvObj);
}

int32_t LvImage::getOffsetY() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return 0;
    }
    return lv_image_get_offset_y(mLvObj);
}

int32_t LvImage::getRotation() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return 0;
    }
    return lv_image_get_rotation(mLvObj);
}

void LvImage::getPivot(LvPoint *pivot)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return;
    }
    lv_image_get_pivot(mLvObj, pivot);
}

int32_t LvImage::getScale() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return -1;
    }
    return lv_image_get_scale(mLvObj);
}

int32_t LvImage::getScaleX() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return -1;
    }
    return lv_image_get_scale_x(mLvObj);
}

int32_t LvImage::getScaleY() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return -1;
    }
    return lv_image_get_scale_y(mLvObj);
}

LvBlendMode LvImage::getBlendMode() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return LvBlendMode::LV_BLEND_MODE_NORMAL;
    }
    return lv_image_get_blend_mode(mLvObj);
}

bool LvImage::getAntiAlias() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return false;
    }
    return lv_image_get_blend_mode(mLvObj);
}

LvImageAlign LvImage::getInnerAlign() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return LvImageAlign::LV_IMAGE_ALIGN_DEFAULT;
    }
    return lv_image_get_inner_align(mLvObj);
}

const LvImageDsc *LvImage::getBitmapMapSrc() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Image was not created!";
        return nullptr;
    }
    return lv_image_get_bitmap_map_src(mLvObj);
}
