#ifndef LVSTYLE_H
#define LVSTYLE_H

#include "lvglpptype.h"

class LvObjectStyle
{
public:
    LvObjectStyle();

    /**
     * @brief setWidth: set style width
     * @param width
     */
    void setWidth(const int32_t &width);

    /**
     * @brief setHeight: set style height
     * @param height
     */
    void setHeight(const int32_t &height);

    /**
     * @brief setSize: set style size
     * @param width
     * @param height
     */
    void setSize(const int32_t &width, const int32_t &height);

    /**
     * @brief setX: set style position at x
     * @param x
     */
    void setX(const int32_t &x);

    /**
     * @brief setY: set style position at y
     * @param y
     */
    void setY(const int32_t &y);

    /**
     * @brief setAlign: set align style
     * @param align
     */
    void setAlign(LvAlign align);

    /**
     * @brief setBgColor: set style background color
     * @param color
     */
    void setBgColor(const LvColor &color);

    /**
     * @brief setBgGradColor: set gradient color of background
     * @warning use only if grad_dir is not LV_GRAD_DIR_NONE
     * @param color
     */
    void setBgGradColor(const LvColor &color);

    /**
     * @brief setBgGradDir: set gradient direction of background
     * @param grad
     */
    void setBgGradDir(const LvGradDir &graddir);

    /**
     * @brief setBgOpa: set style background opa
     * @param opa
     */
    void setBgOpa(const LvOpa &opa);

    /**
     * @brief setBorderWidth: set style border width
     * @param width
     */
    void setBorderWidth(const int32_t &width);

    /**
     * @brief setBorderColor: set style border color
     * @param color
     */
    void setBorderColor(const LvColor &color);

    /**
     * @brief setBorderPost: set style border post
     * @param value
     */
    void setBorderPost(const bool &value);

    /**
     * @brief setBorderSide: set style border side
     * @param borderside
     */
    void setBorderSide(const LvBorderSide &borderside);

    /**
     * @brief setBorderOpa: set style border opa
     * @param opa
     */
    void setBorderOpa(const LvOpa &opa);

    /**
     * @brief setPadLeft: set padding left
     * @param value
     */
    void setPadLeft(const int32_t &value);

    /**
     * @brief setPadTop: set padding top
     * @param value
     */
    void setPadTop(const int32_t &value);

    /**
     * @brief setPadRight: set padding right
     * @param value
     */
    void setPadRight(const int32_t &value);

    /**
     * @brief setPadBottom: set padding bottom
     * @param value
     */
    void setPadBottom(const int32_t &value);

    /**
     * @brief setPadAll: set padding to object
     * @param value
     */
    void setPadAll(const int32_t &value);

    /**
     * @brief setPadRow: set padding between row
     * @param value
     */
    void setPadRow(const int32_t &value);

    /**
     * @brief setPadColmn: set padding between column
     * @param value
     */
    void setPadColmn(const int32_t &value);

    /**
     * @brief setMarginTop: set margin top
     * @param value
     */
    void setMarginTop(const int32_t &value);

    /**
     * @brief setMarginLeft: set margin left
     * @param value
     */
    void setMarginLeft(const int32_t &value);

    /**
     * @brief setMarginRight: set margin right
     * @param value
     */
    void setMarginRight(const int32_t &value);

    /**
     * @brief setMarginBottom: set margin bottom
     * @param value
     */
    void setMarginBottom(const int32_t &value);

    /**
     * @brief setTextFont: set style text font
     * @param font
     */
    void setTextFont(const LvFont font);

    /**
     * @brief setTextColor: set style text color
     * @param color
     */
    void setTextColor(const LvColor color);

    /**
     * @brief setRadius: set style radius
     * @param radius
     * @param selector
     */
    void setRadius(const int32_t &radius);

    /**
     * @brief setImgOpa: set opa for image object
     * @param opa
     */
    void setImgOpa(const LvOpa &opa);

    /**
     * @brief reset: reset a style (free all its data)
     */
    void reset();

    /**
     * @brief getStyle get base type style of object
     * @warning do not call this function
     * @return
     */
    LvStyle *getStyle() const;

private:
    static LvStyle mStyle;
};

#endif // LVSTYLE_H
