#ifndef LVTABVIEW_H
#define LVTABVIEW_H

#include "lvbaseobject.h"

class LvTabview : public LvBaseObject
{
public:
    LvTabview(LvBaseObject *parent = nullptr);

    /**
     * @brief create: create tabview widget
     * @warning must call this funtion after initialize tabview
     */
    void create();

    /**
     * @brief addTab: add a tab to tabview
     * @param tabName: const char*
     */
    LvBaseObject *addTab(const char* tabName);

    /**
     * @brief renameTab: change the name of the tab at index
     * @param tabIdx: the index of the tab to rename
     * @param newName: the new name of the tab
     */
    void renameTab(const uint32_t &tabIdx, const char* newName);

    /**
     * @brief setActive: show a tab
     * @param tabIdx: the index of the tab to show
     * @param en: LV_ANIM_ON/OFF
     */
    void setActive(const uint32_t &tabIdx, const LvAnimEnable &en = LV_ANIM_OFF);

    /**
     * @brief moveToNextTab: move to next tab of tabview
     * @param en
     */
    void moveToNextTab(const LvAnimEnable &en = LV_ANIM_OFF);

    /**
     * @brief moveToPrvTab: move to previous tab of tabview
     * @param en
     */
    void moveToPrvTab(const LvAnimEnable &en = LV_ANIM_OFF);

    /**
     * @brief setTabBarPos: set the position of the tab bar
     * @param direction: LV_DIR_TOP/BOTTOM/LEFT/RIGHT
     */
    void setTabBarPosition(const LvDir &direction);

    /**
     * @brief setTabBarSize: set the width or height of the tab bar
     * @param size
     */
    void setTabBarSize(const uint32_t &size);

    /**
     * @brief getTabCount: get the number of tabs
     * @return
     */
    uint32_t getTabCount() const;

    /**
     * @brief getTabActive: get the current tab's index
     * @return
     */
    uint32_t getTabActive() const;

    /**
     * @brief getContent: get the widget where the container of each tab is created
     * @return
     */
    LvBaseObject *getContent() const;

    /**
     * @brief getTabBar: get the tab bar where the buttons are created
     * @return
     */
    LvBaseObject *getTabBar() const;


private:
    int32_t mTabNums = 0;
    int32_t mTabIdx = 0;

};

#endif // LVTABVIEW_H
