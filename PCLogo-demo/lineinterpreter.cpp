#include "lineinterpreter.h"
#include <QDebug>
#include <QStringList>
command* LineInterpreter::parseLine(QString str) {
    str = str.toUpper();
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
    } else if (wordList[begin] == "TO") {
        int endpos;
        for (endpos = begin+1; endpos <= end; endpos++) if (wordList[endpos] == "END") break;   //可能要改进成计算TO和END的个数差进行判断。
        procedures.insert(wordList[begin+1], Procedure(wordList, begin + 1, endpos - 1, & procedures));   //同名procedure默认替换。
        return parse(wordList, endpos + 1, end);
    } else if (procedures.contains(wordList[begin])){   //调用子程序
        Procedure pro = procedures[wordList[begin]];
        QStringList varList;
        for (int i = 1; i <= pro.varList.length(); i++){
            varList.append(wordList[begin+i]);
        }
        if (pro.varList.length() > 0){
            for (int i = 0; i < pro.body.length(); i++){
                for (int j = 0; j < pro.varList.length(); j++){
                    if (pro.body[i] == pro.varList[j]) pro.body[i] = varList[j];
                }
            }
        }
        return new command(PROCEDURE, parse(pro.body, 0, pro.body.length()-1), parse(wordList, begin + pro.varList.length() + 1, end));
    } else return NULL;
}
