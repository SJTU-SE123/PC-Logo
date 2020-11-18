#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QMessageBox>
#include <QAudioInput>
#include <QFile>
class Audio : public QObject
{
    Q_OBJECT
public:
    explicit Audio(QObject *parent = nullptr);
    void startAudio(QString fileName);
    void stopAudio();
signals:
private:
    QAudioInput *m_audio;
    QFile *m_file;
};
#endif // AUDIO_H
