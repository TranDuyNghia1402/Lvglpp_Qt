#ifndef LVDROPDOWNLIST_H
#define LVDROPDOWNLIST_H

#include "lvbaseobject.h"

class LvDropDownList : public LvBaseObject
{
public:
    LvDropDownList(LvBaseObject *parent = nullptr);

    /**
     * @brief create: create dropdown list
     * @warning must call after initialize the list
     */
    void create();

    /**
     * @brief setText: set text of the drop-down list's button.
     * If set to NULL the selected option's text will be displayed on the button.
     * If set to a specific text then that text will be shown regardless of the selected option.
     * @param txt
     */
    void setText(const char *txt);

    /**
     * @brief setOption: set the options in a drop-down list from a string.
     * The options will be copied and saved in the object so the options can be destroyed after calling this function
     * @param options
     */
    void setOptions(const char *options);

    /**
     * @brief setOptionsStatic: set the options in a drop-down list from a static string (global, static or dynamically allocated).
     * Only the pointer of the option string will be saved
     * @param options
     */
    void setOptionsStatic(const char *options);

    /**
     * @brief addOption: add an options to a drop-down list from a string.
     * @warning Only works for non-static options.
     * @param option
     * @param pos
     */
    void addOption(const char* option, const uint32_t &pos);

    /**
     * @brief clearOption: clear all options in a drop-down list. Works with both static and dynamic options.
     */
    void clearOption();

    /**
     * @brief setSelected: set the selected option
     * @param idx
     */
    void setSelected(const uint32_t &idx);

    /**
     * @brief setDir: set the direction of the dropdown list
     * @param dir
     */
    void setDir(const LvDir &dir);

    /**
     * @brief setSelectedHighlight: set whether the selected option in the list should be highlighted or not
     * @param en
     */
    void setSelectedHighlight(const bool &en);

    /**
     * @brief getList: get the list of a dropdown to allow styling or other modifications
     * @return
     */
    LvBaseObject *getList() const;

    /**
     * @brief getText: get the text of the dropdown list's button
     * @return
     */
    const char *getText() const;

    /**
     * @brief getOption: get the options of a dropdown list
     * @return
     */
    const char *getOption() const;

    /**
     * @brief getSelected: get the index of the selected option
     * @return
     */
    uint32_t getSelected() const;

    /**
     * @brief getOptionsCount: get the number of option
     * @return
     */
    uint32_t getOptionsCount() const;

    /**
     * @brief getSelectedString: get the current selected option as a string
     * @return
     */
    QString getSelectedString(const uint32_t &buffSize) const;

    /**
     * @brief getOptionIndex: get the index of a option
     * @param option
     * @return
     */
    int32_t getOptionIndex(const char *option) const;

    /**
     * @brief getSymbol: get the symbol on the drop-down list. Typically a down caret or arrow.
     * @return
     */
    QString getSymbol() const;

    /**
     * @brief getSelectedHighlight: get whether the selected option in the list should be highlighted or not
     * @return
     */
    bool getSelectedHighlight() const;

    /**
     * @brief getDir: get the direction of a dropdown list
     * @return
     */
    LvDir getDir() const;

    /**
     * @brief open: open the dropdown list
     */
    void open();

    /**
     * @brief close: close a dropdown list
     */
    void close();

    /**
     * @brief isOpen: tells whether the list is open or not
     * @return
     */
    bool isOpen() const;

private:

};

#endif // LVDROPDOWNLIST_H
