#include <QCoreApplication>
#include <QDate>
#include <QDir>
#include <QFile>
#include <QList>
#include <QStringBuilder>
#include <iostream>
#include <string>

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

int main(int argc, char *argv[]) {

  QTextStream out(stdout);


  QString text("   G\"; \"G; hH:G?H?gh?j");
  text.append("shfjkshdkj sdf");

  out << analyzeTextCharacters(text) << Qt::endl;
  out << text << "\n" ;

  return 0;
}
