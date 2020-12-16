#ifndef LINEINTERPRETER_H
#define LINEINTERPRETER_H
#include <QString>
#include <QMap>
#include "command.h"
#include "procedure.h"

class LineInterpreter {
public:
    command* parseLine(QString str);
    command* parse(QStringList wordList, int begin, int end);

private:
    QMap<QString, Procedure> procedures;
};

#endif // LINEINTERPRETER_H
