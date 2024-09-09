#ifndef LVBASEOBJECT_H
#define LVBASEOBJECT_H
#include "lvglpp/lvglpptype.h"
#include "../lvstyle.h"

class LvBaseObject : public QObject
{
    Q_OBJECT
public:
    LvBaseObject(LvBaseObject *parent = nullptr);
    LvBaseObject(LvBaseObject *parent, int32_t width = 100, int32_t height = 100);

    ~LvBaseObject();

    /**
     * @brief create: create an object
     * @warning must be called after initialize object
     */
    void create();

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
     * @brief addPropFlag: add properties flag to object
     * @param props
     */
    void addPropFlag(LvPropFlag props);

    /**
     * @brief clearPropFlag: clear properties flag of object
     * @param props
     */
    void clearPropFlag(LvPropFlag props);

    /**
     * @brief setSize: set size of object
     * @param width
     * @param height
     */
    void setSize(const int32_t &width, const int32_t &height);

    /**
     * @brief setWidth: set width of object
     * @param width
     */
    void setWidth(const int32_t &width);

    /**
     * @brief setHeight: set height of object
     * @param height
     */
    void setHeight(const int32_t &height);

    /**
     * @brief getWidght: get width of object
     * @return width of object
     */
    int32_t getWidth() const;

    /**
     * @brief getHeight: get height of object
     * @return height of object
     */
    int32_t getHeight() const;

    /**
     * @brief setX: move object to x position
     * @param x
     */
    void setX(const int32_t &x);

    /**
     * @brief setY: move object to y position
     * @param y
     */
    void setY(const int32_t &y);

    /**
     * @brief setPos: move object to position(x, y)
     * @param x
     * @param y
     */
    void setPos(const int32_t &x, const int32_t &y);

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
    void align(const LvAlign &align, const int32_t &x, const int32_t &y);

    /**
     * @brief setAlign: align object to a specific position without offsets
     * @param align
     */
    void setAlign(const LvAlign &align);

    /**
     * @brief setAlignTo: align object to a reference object
     * @param ref
     * @param align
     * @param x
     * @param y
     */
    void setAlignTo(LvBaseObject *ref, const LvAlign &align, const int32_t &x, const int32_t &y);

    /**
     * @brief setOVerflowVisible: allow the childrens to be draw out of the parent
     * @param isVisible
     */
    void setOVerflowVisible(const bool &isVisible);

    /**
     * @brief addStyle: add style properties to object
     * @param style
     */
    void addStyle(LvObjectStyle &style, const LvSelector &selector = LV_PART_MAIN);

    /**
     * @brief removeStyle: remove specific styles. This function remove style only if the selector
     *                      matches with the selector use in addStyle()
     * @param style
     * @param selector
     */
    void removeStyle(LvObjectStyle &style, const LvSelector &selector);

    /**
     * @brief removeAllStyle: remove all style
     */
    void removeAllStyle();

    /**
     * @brief setScrollBarMode: set scrollbar mode to object
     * @param mode
     */
    void setScrollBarMode(const ScrollBarMode &mode);

    /**
     * @brief setScrollable: set/unset object to be scrollable
     * @param isScrollable
     */
    void setScrollable(const bool &isScrollable);

    /**
     * @brief setScrollDir: set scroll direction
     * @param direction
     */
    void setScrollDir(const ScrollDirection &direction);

    /**
     * @brief scrollBy: scoll by x & y value
     * @param x
     * @param y
     * @param animEn
     */
    void scrollBy(const int32_t &x, const int32_t &y, const LvAnimEnable &animEn);

    /**
     * @brief scrollTo: scroll to bring the given coordinate to the top left corner
     * @param x
     * @param y
     * @param animEn
     */
    void scrollTo(const int32_t &x, const int32_t &y, const LvAnimEnable &animEn);

    /**
     * @brief scrollToX: scroll to bring the given coordinate to the left side
     * @param x
     * @param animEn
     */
    void scrollToX(const int32_t &x, const LvAnimEnable &animEn);

    /**
     * @brief scrollToY: scroll to bring the given coordinate to the top side
     * @param y
     * @param animEn
     */
    void scrollToY(const int32_t &y, const LvAnimEnable &animEn);

    /**
     * @brief setParent: set Parent to Object
     * @param parent
     */
    void setParent(LvBaseObject *parent);

    /**
     * @brief getParent: get object's parent
     * @return mParent
     */
    LvBaseObject *getParent() const;

    /**
     * @brief getChilds: get children at index of object
     * @param index
     * @return childrent at index
     */
    LvBaseObject *getChilds(const int32_t &index);

    /**
     * @brief setBgColor: set object's background color
     * @param color
     * @param selector
     */
    void setBgColor(const LvColor &color, const LvSelector &selector = LV_PART_MAIN);

    /**
     * @brief setBgOpa: set object's background opa
     * @param opa
     * @param selector
     */
    void setBgOpa(const LvOpa &opa, const LvSelector &selector = LV_PART_MAIN);

    /**
     * @brief setBorderWidth: set object's border width
     * @param width
     * @param selector
     */
    void setBorderWidth(const int32_t &width, const LvSelector &selector = LV_PART_MAIN);

    /**
     * @brief setBorderColor: set object's border color
     * @param color
     * @param selector
     */
    void setBorderColor(const LvColor &color, const LvSelector &selector = LV_PART_MAIN);

    /**
     * @brief setBorderOpa: set object's border opa
     * @param opa
     * @param selector
     */
    void setBorderOpa(const LvOpa &opa, const LvSelector &selector = LV_PART_MAIN);

    /**
     * @brief setBorderSide: set object's border side
     * @param borderside
     * @param selector
     */
    void setBorderSide(const LvBorderSide &borderside, const LvSelector &selector = LV_PART_MAIN);

    /**
     * @brief setBorderPost: set object's border post
     * @param value
     * @param selector
     */
    void setBorderPost(const bool &value, const LvSelector &selector = LV_PART_MAIN);

    /**
     * @brief getLvObject: return base object of lvgl
     * @warning do not call this function outside this class
     * @return mLvObject
     */
    LvObj *getLvObject() const;

    /**
     * @brief setLvObject: set basetype of lvObj
     * @warning do not call this function, we dont need it
     * @param obj
     */
    void setLvObject(LvObj *obj);

protected:
    LvBaseObject *mParent = nullptr;
    LvObj *mLvObj = nullptr;

    int32_t mWidth = 100;
    int32_t mHeight = 100;

};

#endif // LVBASEOBJECT_H
