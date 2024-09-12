#ifndef LVROLLER_H
#define LVROLLER_H

#include "lvbaseobject.h"

class LvRoller : public LvBaseObject
{
public:
    LvRoller(LvBaseObject *parent = nullptr);

    /**
     * @brief create: create a roller
     * @warning must call after initialize a roller
     */
    void create();
};

#endif // LVROLLER_H
