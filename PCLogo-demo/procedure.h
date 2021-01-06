#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <QString>
#include <QStringList>
#include <QMap>
#include <QDebug>

//这个命令列表是方便起见写的，与procedure的实现有关。
const QStringList CMD = {"FD", "BK", "RT", "LT", "SETPC", "SETBG", "SETXY", "STAMPOVAL", "REPEAT",
                         "RESET", "CLEAN"};

class Procedure {
public:
    QString name;
    QStringList body;
    QStringList varList;
    Procedure(){}
    Procedure(QStringList wordList, int begin, int end, QMap<QString, Procedure> *defined_procedures){
        this->name = wordList[begin];
        int i;
        for (i = begin+1; i <= end; i++){
            if (CMD.contains(wordList[i]) || defined_procedures->contains(wordList[i])) break;
            else this->varList.append(wordList[i]);
        }
        for (; i <= end; i++){
            this->body.append(wordList[i]);
        }
    }
};

#endif // PROCEDURE_H
