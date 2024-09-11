#ifndef LVBUTTONMAXTRIX_H
#define LVBUTTONMAXTRIX_H

#include "lvbaseobject.h"

class LvButtonMaxtrix : public LvBaseObject
{
public:
    LvButtonMaxtrix(LvBaseObject *parent = nullptr);

    /**
     * @brief create: create button matrix
     * @warning must call after initialize button matrix
     */
    void create();

    /**
     * @brief setButtonMap: set a new map.
     * @warning Buttons will be created/deleted according to the map. The button matrix keeps a reference to the map
     * and so the string array must not be deallocated during the life of the matrix.
     * @param map: should be declare as static
     */
    void setButtonMap(const char* map[]);

    /**
     * @brief setCtrlMap: set the button control map (hidden, disabled etc.) for a button matrix.
     * The control map array will be copied and so may be deallocated after this function returns.
     * @param ctrlMap
     */
    void setCtrlMap(const LvBtnMatrixCtrl ctrlMap[]);

    /**
     * @brief setSelected: set the selected buttons
     * @param idx
     */
    void setSelected(const uint32_t &idx);

    /**
     * @brief setButtonCtrl: set the attributes of a button of the button matrix
     * @param ctrl
     */
    void setButtonCtrl(const uint32_t &idx, const LvBtnMatrixCtrl &ctrl);

    /**
     * @brief clearButtonCtrl: clear the attributes of a button of the button matrix
     * @param idx
     * @param ctrl
     */
    void clearButtonCtrl(const uint32_t &idx, const LvBtnMatrixCtrl &ctrl);

    /**
     * @brief setButtonCtrlAll: set attributes of all buttons of a button matrix
     * @param ctrl
     */
    void setButtonCtrlAll(const LvBtnMatrixCtrl &ctrl);

    /**
     * @brief clearButtonCtrlAll: clear attributes of all buttons of a button matrix
     * @param ctrl
     */
    void clearButtonCtrlAll(const LvBtnMatrixCtrl &ctrl);

    /**
     * @brief setButtonWidth: set a single button's relative width.
     * @warning This method will cause the matrix be regenerated and is a relatively expensive operation.
     * It is recommended that initial width be specified using lv_buttonmatrix_set_ctrl_map
     * and this method only be used for dynamic changes.
     * @param idx
     * @param width
     */
    void setButtonWidth(const uint32_t &idx, const uint32_t &width);

    /**
     * @brief setOneChecked: make the button matrix like a selector widget (only one button may be checked at a time).
     * @warning LV_BUTTONMATRIX_CTRL_CHECKABLE must be enabled on the buttons to be selected using lv_buttonmatrix_set_ctrl()
     * or lv_buttonmatrix_set_button_ctrl_all()
     * @param en
     */
    void setOneChecked(const bool &en);

    /**
     * @brief getMap: get the current map of a button matrix
     * @return
     */
    const char * const *getMap();

    /**
     * @brief getSelected: get the index of the lastly "activated" button by the user (pressed, released, focused etc)
     * @return
     */
    uint32_t getSelected() const;

    /**
     * @brief getText: get the button's text
     * @return
     */
    const char *getText(const uint32_t &idx) const;

    /**
     * @brief isHasCtrl: get the whether a control value is enabled or disabled for button of a button matrix
     * @param idx
     * @param ctrl
     * @return
     */
    bool isHasCtrl(const uint32_t &idx, const LvBtnMatrixCtrl &ctrl) const;

    /**
     * @brief getOneChecked: tell whether "one check" mode is enabled or not.
     * @return
     */
    bool getOneChecked() const;

private:
};

#endif // LVBUTTONMAXTRIX_H
