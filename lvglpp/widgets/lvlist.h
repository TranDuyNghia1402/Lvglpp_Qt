#ifndef LVLIST_H
#define LVLIST_H

/**
 *
 * Parts and Styles
 * Background
 * - LV_PART_MAIN The main part of the list that uses all the typical background properties
 * - LV_PART_SCROLLBAR The scrollbar. See the Base objects documentation for details.
 */

#include "lvbaseobject.h"
#include "lvlabel.h"

class LvList : public LvBaseObject
{
public:
    LvList(LvBaseObject *parent = nullptr);

    /**
     * @brief create: create a list
     * @warning must call after initialize a list
     */
    void create();

    /**
     * @brief addText: add text to a list
     * @param txt
     * @return
     */
    LvBaseObject *addText(const char *txt);

    /**
     * @brief addButton: add button to a list
     * @param button
     * @return
     */
    LvBaseObject *addButton(const void *icon, const char *txt);

    /**
     * @brief getButtonText: get text of a given list button
     * @param btn
     * @return
     */
    const char *getButtonText(LvBaseObject *btn) const;

    /**
     * @brief setButtonText: set text of a given list button
     * @param button
     * @param txt
     */
    void setButtonText(LvBaseObject *button, const char *txt);

private:
};

#endif // LVLIST_H
