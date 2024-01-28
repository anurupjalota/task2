#ifndef CSVCLASS_H
#define CSVCLASS_H

#include <QQuickItem>

class CsvClass : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString csvFile READ csvFile WRITE setcsvFile NOTIFY csvFileChanged FINAL)
public:
    CsvClass();
    QString csvFile(){
        return m_csvFile;
    }
    QString read();
signals:
    void csvFileChanged();

public slots:
    void setcsvFile(const QString& csvFile);

private:
    QString m_csvFile;

};

#endif // CSVCLASS_H

