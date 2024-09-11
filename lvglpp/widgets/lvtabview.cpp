#include "lvtabview.h"

LvTabview::LvTabview(LvBaseObject *parent) : LvBaseObject(parent) {}

void LvTabview::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_tabview_create(mParent->getLvObject());
    else
        mLvObj = lv_tabview_create(lv_screen_active());
}

LvBaseObject *LvTabview::addTab(const char *tabName)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] tabview was not created!";
        return nullptr;
    }
    LvObj *baseTypeTab = lv_tabview_add_tab(mLvObj, tabName);
    LvBaseObject *tab = new LvBaseObject();
    tab->setLvObject(baseTypeTab);

    mTabNums += 1;

    return tab;
}

void LvTabview::renameTab(const uint32_t &tabIdx, const char *newName)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] tabview was not created!";
        return;
    }
    lv_tabview_rename_tab(mLvObj, tabIdx, newName);
}

void LvTabview::setActive(const uint32_t &tabIdx, const LvAnimEnable &en)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] tabview was not created!";
        return;
    }
    lv_tabview_set_active(mLvObj, tabIdx, en);
}

void LvTabview::moveToNextTab(const LvAnimEnable &en)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] tabview was not created!";
        return;
    }
    mTabIdx++;
    if (mTabIdx >= mTabNums)
        mTabIdx = 0;
    this->setActive(mTabIdx);
}

void LvTabview::moveToPrvTab(const LvAnimEnable &en)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] tabview was not created!";
        return;
    }
    mTabIdx--;
    if (mTabIdx < 0)
        mTabIdx = mTabNums - 1;
    this->setActive(mTabIdx);
}

void LvTabview::setTabBarPosition(const LvDir &direction)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] tabview was not created!";
        return;
    }
    lv_tabview_set_tab_bar_position(mLvObj, direction);
}

void LvTabview::setTabBarSize(const uint32_t &size)
{
    if (!isCreated)
    {
        qDebug() << "[Warning] tabview was not created!";
        return;
    }
    lv_tabview_set_tab_bar_size(mLvObj, size);
}

uint32_t LvTabview::getTabCount() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] tabview was not created!";
        return 0;
    }
    return lv_tabview_get_tab_count(mLvObj);
}

uint32_t LvTabview::getTabActive() const
{
    if (!isCreated)
    {
        qDebug() << "[Warning] tabview was not created!";
        return 0;
    }
    return lv_tabview_get_tab_active(mLvObj);
}

LvBaseObject *LvTabview::getContent() const
{
    LvBaseObject *content = new LvBaseObject();
    content->create();
    LvObj *baseTypeContent = lv_tabview_get_content(mLvObj);
    content->setLvObject(baseTypeContent);

    return content;
}

LvBaseObject *LvTabview::getTabBar() const
{
    LvBaseObject *tabBar = new LvBaseObject();
    tabBar->create();
    LvObj *baseTypeTabBar = lv_tabview_get_tab_bar(mLvObj);
    tabBar->setLvObject(baseTypeTabBar);

    return tabBar;
}
