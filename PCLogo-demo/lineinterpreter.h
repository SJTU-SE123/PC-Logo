#ifndef LINEINTERPRETER_H
#define LINEINTERPRETER_H
#include <QString>
#include "command.h"

class LineInterpreter {
public:
    command* parseLine(QString str);
    command* parse(QStringList wordList, int begin, int end);
};

#endif // LINEINTERPRETER_H
