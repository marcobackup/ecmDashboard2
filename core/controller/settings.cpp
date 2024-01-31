#include "settings.h"

Settings::Settings(QObject *parent)
    : QObject{parent}
    , m_settingsIsOpen(false)
    , m_settingsDiagnosysOpen(false)
    , m_settingsViewId(0)
    , m_theme(0)
    , m_language(0)
    , m_audioStatus(true)
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

int Settings::theme() const
{
    return m_theme;
}

void Settings::setTheme(int newTheme)
{
    if (m_theme == newTheme)
        return;
    m_theme = newTheme;
    emit themeChanged();
}

int Settings::language() const
{
    return m_language;
}

void Settings::setLanguage(int newLanguage)
{
    if (m_language == newLanguage)
        return;
    m_language = newLanguage;
    emit languageChanged();
}

bool Settings::audioStatus() const
{
    return m_audioStatus;
}

void Settings::setAudioStatus(bool newAudioStatus)
{
    if (m_audioStatus == newAudioStatus)
        return;
    m_audioStatus = newAudioStatus;
    emit audioStatusChanged();
}
