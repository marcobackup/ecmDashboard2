#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool settingsIsOpen READ settingsIsOpen WRITE setSettingsIsOpen NOTIFY settingsIsOpenChanged)
    Q_PROPERTY(bool settingsDiagnosysOpen READ settingsDiagnosysOpen WRITE setSettingsDiagnosysOpen NOTIFY settingsDiagnosysOpenChanged)
    Q_PROPERTY(int settingsViewId READ settingsViewId WRITE setSettingsViewId NOTIFY settingsViewIdChanged)
public:
    explicit Settings(QObject *parent = nullptr);

    bool settingsIsOpen() const;
    void setSettingsIsOpen(bool newSettingsIsOpen);

    bool settingsDiagnosysOpen() const;
    void setSettingsDiagnosysOpen(bool newSettingsDiagnosysOpen);

    int settingsViewId() const;
    void setSettingsViewId(int newSettingsViewId);

signals:

    void settingsIsOpenChanged();
    void settingsDiagnosysOpenChanged();

    void settingsViewIdChanged();

private:
    bool m_settingsIsOpen;
    bool m_settingsDiagnosysOpen;
    int m_settingsViewId;
};

#endif // SETTINGS_H
