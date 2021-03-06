#ifndef JAIMINISBOX_H
#define JAIMINISBOX_H

#include "abstractmangasource.h"
#include "mangainfo.h"

class JaiminisBox : public AbstractMangaSource
{
public:
    explicit JaiminisBox(NetworkManager *dm);

    bool uptareMangaList(UpdateProgressToken *token) override;

    void updateMangaInfoFinishedLoading(QSharedPointer<DownloadStringJob> job,
                                        QSharedPointer<MangaInfo> info) override;
    Result<QStringList, QString> getPageList(const QString &chapterUrl) override;

private:
    QString dictionaryUrl;
};

#endif  // JAIMINISBOX_H
