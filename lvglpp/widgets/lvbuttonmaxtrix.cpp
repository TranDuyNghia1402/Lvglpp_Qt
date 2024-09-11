#include "lvbuttonmaxtrix.h"

LvButtonMaxtrix::LvButtonMaxtrix(LvBaseObject *parent) :
    LvBaseObject(parent)
{}

void LvButtonMaxtrix::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_buttonmatrix_create(mParent->getLvObject());
    else
        mLvObj = lv_buttonmatrix_create(lv_screen_active());
}

void LvButtonMaxtrix::setButtonMap(const char *map[])
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return;
    }
    lv_buttonmatrix_set_map(mLvObj, map);
}

void LvButtonMaxtrix::setCtrlMap(const LvBtnMatrixCtrl ctrlMap[])
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return;
    }
    lv_buttonmatrix_set_ctrl_map(mLvObj, ctrlMap);
}

void LvButtonMaxtrix::setSelected(const uint32_t &idx)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return;
    }
    lv_buttonmatrix_set_selected_button(mLvObj, idx);
}

void LvButtonMaxtrix::setButtonCtrl(const uint32_t &idx, const LvBtnMatrixCtrl &ctrl)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return;
    }
    lv_buttonmatrix_set_button_ctrl(mLvObj, idx, ctrl);
}

void LvButtonMaxtrix::clearButtonCtrl(const uint32_t &idx, const LvBtnMatrixCtrl &ctrl)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return;
    }
    lv_buttonmatrix_clear_button_ctrl(mLvObj, idx, ctrl);
}

void LvButtonMaxtrix::setButtonCtrlAll(const LvBtnMatrixCtrl &ctrl)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return;
    }
    lv_buttonmatrix_set_button_ctrl_all(mLvObj, ctrl);
}

void LvButtonMaxtrix::clearButtonCtrlAll(const LvBtnMatrixCtrl &ctrl)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return;
    }
    lv_buttonmatrix_clear_button_ctrl_all(mLvObj, ctrl);
}

void LvButtonMaxtrix::setButtonWidth(const uint32_t &idx, const uint32_t &width)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return;
    }
    lv_buttonmatrix_set_button_width(mLvObj, idx, width);
}

void LvButtonMaxtrix::setOneChecked(const bool &en)
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return;
    }
    lv_buttonmatrix_set_one_checked(mLvObj, en);
}

const char * const *LvButtonMaxtrix::getMap()
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return nullptr;
    }
    return lv_buttonmatrix_get_map(mLvObj);
}

uint32_t LvButtonMaxtrix::getSelected() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return 0;
    }
    return lv_buttonmatrix_get_selected_button(mLvObj);
}

const char *LvButtonMaxtrix::getText(const uint32_t &idx) const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return nullptr;
    }
    return lv_buttonmatrix_get_button_text(mLvObj, idx);
}

bool LvButtonMaxtrix::isHasCtrl(const uint32_t &idx, const LvBtnMatrixCtrl &ctrl) const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return false;
    }
    return lv_buttonmatrix_has_button_ctrl(mLvObj, idx, ctrl);
}

bool LvButtonMaxtrix::getOneChecked() const
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] Button matrix was not created!";
        return false;
    }
    return lv_buttonmatrix_get_one_checked(mLvObj);
}
