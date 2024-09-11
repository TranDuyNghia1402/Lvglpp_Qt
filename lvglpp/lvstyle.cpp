#include "lvstyle.h"
#include <QDebug>

LvStyle LvObjectStyle::mStyle;

LvObjectStyle::LvObjectStyle()
{
    lv_style_init(&mStyle);
}

void LvObjectStyle::setWidth(const int32_t &width)
{
    lv_style_set_width(&mStyle, width);
}

void LvObjectStyle::setHeight(const int32_t &height)
{
    lv_style_set_height(&mStyle, height);
}

void LvObjectStyle::setSize(const int32_t &width, const int32_t &height)
{
    lv_style_set_size(&mStyle, width, height);
}

void LvObjectStyle::setX(const int32_t &x)
{
    lv_style_set_x(&mStyle, x);
}

void LvObjectStyle::setY(const int32_t &y)
{
    lv_style_set_y(&mStyle, y);
}

void LvObjectStyle::setAlign(LvAlign align)
{
    lv_style_set_align(&mStyle, align);
}

void LvObjectStyle::setBgColor(const LvColor &color)
{
    lv_style_set_bg_color(&mStyle, color);
}

void LvObjectStyle::setBgGradColor(const LvColor &color)
{
    lv_style_set_bg_grad_color(&mStyle, color);
}

void LvObjectStyle::setBgGradDir(const LvGradDir &graddir)
{
    lv_style_set_bg_grad_dir(&mStyle, graddir);
}

void LvObjectStyle::setBgOpa(const LvOpa &opa)
{
    lv_style_set_bg_opa(&mStyle, opa);
}

void LvObjectStyle::setBorderWidth(const int32_t &width)
{
    lv_style_set_border_width(&mStyle, width);
}

void LvObjectStyle::setBorderColor(const LvColor &color)
{
    lv_style_set_border_color(&mStyle, color);
}

void LvObjectStyle::setBorderPost(const bool &value)
{
    lv_style_set_border_post(&mStyle, value);
}

void LvObjectStyle::setBorderSide(const LvBorderSide &borderside)
{
    lv_style_set_border_side(&mStyle, borderside);
}

void LvObjectStyle::setBorderOpa(const LvOpa &opa)
{
    lv_style_set_border_opa(&mStyle, opa);
}

void LvObjectStyle::setPadLeft(const int32_t &value)
{
    lv_style_set_pad_left(&mStyle, value);
}

void LvObjectStyle::setPadTop(const int32_t &value)
{
    lv_style_set_pad_top(&mStyle, value);
}

void LvObjectStyle::setPadRight(const int32_t &value)
{
    lv_style_set_pad_right(&mStyle, value);
}

void LvObjectStyle::setPadBottom(const int32_t &value)
{
    lv_style_set_pad_bottom(&mStyle, value);
}

void LvObjectStyle::setPadAll(const int32_t &value)
{
    lv_style_set_pad_all(&mStyle, value);
}

void LvObjectStyle::setPadRow(const int32_t &value)
{
    lv_style_set_pad_row(&mStyle, value);
}

void LvObjectStyle::setPadColmn(const int32_t &value)
{
    lv_style_set_pad_column(&mStyle, value);
}

void LvObjectStyle::setMarginTop(const int32_t &value)
{
    lv_style_set_margin_top(&mStyle, value);
}

void LvObjectStyle::setMarginLeft(const int32_t &value)
{
    lv_style_set_margin_left(&mStyle, value);
}

void LvObjectStyle::setMarginRight(const int32_t &value)
{
    lv_style_set_margin_right(&mStyle, value);
}

void LvObjectStyle::setMarginBottom(const int32_t &value)
{
    lv_style_set_margin_bottom(&mStyle, value);
}

void LvObjectStyle::setTextFont(const LvFont font)
{
    lv_style_set_text_font(&mStyle, &font);
}

void LvObjectStyle::setTextColor(const LvColor color)
{
    lv_style_set_text_color(&mStyle, color);
}

void LvObjectStyle::setRadius(const int32_t &radius)
{
    lv_style_set_radius(&mStyle, radius);
}

void LvObjectStyle::setImgOpa(const LvOpa &opa)
{
    lv_style_set_image_opa(&mStyle, opa);
}

void LvObjectStyle::setLineWidth(const int32_t &width)
{
    lv_style_set_line_width(&mStyle, width);
}

void LvObjectStyle::setLineColor(const LvColor &color)
{
    lv_style_set_line_color(&mStyle, color);
}

void LvObjectStyle::setLineRounded(const bool &isRounded)
{
    lv_style_set_line_rounded(&mStyle, isRounded);

}

void LvObjectStyle::setLineOpa(const LvOpa &opa)
{
    lv_style_set_line_opa(&mStyle, opa);
}

void LvObjectStyle::setLineDashGap(const uint32_t &gap)
{
    lv_style_set_line_dash_gap(&mStyle, gap);
}

void LvObjectStyle::setLineDashWidth(const uint32_t &width)
{
    lv_style_set_line_dash_width(&mStyle, width);
}

void LvObjectStyle::reset()
{
    lv_style_reset(&mStyle);
}

LvStyle *LvObjectStyle::getStyle() const
{
    return &mStyle;
}
