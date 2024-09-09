#include "lvlabel.h"

LvLabel::LvLabel(LvBaseObject *parent, QString text) : LvBaseObject(), mContent(text) { }

void LvLabel::create()
{
    if (mParent)
        mLvObj = lv_label_create(mParent->getLvObject());
    else
        mLvObj = lv_label_create(lv_screen_active());
    setText(mContent);
}

void LvLabel::setText(const QString &text)
{
    lv_label_set_text(mLvObj, text.toStdString().c_str());
}

QString LvLabel::getText() const
{
    return mContent;
}

void LvLabel::setTextAlign(const LvTextAlign &align)
{
    lv_obj_set_style_text_align(mLvObj, align, LV_PART_MAIN);
}

void LvLabel::setLongMode(const LvLabelLongMode &mode)
{
    lv_label_set_long_mode(mLvObj, mode);
}

void LvLabel::setFont(const LvFont &font, const LvSelector &selector)
{
    lv_obj_set_style_text_font(mLvObj, &font, selector);
}

void LvLabel::setTextColor(const LvColor &color, const LvSelector &selector)
{
    lv_obj_set_style_text_color(mLvObj, color, selector);
}
