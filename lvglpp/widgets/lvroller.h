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

    /**
     * @brief setOption: set the options on a roller
     * @param option
     * @param mode
     */
    void setOption(const char *option, const LvRollerMode &mode = LV_ROLLER_MODE_NORMAL);

    /**
     * @brief next: move to next option
     */
    void next(const LvAnimEnable &anim = LV_ANIM_OFF);

    /**
     * @brief previous: move to previos option
     */
    void previous(const LvAnimEnable &anim = LV_ANIM_OFF);

    /**
     * @brief setSelected: set the selected option
     * @param idx
     * @param anim
     */
    void setSelected(const uint32_t &idx, const LvAnimEnable &anim = LV_ANIM_OFF);

    /**
     * @brief setVisibleRows: set the height to show the given number of rows (options)
     * @param rowCnt
     */
    void setVisibleRows(const uint32_t rowCnt);

    /**
     * @brief getSelected: get the index of the selected option
     * @return
     */
    uint32_t getSelected() const;

    /**
     * @brief getSelectedString: get the current selected option as a string.
     * @return
     */
    QString getSelectedString(const uint32_t &buffSize) const;

    /**
     * @brief getOptions: get the options of a roller
     * @return
     */
    const char *getOptions() const;

    /**
     * @brief getOptionsCount: get the total number of options
     * @return
     */
    uint32_t getOptionsCount() const;

private:
    int32_t mOptionIdx = 0;
};

#endif // LVROLLER_H
