#ifndef MANGAHERE_H
#define MANGAHERE_H

#include "abstractmangasource.h"
#include "mangainfo.h"

class MangaHere : public AbstractMangaSource
{
public:
    explicit MangaHere(NetworkManager *dm);

    bool uptareMangaList(UpdateProgressToken *token) override;
    void updateMangaInfoFinishedLoading(QSharedPointer<DownloadStringJob> job,
                                        QSharedPointer<MangaInfo> info) override;
    Result<QStringList, QString> getPageList(const QString &chapterUrl) override;

private:
    QString dictionaryUrl;
};

#endif  // MANGAHERE_H
