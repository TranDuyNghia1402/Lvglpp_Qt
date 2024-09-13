#ifndef LVMESSAGEBOX_H
#define LVMESSAGEBOX_H

#include "lvbaseobject.h"

class LvMessageBox : public LvBaseObject
{
public:
    LvMessageBox(LvBaseObject *parent);

    /**
     * @brief create: create a message box
     * @warning must call after initialize messagebox
     */
    void create();

    /**
     * @brief addTitle: add title to the message box. It also creates a header for the title.
     * @param title
     */
    void addTitle(const char *title);

    /**
     * @brief addHeaderButton: add a button to the header of to the message box. It also creates a header.
     * @param icon
     */
    void addHeaderButton(const void *icon);

    /**
     * @brief addText: add a button to the header of to the message box. It also creates a header.
     * @param text
     */
    void addText(const char *text);

};
#endif // LVMESSAGEBOX_H
