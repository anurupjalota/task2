#include "csvclass.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

CsvClass::CsvClass() {
    setObjectName("cppCsvClass");
    read();
}

QString CsvClass::read(){

    QFile file("task2.csv");
    QString fileContent;
    if ( file.open(QIODevice::ReadOnly) ) {
        QString line;
        QTextStream t( &file );
        do {
            line = t.readLine();
            fileContent += line+"\n";
        } while (!line.isNull());

        file.close();
    } else {
        qDebug() << "Error in reading file";
        return QString("Error");
    }
    m_csvFile = fileContent;
    return fileContent;
}

void CsvClass::setcsvFile(const QString& csvFile){
    m_csvFile = csvFile;
}
