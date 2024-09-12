#ifndef LVBAR_H
#define LVBAR_H

#include "lvbaseobject.h"

class LvBar : public LvBaseObject
{
public:
    LvBar(LvBaseObject *parent = nullptr);

    /**
     * @brief create: create a bar
     * @warning must call after initialize a bar
     */
    void create();

};

#endif // LVBAR_H
