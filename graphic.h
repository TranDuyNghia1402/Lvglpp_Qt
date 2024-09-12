#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QObject>
#include <QTimer>
#include "lvglpp/core/lv_conf.h"
#include "lvglpp/core/lvgl/src/drivers/sdl/lv_sdl_window.h"
#include "lvglpp/widgets/lvbaseobject.h"
#include "lvglpp/widgets/lvcuractivescreen.h"
#include "lvglpp/widgets/lvlabel.h"
#include "lvglpp/widgets/lvbutton.h"
#include "lvglpp/widgets/lvscale.h"
#include "lvglpp/widgets/lvimage.h"
#include "lvglpp/widgets/lvbuttonmaxtrix.h"
#include "lvglpp/widgets/lvtabview.h"
#include "lvglpp/widgets/lvlist.h"
#include "lvglpp/widgets/lvline.h"
#include "lvglpp/widgets/lvwindow.h"
#include "lvglpp/lvstyle.h"

#define MONITOR_WIDTH   1280
#define MONITOR_HEIGHT  720

class Graphic : public QObject
{
    Q_OBJECT
public:
    Graphic();

private:
    QTimer *lvTickTimer = nullptr;
    QTimer *lvTimeTimer = nullptr;

    void halInit(void);
    void drawSomething(void);

    LvImage *backGround = nullptr;
    LvBaseObject *base = nullptr;
    LvTabview *tabview = nullptr;

    LvButton *tab1Button = nullptr;
    LvButton *tab2Button = nullptr;
    LvButton *tab3Button = nullptr;

    LvScale *scale = nullptr;

    QTimer *autoPressTimer = nullptr;

public slots:
    void onLvTickHandler();
    void onLvTimerHandler();

    void onButton1Pressed();
    void onButton2Pressed();
    void onButton3Pressed();

    void onAutoPressTimerHandler();
};

#endif // GRAPHIC_H
