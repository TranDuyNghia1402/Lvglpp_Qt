#ifndef LVIMAGE_H
#define LVIMAGE_H

#include "lvbaseobject.h"

class LvImage : public LvBaseObject
{
public:
    LvImage(LvBaseObject *parent = nullptr, const void *source = nullptr);

    /**
     * @brief create: create image
     * @warning must call after initialize image
     */
    void create();

    /**
     * @brief setSource: set the image data to display on the object
     * @param src
     */
    void setSource(const void *src);

    /**
     * @brief setOffsetX: set an offset for the source of an image so the image will be displayed from the new origin.
     * @param x
     */
    void setOffsetX(const int32_t &x);

    /**
     * @brief setOffsetY: set an offset for the source of an image. so the image will be displayed from the new origin.
     * @param y
     */
    void setOffsetY(const int32_t &y);

    /**
     * @brief setRotation: et the rotation angle of the image. The image will be rotated around the set pivot set by
     * setPivot().  Note that indexed and alpha only images can't be transformed.
     * @param angle
     */
    void setRotation(const int32_t &angle);

    /**
     * @brief setPivot: set the rotation center of the image. The image will be rotated around this point.
     * x, y can be set with value of LV_PCT, lv_image_get_pivot will return the true pixel coordinate of pivot in this case.
     * @param x
     * @param y
     */
    void setPivot(const int32_t &x, const int32_t &y);

    /**
     * @brief setScale: set the zoom factor of the image. Note that indexed and alpha only images can't be transformed.
     * @param zoom
     */
    void setScale(const uint32_t &zoom);

    /**
     * @brief setScaleX: set the horizontal zoom factor of the image. Note that indexed and alpha only images can't be transformed.
     * @param zoom
     */
    void setScaleX(const uint32_t &zoom);

    /**
     * @brief setScaleY: set the vertical zoom factor of the image. Note that indexed and alpha only images can't be transformed.
     * @param zoom
     */
    void setScaleY(const uint32_t &zoom);

    /**
     * @brief setBlendMode: set the blend mode of an image.
     * @param blendMode
     */
    void setBlendMode(const LvBlendMode &blendMode);

    /**
     * @brief setAntiAlias: Enable/disable anti-aliasing for the transformations (rotate, zoom) or not.
     * The quality is better with anti-aliasing looks better but slower.
     * @param antiAlias
     */
    void setAntiAlias(const bool &antiAlias);

    /**
     * @brief setInnerAlign: set the image object size mode.
     * @param align
     */
    void setInnerAlign(const LvImageAlign &align);

    /**
     * @brief setBitmapMapSrc: set an A8 bitmap mask for the image.
     * @param src
     */
    void setBitmapMapSrc(const LvImageDsc *src);

    /**
     * @brief getSource: get the source of the image
     * @return
     */
    const void *getSource() const;

    /**
     * @brief getOffsetX: get the offset's x attribute of the image object.
     * @return
     */
    int32_t getOffsetX() const;

    /**
     * @brief getOffsetY: get the offset's y attribute of the image object.
     * @return
     */
    int32_t getOffsetY() const;

    /**
     * @brief getRotation: get the rotation of the image.
     * @return
     */
    int32_t getRotation() const;

    /**
     * @brief getPivot: get the pivot (rotation center) of the image. If pivot is set with LV_PCT,
     * convert it to px before return.
     * @param pivot
     */
    void getPivot(LvPoint *pivot);

    /**
     * @brief getScale: get the zoom factor of the image.
     * @return
     */
    int32_t getScale() const;

    /**
     * @brief getScaleX: get the horizontal zoom factor of the image.
     * @return
     */
    int32_t getScaleX() const;

    /**
     * @brief getScaleY: get the vertical zoom factor of the image.
     * @return
     */
    int32_t getScaleY() const;

    /**
     * @brief getBlendMode: get the current blend mode of the image
     * @return
     */
    LvBlendMode getBlendMode() const;

    /**
     * @brief getAntiAlias: get whether the transformations (rotate, zoom) are anti-aliased or not
     * @return
     */
    bool getAntiAlias() const;

    /**
     * @brief getInnerAlign: get the size mode of the image
     * @return
     */
    LvImageAlign getInnerAlign() const;

    /**
     * @brief getBitmapMapSrc: get the bitmap mask source.
     * @return
     */
    const LvImageDsc *getBitmapMapSrc() const;

private:
    const void *mSource;
};

#endif // LVIMAGE_H
