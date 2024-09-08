#ifndef CURRENTACTSCREEN_H
#define CURRENTACTSCREEN_H

#include "lvglpptype.h"

class CurrentActScreen
{
public:
    CurrentActScreen() = default;

    static void init();
    static LvObj *getActiveScreen();
    static void setScreenColor(LvColor color, LvSelector selector);

private:
    static LvObj *mCurrentActiveScreen;
};

#endif // CURRENTACTSCREEN_H
