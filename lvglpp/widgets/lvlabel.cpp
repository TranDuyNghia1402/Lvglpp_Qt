#include "lvlabel.h"

LvLabel::LvLabel(LvBaseObject *parent, QString text) : LvBaseObject(parent), mContent(text) { }

void LvLabel::create()
{
    isCreated = true;
    if (mParent)
        mLvObj = lv_label_create(mParent->getLvObject());
    else
        mLvObj = lv_label_create(lv_screen_active());
    setText(mContent);
}

void LvLabel::setText(const QString &text)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] label was not created!";
        return;
    }
    lv_label_set_text(mLvObj, text.toStdString().c_str());
}

QString LvLabel::getText() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] label was not created!";
        return "";
    }
    return mContent;
}

void LvLabel::setTextAlign(const LvTextAlign &align)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] label was not created!";
        return;
    }
    lv_obj_set_style_text_align(mLvObj, align, LV_PART_MAIN);
}

void LvLabel::setLongMode(const LvLabelLongMode &mode)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] label was not created!";
        return;
    }
    lv_label_set_long_mode(mLvObj, mode);
}

void LvLabel::setFont(const LvFont &font, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] label was not created!";
        return;
    }
    lv_obj_set_style_text_font(mLvObj, &font, selector);
}

void LvLabel::setTextColor(const LvColor &color, const LvSelector &selector)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] label was not created!";
        return;
    }
    lv_obj_set_style_text_color(mLvObj, color, selector);
}
