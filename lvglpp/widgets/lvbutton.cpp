#include "lvbutton.h"

LvButton::LvButton(LvBaseObject *parent, QString text) :
    LvBaseObject(parent), mContent(text)
{
    mButtonPressedEffectTimer = new QTimer();
    mButtonPressedEffectTimer->setSingleShot(true);
    mButtonPressedEffectTimer->setInterval(100);

    connect(mButtonPressedEffectTimer, &QTimer::timeout, this, &LvButton::onButtonPressedEffectTimerHandler);
}

void LvButton::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_button_create(mParent->getLvObject());
    else
        mLvObj = lv_button_create(lv_screen_active());

    mContentLabel = lv_label_create(mLvObj);
    lv_label_set_text(mContentLabel, mContent.toStdString().c_str());
    lv_obj_center(mContentLabel);
}

void LvButton::press()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] button was not created!";
        return;
    }
    mButtonPressedEffectTimer->start();
    this->setBgOpa(LV_OPA_0);
    emit pressed();
}

void LvButton::onButtonPressedEffectTimerHandler()
{
    if (!isCreated)
    {
        qDebug() << "[Warning] button was not created!";
        mButtonPressedEffectTimer->stop();
    }
    this->setBgOpa(LV_OPA_100);
}
