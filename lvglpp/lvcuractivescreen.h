#ifndef LVCURACTIVESCREEN_H
#define LVCURACTIVESCREEN_H

#include "lvglpptype.h"

class LvCurrentActScreen
{
public:
    LvCurrentActScreen() = default;

    static void init();
    static LvObj *getActiveScreen();
    static void setScreenColor(LvColor color, LvSelector selector);

private:
    static LvObj *mCurrentActiveScreen;
};

#endif // LVCURACTIVESCREEN_H
