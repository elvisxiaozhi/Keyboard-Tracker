#ifndef INITIALISATION_H
#define INITIALISATION_H

#include <QSettings>

class Initialisation
{
public:
    Initialisation();
    static QSettings settings;
    static QSettings startOnBoot;

    static void writeInitXml();
};

#endif // INITIALISATION_H
