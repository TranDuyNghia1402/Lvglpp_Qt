#ifndef LVSCALE_H
#define LVSCALE_H

/**
 *
 * The scale widget is divided in the following three parts:
 *  - LV_PART_MAIN Main line. See blue line in the example image.
 *  - LV_PART_ITEMS Minor ticks. See red minor ticks in the example image.
 *  - LV_PART_INDICATOR Major ticks and its labels (if enabled). See pink labels and green major ticks in the example image.
 *
 */

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
    void setRange(const int32_t &min, const int32_t &max);

    /**
     * @brief setRotation: set rotation of scale
     * @param angle
     */
    void setRotation(const int32_t &angle);

    /**
     * @brief setMode: set scale mode
     * @param mode
     */
    void setMode(const LvScaleMode &mode);

    /**
     * @brief setTotalTickCount: set tick count of scale (including minor and major ticks)
     * @param totalTickCnt
     */
    void setTotalTickCount(const uint32_t &totalTickCnt);

    /**
     * @brief setMajorTickEvery: set how often the major tick will be drawn
     * @param majorTickEvery
     */
    void setMajorTickEvery(const uint32_t &majorTickEvery);

        /**
     * @brief setMinorTickLength: set minor tick length
     * @param len
     */
    void setMinorTickLength(const int32_t &len);

    /**
     * @brief setMajorTickLength: set major tick length
     * @param len
     */
    void setMajorTickLength(const int32_t &len);

    /**
     * @brief setMajorTickWidth: set major tick width
     * @param width
     */
    void setMajorTickWidth(const int32_t &width);

    /**
     * @brief setMinorTickWidth: set minor tick width
     * @param width
     */
    void setMinorTickWidth(const int32_t &width);

    /**
     * @brief setAngleRange: set properties specific to round scale
     * @param angleRange
     */
    void setAngleRange(const uint32_t &angleRange);

    /**
     * @brief setLineNeedleValue: point the needle to the corresponding value through the line
     * @param needleLine
     * @param needleLen
     * @param value
     */
    void setLineNeedleValue(LvBaseObject *needleLine, const int32_t &needleLen, const int32_t &value);

    /**
     * @brief setImageNeedleValue: point the needle to the corresponding value through the image, image must point to the right
     * @param needleImg
     * @param value
     */
    void setImageNeedleValue(LvBaseObject *needleImg, const int32_t &value);

    /**
     * @brief setTextSrc: set custom text source for major ticks labels
     * @param txtSrc
     */
    void setTextSrc(const char **txtSrc);

    /**
     * @brief setPosDraw: draw the scale after all the children are drawn
     * @param en
     */
    void setPosDraw(const bool &en);

    /**
     * @brief setDrawTickOnTop: draw the scale ticks on top of all parts
     * @param en
     */
    void setDrawTickOnTop(const bool &en);

    /**
     * @brief addSection: add a section to the given scale
     * @param section
     */
    void addSection();

    /**
     * @brief setSectionRange: set the range for the given scale section
     * @param scaleSec
     * @param minorRange
     * @param majorRange
     */
    void setSectionRange(LvScaleSection *scaleSec, const int32_t &minorRange, const int32_t &majorRange);

    /**
     * @brief setSectionStyle: set the style of the part for the given scale section
     * @param scaleSec
     * @param part
     * @param sectionPartStyle
     */
    void setSectionStyle(LvScaleSection *scaleSec, const LvPart &part, LvStyle *sectionPartStyle);

    /**
     * @brief getMode: get scale mode
     * @return
     */
    LvScaleMode getMode() const;

    /**
     * @brief getTotalTickCount: get scale total tick count
     * @return
     */
    int32_t getTotalTickCount() const;

    /**
     * @brief getMajorTickEvery: get how often the major tick will be drawn
     * @return
     */
    int32_t getMajorTickEvery() const;

    /**
     * @brief getLabelShow: get label visibility
     * @return
     */
    bool getLabelShow() const;

    /**
     * @brief getAngleRange: get angle range of a round scale
     * @return
     */
    uint32_t getAngleRange() const;

    /**
     * @brief getRangeMin: get min range of scale
     * @return
     */
    int32_t getRangeMin() const;

    /**
     * @brief getRangeMax: get max range of scale
     * @return
     */
    int32_t getRangeMax() const;

private:
    int32_t mMin;
    int32_t mMax;
    bool mIsShowLabel;
};

#endif // LVSCALE_H
