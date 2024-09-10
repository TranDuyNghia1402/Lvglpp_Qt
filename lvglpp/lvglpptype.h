#ifndef LVGLPPTYPE_H
#define LVGLPPTYPE_H

#include <QObject>
#include <QDebug>
#include "core/lvgl/lvgl.h"

#define LvColorBlack            lv_color_black
#define LvColorWhite            lv_color_white
#define LvColorHex              lv_color_hex

typedef lv_obj_t                LvObj;
typedef lv_font_t               LvFont;
typedef lv_image_dsc_t          LvImageDsc;
typedef lv_point_t              LvPoint;

typedef lv_align_t              LvAlign;
typedef lv_text_align_t         LvTextAlign;
typedef lv_color_t              LvColor;
typedef lv_style_selector_t     LvSelector;
typedef lv_style_t              LvStyle;
typedef lv_opa_t                LvOpa;
typedef lv_border_side_t        LvBorderSide;
typedef lv_grad_dir_t           LvGradDir;
typedef lv_anim_enable_t        LvAnimEnable;
typedef lv_obj_flag_t           LvPropFlag;
typedef lv_label_long_mode_t    LvLabelLongMode;
typedef lv_scale_mode_t         LvScaleMode;
typedef lv_scale_section_t      LvScaleSection;
typedef lv_part_t               LvPart;
typedef lv_blend_mode_t         LvBlendMode;
typedef lv_image_align_t        LvImageAlign;
typedef lv_anim_enable_t        LvAnimEnable;
typedef lv_dir_t                LvDir;


enum class ScrollBarMode
{
    OFF = 0,
    ON,
    ACTIVE,
    AUTO
};

enum class ScrollDirection
{
    TOP = 0,
    LEFT,
    BOTTOM,
    RIGHT,
    HOR,
    VER,
    ALL
};


#endif
