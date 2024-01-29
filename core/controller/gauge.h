#ifndef GAUGE_H
#define GAUGE_H

#include <QObject>

class Gauge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)
public:
    explicit Gauge(QObject *parent = nullptr);

    int speed() const;
    void setSpeed(int newSpeed);

signals:

    void speedChanged();

private:
    int m_speed;
};

#endif // GAUGE_H
