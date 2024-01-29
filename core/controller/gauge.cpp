#include "gauge.h"

Gauge::Gauge(QObject *parent)
    : QObject{parent}
    , m_speed(0)
{
}

int Gauge::speed() const
{
    return m_speed;
}

void Gauge::setSpeed(int newSpeed)
{
    if (m_speed == newSpeed)
        return;
    m_speed = newSpeed;
    emit speedChanged();
}
