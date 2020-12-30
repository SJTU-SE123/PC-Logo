#include "lineinterpreter.h"
#include <QDebug>
#include <QStringList>
#include "localmode.h"

command* LineInterpreter::parseLine(QString str) {
    str = str.toUpper();
    QStringList lineList = str.split("\n");
    QStringList wordList;
//    for (int i = 0; i < lineList.size(); ++i) {
//        if(i != lineList.size() - 1)lineList[i] += " $";
//        qDebug()<<lineList[i];
//        QStringList tmp = lineList[i].split(" ");
//        wordList.append(tmp);
//        qDebug()<<wordList;
//    }
    for (auto line : lineList) {
//        if(line == lineList.end())
        line += " $";
        QStringList tmp = line.split(" ");
        wordList.append(tmp);
    }
    return this->parse(wordList, 0, wordList.length() - 1);
}

command* LineInterpreter::parse(QStringList wordList, int begin, int end) {
    if (wordList[begin] == "$"){
        if (begin+1 > end) return nullptr;
        lineNumber++;
        return parse(wordList, begin+1, end);
    }
    if (wordList[begin] == "" && lineNumber != 0){
        qDebug()<<"reminder:  "<<reminder;
        return parse(wordList, begin+1, end);
    }
    if (wordList[begin] == "")return nullptr;
    if (begin > end) return nullptr;
    bool flag;
    if (wordList[begin] == "FD") {
        reminder = "前进（FD）";
        wordList[begin + 1].toInt(&flag);
        if(!flag)reminder += " 指令参数错误,请重新输入";
        return new command(STRAIGHTMOVE, wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "BK") {
        reminder = "后退（BK）";
        wordList[begin + 1].toInt(&flag);
        if(!flag)reminder += " 指令参数错误,请重新输入";
        return new command(STRAIGHTMOVE, -wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "RT") {
        reminder = "左转（RT）";
        wordList[begin + 1].toInt(&flag);
        if(!flag)reminder += " 指令参数错误,请重新输入";
        return new command(SETANGLE, wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "LT") {
        reminder = "右转（LT）";
        wordList[begin + 1].toInt(&flag);
        if(!flag)reminder += " 指令参数错误,请重新输入";
        return new command(SETANGLE, -wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "SETPC") {
        reminder = "设置画笔颜色（SETPC）";
        wordList[begin + 1].toInt(&flag);
        if(!flag)reminder += " 指令参数错误,请重新输入";
        return new command(SETPC, wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "SETBG") {
        reminder = "设置背景颜色（SETBG）";
        wordList[begin + 1].toInt(&flag);
        if(!flag)reminder += " 指令参数错误,请重新输入";
        return new command(SETBG, wordList[begin + 1].toInt(), parse(wordList, begin+2, end));
    } else if (wordList[begin] == "SETXY") {
        reminder = "坐标定位（SETXY）";
        wordList[begin + 1].toInt(&flag);
        wordList[begin + 2].toInt(&flag);
        if(!flag)reminder += " 指令参数错误,请重新输入";
        return new command(SETXY, wordList[begin + 1].toInt(), wordList[begin + 2].toInt(), parse(wordList, begin+3, end));
    } else if (wordList[begin] == "STAMPOVAL") {
        reminder = "画圆（STAMPOVAL）";
        wordList[begin + 1].toInt(&flag);
        wordList[begin + 2].toInt(&flag);
        if(!flag)reminder += " 指令参数错误,请重新输入";
        return new command(OVALMOVE, wordList[begin + 1].toInt(), wordList[begin + 2].toInt(), parse(wordList, begin+3, end));
    } else if (wordList[begin] == "REPEAT") {
        reminder = "重复命令（REPEAT）";
        int cnt = 0, i;
        for (i=begin; i<=end; i++) {
            if (wordList[i] == "[") ++cnt;
            else if (wordList[i] == "]") {
                --cnt;
                if (!cnt) break;
            }
        }
        return new command(REPEAT, wordList[begin + 1].toInt(), parse(wordList, begin + 3, i - 1), parse(wordList, i + 1, end));
    } else if (wordList[begin] == "CLEAN") {
        reminder = "清屏（CLEAN）";
        return new command(CLEAN, 0, parse(wordList, begin+1, end));
    } else if (wordList[begin] == "PU") {
        reminder = "提笔（PENUP）";
        return new command(PU, 0, parse(wordList, begin+1, end));
    } else if (wordList[begin] == "PD") {
        reminder = "落笔（PENDOWN）";
        return new command(PD, 0, parse(wordList, begin+1, end));
    } else {

        if(reminder != ""){
            if(reminder.at(reminder.size() - 1) == "）")reminder += " 指令参数错误,请重新输入！";
            return nullptr;
        }
        reminder = "未输入指令或输入指令无效,请重新输入";
        return nullptr;
    }
}
