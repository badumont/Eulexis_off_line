#ifndef LEMMAT_H
#define LEMMAT_H

#include <QDebug>
#include <QTextStream>
#include <QDir>
#include <QMap>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QProgressDialog>

class Lemmat
{
public:
    Lemmat(QString rep);
    void lireData();
    QStringList lemmatise(QString f, bool beta = true);
    QStringList lem2csv(QString f, bool beta = true);
    QString beta2unicode(QString f,bool beta = true);
    QString uni2betacode(QString f);
    QString nettoie(QString f);
    QString nettoie2(QString res);
    void majLSJ(QString nom);
    void lireAbrBailly();
    void lireLSJ();
    void lirePape();
    QStringList consLSJ(QString f);
    QStringList consAbrBailly(QString f);
    QStringList consPape(QString f);
    void majPape(QString nom);
    void majAbrBailly(QString nom);
    void majAnalyses(QString nom);
    QStringList consult(QString nom, QStringList llem, QString prefix);
    void indexCommun();
    QString traduction(QString lem);
    void setCible(int lang);
    int cible();
    void lireAnalyses();
    void lireTraductions();

private:
    QString _rscrDir;
    QMap<QString,QString> _formes;
    QMap<QString,QString> _trad;
    int _cible; // Choix de la langue 0 = Anglais ; 1 = Français.
    QMultiMap<QString,QString> _LSJindex;
    QMultiMap<QString,QString> _PapeIndex;
    QMultiMap<QString,QString> _AbrBaillyIndex;
    QString _LSJname;
    QString _PapeName;
    QString _AbrBaillyName;
    QStringList _beta;
    QStringList _uni;
    QRegExp rePonct;
    QRegExp reLettres;
    QString lierRenvois(QString article, QString renvoi);
    void verif(QString ligne);
    QStringList _refLSJ;
    QStringList _tmpLSJ;
    QStringList _renLSJ;
};

#endif // LEMMAT_H
