#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QObject>
#include <QTimer>
#include "lvglpp/core/lv_conf.h"
#include "lvglpp/core/lvgl/src/drivers/sdl/lv_sdl_window.h"
#include "lvglpp/widgets/lvbaseobject.h"
#include "lvglpp/widgets/lvcuractivescreen.h"
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

public slots:
    void onLvTickHandler();
    void onLvTimerHandler();

};

#endif // GRAPHIC_H
