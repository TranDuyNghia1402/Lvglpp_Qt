#ifndef LVLINE_H
#define LVLINE_H

#include "lvbaseobject.h"

class LvLine : public LvBaseObject
{
public:
    LvLine(LvBaseObject *parent = nullptr);

    /**
     * @brief create: create line
     * @warning must call after initialize line
     */
    void create();

    /**
     * @brief setPoint: set an array of points. The line object will connect these points.
     * @param points
     * @param pointNum
     */
    void setPoint(const LvPointPrecise points[], const int32_t &pointNum);

    /**
     * @brief invertY: Enable (or disable) the y coordinate inversion.
     * If enabled then y will be subtracted from the height of the object,
     * therefore the y = 0 coordinate will be on the bottom.
     * @param en
     */
    void invertY(const bool &en);

    /**
     * @brief isInvertY: get the y inversion attribute
     * @return
     */
    bool isInvertY() const;

private:

};

#endif // LVLINE_H
