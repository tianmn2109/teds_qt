#ifndef DOMPARSER_H
#define DOMPARSER_H
#include <QTreeWidget>
#include <QDomElement>
#include "teds.h"

class DomParser
{
public:
    DomParser();
    bool readMetaTedsFile(const QString & filename);
    bool readPhyTedsFile(const QString & filename);
    bool readTransducerTedsFile(const QString & filename);

    QString strPhy;
    QString strMeta;
    QString strTs;

private:
    void parseMetaTeds(const QDomElement & element);
    void parsePhyTeds(const QDomElement & element);
    void parseTransducerTeds(const QDomElement & element);

   // QTreeWidget * treeWidget;
    QDomDocument doc;
    Meta_TEDS * meta;
    Phy_TEDS * phy;

    Transducerchannel_TEDS * ts;
};

#endif // DOMPARSER_H
