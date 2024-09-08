#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QObject>
#include <QTimer>
#include "lvglpp/lvglpptype.h"

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


public slots:
    void onLvTickHandler();
    void onLvTimerHandler();

};

#endif // GRAPHIC_H
