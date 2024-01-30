#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "core/controller/gauge.h"
#include "core/controller/carparameter.h"
#include "core/controller/trip.h"
#include "core/controller/topbar.h"
#include "core/controller/bottombar.h"

class Controller {
public:
    Controller(Gauge *gauge,
               CarParameter *carParameter,
               Trip *trip,
               TopBar *topBar,
               BottomBar *bottomBar);

    Gauge *gauge;
    CarParameter *carParameter;
    Trip *trip;
    TopBar *topBar;
    BottomBar *bottomBar;
};

#endif // CONTROLLER_H
