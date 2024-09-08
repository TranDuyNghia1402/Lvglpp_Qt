#ifndef LVOBJECT_H
#define LVOBJECT_H

#include <QObject>
#include "lvglpp/lvglpptype.h"

class LvObject : public QObject
{
    Q_OBJECT
public:
    LvObject(LvObject *parent);
    LvObject();
    /**
     * @brief getLvObject: return base object of lvgl
     * @warning do not call this function outside this class
     * @return mLvObject
     */
    LvObj *getLvObject();
private:
    LvObject *mParent = nullptr;

    LvObj *mLvObj = nullptr;
signals:

public slots:

};

#endif // LVOBJECT_H
