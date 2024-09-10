#ifndef LVBUTTON_H
#define LVBUTTON_H

#include "lvbaseobject.h"
#include <QTimer>

class LvButton : public LvBaseObject
{
    Q_OBJECT
public:
    LvButton(LvBaseObject *parent = nullptr, QString text = "Button");

    /**
     * @brief create: create button
     * @warning must call after initialize button
     */
    void create();

    /**
     * @brief press: call to press the button
     */
    void press();

private:
    QTimer *mButtonPressedEffectTimer = nullptr;
    LvObj* mContentLabel = nullptr;
    QString mContent = "";

signals:
    void pressed();

private slots:
    void onButtonPressedEffectTimerHandler();
};

#endif // LVBUTTON_H
