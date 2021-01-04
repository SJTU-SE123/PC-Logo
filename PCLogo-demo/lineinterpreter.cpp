#include "lineinterpreter.h"
#include <QDebug>
#include <QStringList>
#include "localmode.h"

command* LineInterpreter::parseLine(QString str) {
    str = str.toUpper();
    QStringList lineList = str.split("\n");
    QStringList wordList;
    for (auto line : lineList) {
        line += " $";
        QStringList tmp = line.split(" ");
        wordList.append(tmp);
    }
    return this->parse(wordList, 0, wordList.length() - 1);
}

command* LineInterpreter::parse(QStringList wordList, int begin, int end, bool repeatFlag) {
    if (begin > end) return nullptr;
    if (wordList[begin] == "$"){
        if (begin+1 > end) return nullptr;
        lineNumber++;
        return parse(wordList, begin+1, end);
    }
    if(repeatFlag) {
        wordList[begin].remove('[');
        wordList[end].remove(']');
    }
    if (wordList[begin] == ""){
        return parse(wordList, begin+1, end);
    }
    bool flag = true;
    if (wordList[begin] == "FD") {
        reminder = "前进（FD）";
        int param = wordList[begin + 1].toInt(&flag);
        if (!flag) reminder += " 指令参数错误,请重新输入";
        return new command(STRAIGHTMOVE, param, parse(wordList, begin+2, end));
    } else if (wordList[begin] == "BK") {
        reminder = "后退（BK）";
        int param = wordList[begin + 1].toInt(&flag);
        if (!flag) reminder += " 指令参数错误,请重新输入";
        return new command(STRAIGHTMOVE, -param, parse(wordList, begin+2, end));
    } else if (wordList[begin] == "RT") {
        reminder = "左转（RT）";
        int param = wordList[begin + 1].toInt(&flag);
        if (!flag) reminder += " 指令参数错误,请重新输入";
        return new command(SETANGLE, param, parse(wordList, begin+2, end));
    } else if (wordList[begin] == "LT") {
        reminder = "右转（LT）";
        int param = wordList[begin + 1].toInt(&flag);
        if (!flag) reminder += " 指令参数错误,请重新输入";
        return new command(SETANGLE, -param, parse(wordList, begin+2, end));
    } else if (wordList[begin] == "SETPC") {
        reminder = "设置画笔颜色（SETPC）";
        int color_16 = wordList[begin + 1].toInt(&flag, 16);
        if (!flag) reminder += " 指令参数错误,请重新输入";
        return new command(SETPC, color_16, parse(wordList, begin+2, end));
    } else if (wordList[begin] == "SETBG") {
        reminder = "设置背景颜色（SETBG）";
        int color_16 = wordList[begin + 1].toInt(&flag, 16);
        if (!flag) reminder += " 指令参数错误,请重新输入";
        return new command(SETBG, color_16, parse(wordList, begin+2, end));
    } else if (wordList[begin] == "SETXY") {
        reminder = "坐标定位（SETXY）";
        int x = wordList[begin + 1].toInt(&flag);
        int y = wordList[begin + 2].toInt(&flag);
        if (!flag) reminder += " 指令参数错误,请重新输入";
        return new command(SETXY, x, y, parse(wordList, begin+3, end));
    } else if (wordList[begin] == "STAMPOVAL") {
        reminder = "画圆（STAMPOVAL）";
        int a = wordList[begin + 1].toInt(&flag);
        int b = wordList[begin + 2].toInt(&flag);
        if(!flag)reminder += " 指令参数错误,请重新输入";
        return new command(OVALMOVE, a, b, parse(wordList, begin+3, end));
    } else if (wordList[begin] == "REPEAT") {
        reminder = "重复命令（REPEAT）";
        int times = wordList[begin + 1].toInt(&flag);
        if(!flag) {
            reminder += " 指令参数错误,请重新输入";
            return nullptr;
        }
        int cnt = 0, i;
        for (i = begin + 2; i <= end; i++) {
            if (wordList[i].contains('[') && wordList[i].contains(']')) {
                int leftPos = wordList[i].indexOf('[');
                int rightPos = wordList[i].indexOf(']');
                if(leftPos < rightPos) {
                    if(!cnt) break;
                    else continue;
                }
                else reminder += " 指令参数错误,请重新输入！";
                return nullptr;
            }
            if (wordList[i].contains('[')) cnt++;
            else if (wordList[i].contains(']')) cnt--;
            if(!cnt) break;
        }
        if (cnt != 0 || i > end) {
            reminder += " 指令中，[]数目无法匹配,请重新输入";
            return nullptr;
        }
        return new command(REPEAT, times, parse(wordList, begin + 2, i, true), parse(wordList, i + 1, end));
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
        // error
        if (reminder != "") {
            if (reminder.at(reminder.size() - 1) == "）") reminder += " 指令参数错误,请重新输入！";
            return nullptr;
        }
        reminder = "未输入指令或输入指令无效,请重新输入";
        return nullptr;
    }
}
