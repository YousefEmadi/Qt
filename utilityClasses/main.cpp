#include <QCoreApplication>
#include <QDate>
#include <QDir>
#include <QFile>
#include <QList>
#include <QStringBuilder>
#include <iostream>
#include <string>
#include <QProcess>

int logToFile(QString path, QString filename, QString data) {
    path = QDir::homePath() + "/" + path;
    QDir dir(path);
    if (!dir.exists()) {
        dir.mkpath(path);
    }

    QFile file(path + "/" + filename);
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return 1;
    QTextStream out(&file);
    out << data << "\n";
    file.close();
    return (0);
}

QString readLogFile(QString filepath) {
    QFile file(filepath);
    QString logData = "";

    if (file.open(QFile::ReadOnly)) {

        QTextStream in(&file);

        /*
     *
    // for reading line by line
    QTextStream out(stdout);
    while (!file.atEnd()) {
        line = file.readLine();
        out << line ;
        logData.append(line);
    }
    */
        logData = in.readAll();
    }
    return logData;
}

QString analyzeTextCharacters(QString text) {
    int characters = 0, letters = 0, digits = 0, spaces = 0, punctuations = 0;
    for (auto ch: text){
        characters++;
        if (ch.isLetter()) letters++;
        if (ch.isDigit()) digits++;
        if (ch.isSpace()) spaces++;
        if (ch.isPunct()) punctuations++;
    }
    QString result("your text has %1 characters including %2 letters, %3 digits, %4 spaces, and %5 punctuations\n");
    return result.arg(characters).arg(letters).arg(digits).arg(spaces).arg(punctuations);
}

/*
  QString text("this is some log text generated in %1 and sending to %2");
  QDateTime datetime = QDateTime::currentDateTime();
  QString path = QDir::homePath();
  out << text.arg(datetime.toString(), path) ;
 * */

void printIt(const char ch){
    QTextStream out(stdout);
    out << ch << Qt::endl;
}

void printIt(const QString str){
    QTextStream out(stdout);
    out << str << Qt::endl;
}

void printIt(const int & i){
    QTextStream out(stdout);
    out << i << Qt::endl;
}


#include <QDebug>
void showingQuickPrints() {
    QString s = "Yousef";
    qDebug() << "hello" << s;;
    QMap<QString, QString> map;
    map["username"] = "Yousef";
    map["password"] = "abcdef";

    qDebug() << map;


    qCritical() << "uh oh we had an error";
}

int main(int argc, char *argv[]) {


    QTextStream out(stdout);

    QFile file("/home/yousef/qt_projects/Qt/utilityClasses/myfile.txt");

    file.open(QIODevice::ReadWrite);
    auto text = file.readAll();

    out << text << "\n" ;

    out << text.indexOf("ad");

    int pointer = 0;

    while ((pointer = text.indexOf("ad", pointer)) >= 0 ){
        out << pointer << ": ";
        pointer++;
        out << text.mid(pointer-2, 4) << "\n";
    }

    QTextStream intofile(&file);

    intofile << "searched\n";

    if (!file.exists("/home/yousef/qt_projects/Qt/utilityClasses/myfil2e.txt")){
        file.copy("/home/yousef/qt_projects/Qt/utilityClasses/myfil2e.txt");
        out << "file copied";
    }else{
        qWarning("already exists");
    }

    file.close();

    auto permissions = file.permissions();

    out << "permissions : " << permissions << "\n";

    permissions.setFlag(QFileDevice::WriteOther);

    QFileInfo info(file);

    out << "info : " << info.permissions() << "\n";

    out << "readowner : " << QFile::ReadWrite ;


    QDir dir(QDir::homePath());

    out <<  dir.path() << "\n" ;

    out << dir.entryInfoList().count() << "\n";

    auto list = dir.entryInfoList();

    auto list2 = dir.entryList() ;




    for (auto l : list) {
        out << l.baseName() << "\t" ;
        out << l.size() << "\n" ;
    }








    return 0;
}
