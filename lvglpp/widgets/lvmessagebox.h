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
     * @return
     */
    LvBaseObject *addTitle(const char *title);

    /**
     * @brief addHeaderButton: add a button to the header of to the message box. It also creates a header.
     * @param icon
     * @return
     */
    LvBaseObject *addHeaderButton(const void *icon);

    /**
     * @brief addText: add a button to the header of to the message box. It also creates a header.
     * @param text
     * @return
     */
    LvBaseObject *addText(const char *text);

    /**
     * @brief addFooterButton
     * @param text
     * @return
     */
    LvBaseObject *addFooterButton(const char *text);

    /**
     * @brief addCloseButton: add a close button to the messagebox.It also creates a header
     * @return
     */
    LvBaseObject *addCloseButton();

};
#endif // LVMESSAGEBOX_H
