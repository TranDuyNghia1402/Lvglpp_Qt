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

    /**
     * @brief setValue: set a new value on the bar
     * @param value
     * @param aim
     */
    void setValue(const int32_t &value, const LvAnimEnable &anim = LV_ANIM_OFF);

    /**
     * @brief setStartValue: set a new start value on the bar
     * @param startVal
     * @param anim
     */
    void setStartValue(const int32_t &startVal, const LvAnimEnable &anim = LV_ANIM_OFF);

    /**
     * @brief setRange: set minimum and the maximum values of a bar
     * @param min
     * @param max
     */
    void setRange(const int32_t &min, const int32_t &max);

    /**
     * @brief setMode: set the type of bar.
     * @param mode
     */
    void setMode(const LvBarMode &mode);

    /**
     * @brief setOrientation: set the orientation of bar
     * @param orientation
     */
    void setOrientation(const LvBarOrientation &orientation);

    /**
     * @brief getValue: get the value of a bar
     * @return
     */
    int32_t getValue() const;

    /**
     * @brief getStart: get the start value of a bar
     * @return
     */
    int32_t getStart() const;

    /**
     * @brief getMin: get the minimum value of a bar
     * @return
     */
    int32_t getMin() const;

    /**
     * @brief getMax: get the maximum value of a bar
     * @return
     */
    int32_t getMax() const;

    /**
     * @brief getMode: get the type of bar.
     * @return
     */
    LvBarMode getMode() const;

    /**
     * @brief getOrientation: get the orientation of bar.
     * @return
     */
    LvBarOrientation getOrientation() const;

    /**
     * @brief isSymmetrical: give the bar is in symmetrical mode or not
     * @return
     */
    bool isSymmetrical() const;

};

#endif // LVBAR_H
