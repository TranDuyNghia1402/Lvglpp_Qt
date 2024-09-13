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

    /**
     * @brief setValue: set a new value on slider
     * @param value
     * @param anim
     */
    void setValue(const int32_t &value, const LvAnimEnable &anim = LV_ANIM_OFF);

    /**
     * @brief setLeftValue: set a new value for the left knob of a slider
     * @param value
     * @param anim
     */
    void setLeftValue(const int32_t &value, const LvAnimEnable &anim = LV_ANIM_OFF);

    /**
     * @brief setRange: set the minimum and the maximum values of a bar
     * @param min
     * @param max
     */
    void setRange(const int32_t &min, const int32_t &max);

    /**
     * @brief setMode: set the mode of slider
     * @param mode
     */
    void setMode(const LvSliderMode &mode);

    /**
     * @brief getValue: get the value of the main knob of a slider
     * @return
     */
    int32_t getValue() const;

    /**
     * @brief getLeftValue: get the left value of the left knob of a slider
     * @return
     */
    int32_t getLeftValue() const;

    /**
     * @brief getMin: get the minimum value of the slider
     * @return
     */
    int32_t getMin() const;

    /**
     * @brief getMax: get the maximum value of the slider
     * @return
     */
    int32_t getMax() const;

    /**
     * @brief isDragged: give the slider is being dragged or not
     * @return
     */
    bool isDragged() const;

    /**
     * @brief getMode: get the mode of a slider
     * @return
     */
    LvSliderMode getMode() const;

    /**
     * @brief isSymmetrical: give the slider is in symmetrical mode or not
     * @return
     */
    bool isSymmetrical() const;

};

#endif // LVSLIDER_H
