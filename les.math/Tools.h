#ifndef TOOLS_H
#define TOOLS_H

#include "TopologyIcon.h"
#include "TopologyLine.h"
#include <list>
#include <qdebug.h>
#include <QDir>
#include <QStringList>

using namespace std;
class Tools
{
private:
    list<TopologyIcon *>  commonIcons;
    list<TopologyLine *>  commonLines;

public:
    Tools();

    list<TopologyIcon *> getDatabaseIcons();
    list<TopologyLine *> getDatabaseLines();

    void setDatabaseIcons(TopologyIcon *icon);
    void setDatabaseLines();
};

#endif // TOOLS_H
