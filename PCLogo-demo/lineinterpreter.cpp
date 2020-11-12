#include "lineinterpreter.h"
#include <QDebug>
#include <QStringList>
command* LineInterpreter::parseLine(QString str) {
   QStringList lineList = str.split("\n");
   QStringList wordList;
   for (auto line : lineList) {
       QStringList tmp = line.split(" ");
       wordList.append(tmp);
   }
   return this->parse(wordList, 0, wordList.length() - 1);
}

command* LineInterpreter::parse(QStringList wordList, int begin, int end) {
    if (begin > end) return NULL;
    if (wordList[begin] == "FD") {
        return new command(STRAIGHTMOVE, wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "BK") {
        return new command(STRAIGHTMOVE, -wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "RT") {
        return new command(SETANGLE, wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "LT") {
        return new command(SETANGLE, -wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "SETPC") {
        return new command(SETPC, wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "SETBG") {
        return new command(SETBG, wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "SETXY") {
        return new command(SETXY, wordList[begin + 1].toInt(), wordList[begin + 2].toInt(), parse(wordList, begin+3, end));
    } else if (wordList[begin] == "STAMPOVAL") {
        return new command(OVALMOVE, wordList[begin + 1].toInt(), wordList[begin + 2].toInt(), parse(wordList, begin+3, end));
    } else if (wordList[begin] == "REPEAT") {
        int cnt = 0, i;
        for (i=begin; i<=end; i++) {
            if (wordList[i] == "[") ++cnt;
            else if (wordList[i] == "]") {
                --cnt;
                if (!cnt) break;
            }
        }
        return new command(REPEAT, wordList[begin + 1].toInt(), parse(wordList, begin + 3, i - 1), parse(wordList, i + 1, end));
    } else return NULL;
}
