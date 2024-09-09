#ifndef LVCURACTIVESCREEN_H
#define LVCURACTIVESCREEN_H

#include "lvglpptype.h"
#include "lvglpp/lvbaseobject.h"

class LvCurrentActScreen
{
public:
    LvCurrentActScreen() = default;

    static void init();
    static LvBaseObject *getActiveScreen();
    static void setScreenColor(LvColor color, LvSelector selector);

private:
    static LvObj *mCurrentScreen;
    static LvBaseObject *mCurrentActScreen;
};

#endif // LVCURACTIVESCREEN_H
