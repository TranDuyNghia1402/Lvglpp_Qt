#ifndef LVSPINBOX_H
#define LVSPINBOX_H

#include "lvbaseobject.h"

class LvSpinbox : public LvBaseObject
{
public:
    LvSpinbox(LvBaseObject *parent = nullptr);

    /**
     * @brief create: create a spinbox
     * @warning must call after initialize a spinbox
     */
    void create();
};

#endif // LVSPINBOX_H
