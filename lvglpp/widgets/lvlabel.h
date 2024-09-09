#ifndef LVLABEL_H
#define LVLABEL_H

#include "lvbaseobject.h"

class LvLabel : public LvBaseObject
{
public:
    LvLabel(LvBaseObject *parent = nullptr, QString text = "Text");

    /**
     * @brief create: create label
     * @warning must call after initialize label
     */
    void create();

    /**
     * @brief setText: set Text to label
     * @param text
     */
    void setText(const QString &text);

    /**
     * @brief getText: get content of label
     * @return QString
     */
    QString getText() const;

    /**
     * @brief setTextAlign: set align for text of label
     * @param align
     */
    void setTextAlign(const LvTextAlign &align);

    /**
     * @brief setLongMode: handle mode when text is longer than label
     * @param mode
     */
    void setLongMode(const LvLabelLongMode &mode);

    /**
     * @brief setFont: set text font of label
     * @param font
     * @param selector
     */
    void setFont(const LvFont &font, const LvSelector &selector = LV_PART_MAIN);

    /**
     * @brief setTextColor: set text color of label
     * @param color
     * @param selector
     */
    void setTextColor(const LvColor &color, const LvSelector &selector = LV_PART_MAIN);

private:
    QString mContent;
};

#endif // LVLABEL_H
