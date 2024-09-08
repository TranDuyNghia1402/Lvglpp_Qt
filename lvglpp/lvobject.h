#ifndef LVOBJECT_H
#define LVOBJECT_H

#include <QObject>
#include "lvglpp/lvglpptype.h"

class LvObject : public QObject
{
    Q_OBJECT
public:
    LvObject(LvObject *parent, int32_t width = 50, int32_t heigth = 50);
    LvObject();
    ~LvObject();

    /**
     * @brief destroy: delete object & its childrens
     */
    void destroy();

    /**
     * @brief clean: delete all of its childrens
     * @warning shouldn't call this function, im not sure about it :)
     */
    void clean();

    /**
     * @brief hide: disable object
     */
    void hide();

    /**
     * @brief show: enable object
     */
    void show();

    /**
     * @brief setSize: set size of object
     * @param width
     * @param height
     */
    void setSize(int32_t width, int32_t height);

    /**
     * @brief setWidth: set width of object
     * @param width
     */
    void setWidth(int32_t width);

    /**
     * @brief setHeight: set height of object
     * @param height
     */
    void setHeight(int32_t height);

    /**
     * @brief getWidght: get width of object
     * @return width of object
     */
    int32_t getWidght();

    /**
     * @brief getHeight: get height of object
     * @return height of object
     */
    int32_t getHeight();

    /**
     * @brief setX: move object to x position
     * @param x
     */
    void setX(int32_t x);

    /**
     * @brief setY: move object to y position
     * @param y
     */
    void setY(int32_t y);

    /**
     * @brief setPos: move object to position(x, y)
     * @param x
     * @param y
     */
    void setPos(int32_t x, int32_t y);

    /**
     * @brief center: move object to center of its parent
     */
    void center();

    /**
     * @brief align: align object to a specific position with offsets
     * @param align
     * @param x
     * @param y
     */
    void align(LvAlign align, int32_t x, int32_t y);

    /**
     * @brief setAlign: align object to a specific position without offsets
     * @param align
     */
    void setAlign(LvAlign align);

    /**
     * @brief setAlignTo: align object to a reference object
     * @param ref
     * @param align
     * @param x
     * @param y
     */
    void setAlignTo(LvObject *ref, LvAlign align, int32_t x, int32_t y);

    /**
     * @brief setOVerflowVisible: allow the childrens to be draw out of the parent
     * @param isVisible
     */
    void setOVerflowVisible(bool isVisible);

    /**
     * @brief getLvObject: return base object of lvgl
     * @warning do not call this function outside this class
     * @return mLvObject
     */
    LvObj *getLvObject();
private:
    LvObject *mParent = nullptr;
    LvObj *mLvObj = nullptr;

    int32_t mWidth = 0;
    int32_t mHeight = 0;
signals:

public slots:

};

#endif // LVOBJECT_H
