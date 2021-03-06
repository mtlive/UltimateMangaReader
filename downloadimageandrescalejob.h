#ifndef DOWNLOADIMAGEANDRESCALEJOB_H
#define DOWNLOADIMAGEANDRESCALEJOB_H

#include <QImage>

#include "downloadfilejob.h"

class DownloadScaledImageJob : public DownloadFileJob
{
    Q_OBJECT

public:
    DownloadScaledImageJob(QNetworkAccessManager *networkManager, const QString &url, const QString &path,
                           QSize imgSize, bool flipVerticalImage, bool trimImage,
                           const QList<std::tuple<const char *, const char *>> &customHeaders = {});

signals:

public slots:
    virtual void downloadFileReadyRead() override;
    virtual void downloadFileFinished() override;

private:
    QSize imgSize;
    bool trimImage;
    bool flipVerticalImage;

    bool processImage(const QByteArray &array);
    QImage rescaleImage(const QImage &img);
    QRect getTrimRect(const QImage &image);
};

#endif  // DOWNLOADIMAGEANDRESCALEJOB_H
