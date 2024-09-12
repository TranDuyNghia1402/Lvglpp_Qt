#ifndef LVSPINBOX_H
#define LVSPINBOX_H

#include "lvbaseobject.h"

class LvSpinbox : public LvBaseObject
{
    Q_OBJECT
public:
    LvSpinbox(LvBaseObject *parent = nullptr);
//    LvSpinbox(LvBaseObject *parent = nullptr, )

    /**
     * @brief create: create a spinbox
     * @warning must call after initialize a spinbox
     */
    void create();

    /**
     * @brief setValue: set spinbox value
     * @param value
     */
    void setValue(const int32_t &value);

    /**
     * @brief setRollOver: set spinbox rollover function
     * @param rollover
     */
    void setRollOver(const bool &rollover);

    /**
     * @brief setDigitFormat: set spinbox digit format (digit count and decimal format)
     * @param digitCnt: number of digit excluding the decimal separator and the sign
     * @param sepPos: number of digit before the decimal point. If 0, decimal point is not shown
     */
    void setDigitFormat(const uint32_t &digitCnt, const uint32_t &sepPos);

    /**
     * @brief setStep: set spinbox step
     * @param step
     */
    void setStep(const uint32_t &step);

    /**
     * @brief setRange: set spinbox value range
     * @param min
     * @param max
     */
    void setRange(const int32_t &min, const int32_t &max);

    /**
     * @brief setRange: set spinbox value range with step
     * @param min
     * @param max
     * @param step
     */
    void setRange(const int32_t &min, const int32_t &max, const uint32_t &step);

    /**
     * @brief setCursorPos: set cursor position to a specific digit for edition
     * @param pos
     */
    void setCursorPos(const uint32_t &pos);

    /**
     * @brief setDigitStepDirection: set direction of digit step when clicking an encoder button while in editing mode
     * @param direction
     */
    void setDigitStepDirection(const LvDir &direction);

    /**
     * @brief stepNext: select next lower digit for edition by dividing the step by 10
     */
    void stepNext();

    /**
     * @brief stepPrv: select next higher digit for edition by multiplying the step by 10
     */
    void stepPrv();

    /**
     * @brief increase: increment spinbox value by one step
     */
    void increase();

    /**
     * @brief decrease: decrement spinbox value by one step
     */
    void decrease();

    /**
     * @brief select: select current spinbox value
     */
    void select();

    /**
     * @brief getRollOver: get spinbox rollover function status
     * @return
     */
    bool getRollOver() const;

    /**
     * @brief getValue: get the spinbox numeral value (user has to convert to float according to its digit format)
     * @return
     */
    int32_t getValue() const;

    /**
     * @brief getStep: get the spinbox step value (user has to convert to float according to its digit format)
     * @return
     */
    int32_t getStep() const;

private:

signals:
    void valueChanged(int32_t value);
    void selected(int32_t value);
};

#endif // LVSPINBOX_H
