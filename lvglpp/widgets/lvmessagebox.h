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
};

#endif // LVMESSAGEBOX_H
