#include "controller.h"

Controller::Controller(Gauge *gauge, CarParameter *carParameter, Trip *trip, TopBar *topBar, BottomBar *bottomBar)
    : gauge(gauge)
    , carParameter(carParameter)
    , trip(trip)
    , topBar(topBar)
    , bottomBar(bottomBar)
{}
