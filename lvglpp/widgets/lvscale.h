#ifndef LVSCALE_H
#define LVSCALE_H

#include "lvbaseobject.h"

class LvScale : public LvBaseObject
{
public:
    LvScale(LvBaseObject *parent = nullptr, int32_t min = 0, int32_t max = 100, bool isShowLabel = true);

    /**
     * @brief create: create scale
     * @warning must call after initialize scale
     */
    void create();

    /**
     * @brief showLabel: show label of scale
     */
    void showLabel();

    /**
     * @brief hideLabel: hide label of scale
     */
    void hideLabel();

    /**
     * @brief setRange: set range of scale
     * @param min
     * @param max
     */
    void setRange(int32_t min, int32_t max);

    /**
     * @brief setRotation: set rotation of scale
     * @param angle
     */
    void setRotation(uint32_t angle);

    /**
     * @brief setMode: set scale mode
     * @param mode
     */
    void setMode(LvScaleMode mode);

private:
    int32_t mMin;
    int32_t mMax;
    bool mIsShowLabel;
};

#endif // LVSCALE_H
