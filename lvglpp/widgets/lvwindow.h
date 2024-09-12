#ifndef LVWINDOW_H
#define LVWINDOW_H

#include "lvbaseobject.h"

class LvWindow : public LvBaseObject
{
public:
    LvWindow(LvBaseObject *parent = nullptr);

    /**
     * @brief create: create window
     * @warning must call after initialize a window
     */
    void create();

    /**
     * @brief addTitle: add title to a window
     * @param txt
     * @return
     */
    LvBaseObject *addTitle(const char *txt);

    /**
     * @brief addButton: add button to a window
     * @param icon
     * @param btnWidth
     * @return
     */
    LvBaseObject *addButton(const void *icon, const int32_t &btnWidth);

    /**
     * @brief getHeader: get header of a window
     * @return
     */
    LvBaseObject *getHeader() const;

    /**
     * @brief getContent: get content of a window
     * @return
     */
    LvBaseObject *getContent() const;
};

#endif // LVWINDOW_H
