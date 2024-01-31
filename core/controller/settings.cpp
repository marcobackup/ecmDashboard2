#include "settings.h"

Settings::Settings(QObject *parent)
    : QObject{parent}
    , m_settingsIsOpen(false)
    , m_settingsDiagnosysOpen(false)
    , m_settingsViewId(0)
{
}

bool Settings::settingsIsOpen() const
{
    return m_settingsIsOpen;
}

void Settings::setSettingsIsOpen(bool newSettingsIsOpen)
{
    if (m_settingsIsOpen == newSettingsIsOpen)
        return;
    m_settingsIsOpen = newSettingsIsOpen;
    emit settingsIsOpenChanged();
}

bool Settings::settingsDiagnosysOpen() const
{
    return m_settingsDiagnosysOpen;
}

void Settings::setSettingsDiagnosysOpen(bool newSettingsDiagnosysOpen)
{
    if (m_settingsDiagnosysOpen == newSettingsDiagnosysOpen)
        return;
    m_settingsDiagnosysOpen = newSettingsDiagnosysOpen;
    emit settingsDiagnosysOpenChanged();
}

int Settings::settingsViewId() const
{
    return m_settingsViewId;
}

void Settings::setSettingsViewId(int newSettingsViewId)
{
    if (m_settingsViewId == newSettingsViewId)
        return;
    m_settingsViewId = newSettingsViewId;
    emit settingsViewIdChanged();
}
