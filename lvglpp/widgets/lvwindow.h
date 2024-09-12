#ifndef LVWINDOW_H
#define LVWINDOW_H

#include "lvbaseobject.h"

class LvWindow : public LvBaseObject
{
public:
    LvWindow(LvBaseObject *parent);

    /**
     * @brief create: create window
     * @warning must call after initialize a window
     */
    void create();
};

#endif // LVWINDOW_H
