#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "core/controller/gauge.h"
#include "core/controller/topbar.h"

class Controller {
public:
    Controller(Gauge *gauge,
               TopBar *topBar);

    Gauge *gauge;
    TopBar *topBar;
};

#endif // CONTROLLER_H
