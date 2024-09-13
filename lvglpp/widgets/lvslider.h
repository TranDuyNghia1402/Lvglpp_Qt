#ifndef LVSLIDER_H
#define LVSLIDER_H

#include "lvbaseobject.h"

class LvSlider : public LvBaseObject
{
public:
    LvSlider(LvBaseObject *parent = nullptr);

    /**
     * @brief create: create a slider
     * @warning must call after initialize a slider
     */
    void create();
};

#endif // LVSLIDER_H
