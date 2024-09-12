#include "lvlabel.h"

LvLabel::LvLabel(LvBaseObject *parent, QString text) : LvBaseObject(parent), mContent(text) { }

void LvLabel::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_label_create(mParent->getLvObject());
    else
        mLvObj = lv_label_create(lv_screen_active());
    this->setText(mContent);
}

void LvLabel::setText(const QString &text)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] label was not created!";
        return;
    }
    lv_label_set_text(mLvObj, text.toStdString().c_str());
}

QString LvLabel::getText() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] label was not created!";
        return "";
    }
    return mContent;
}

void LvLabel::setTextAlign(const LvTextAlign &align)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] label was not created!";
        return;
    }
    lv_obj_set_style_text_align(mLvObj, align, LV_PART_MAIN);
}

void LvLabel::setLongMode(const LvLabelLongMode &mode)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] label was not created!";
        return;
    }
    lv_label_set_long_mode(mLvObj, mode);
}

void LvLabel::setTextFont(const LvFont &font, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] label was not created!";
        return;
    }
    lv_obj_set_style_text_font(mLvObj, &font, selector);
}

void LvLabel::setTextColor(const LvColor &color, const LvSelector &selector)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] label was not created!";
        return;
    }
    lv_obj_set_style_text_color(mLvObj, color, selector);
}
