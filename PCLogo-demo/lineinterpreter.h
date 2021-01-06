#ifndef LINEINTERPRETER_H
#define LINEINTERPRETER_H
#include <QString>
#include <QMap>
#include "command.h"
#include "procedure.h"

class LineInterpreter {
public:
    LineInterpreter();
    command* parseLine(QString str);
    command* parse(QStringList wordList, int begin, int end, bool repeatFlag=true);

private:
    QMap<QString, Procedure> *procedures;
};

#endif // LINEINTERPRETER_H
