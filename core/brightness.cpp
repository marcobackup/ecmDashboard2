#include "brightness.h"

Brightness::Brightness(QObject *parent)
    : QObject{parent}
    , brightnessFile(*new QFile("/sys/class/backlight/10-0045/brightness"))
    , powerFile(*new QFile("/sys/class/backlight/10-0045/bl_power"))
{
    brightnessFile.setFileName("/sys/class/backlight/10-0045/brightness");
    powerFile.setFileName("/sys/class/backlight/10-0045/bl_power");
}

Brightness::~Brightness()
{
    delete &brightnessFile;
    delete &powerFile;
}

bool Brightness::openFile(QFile &file) {
    if(file.open(QIODevice::ReadWrite))
        return false;
    return true;
}

QByteArray Brightness::getBrightness() {
    if(!Brightness::openFile(brightnessFile))
        return 0;
    return brightnessFile.readAll();
}

void Brightness::setBrightness(int brightness) {
    if(!Brightness::openFile(brightnessFile))
        return;
    brightnessFile.write((char *) brightness);
}

void Brightness::powerOff() {
    if(!Brightness::openFile(brightnessFile))
        return;
    brightnessFile.write((char *) 1);
}

void Brightness::powerOn() {
    if(!Brightness::openFile(brightnessFile))
        return;
    brightnessFile.write((char *) 0);
}
