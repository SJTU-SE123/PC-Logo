#include "lineinterpreter.h"
#include <QDebug>
#include <QStringList>
#include "localmode.h"

LineInterpreter::LineInterpreter() {
    procedures = new QMap<QString, Procedure>();
}

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
        if(wordList[begin].count('[') > 1) {
            reminder += " 指令参数错误,请重新输入";
            return nullptr;
        }
        wordList[begin].remove('[');
        if(wordList[end].count(']') > 1) {
            reminder += " 指令参数错误,请重新输入";
            return nullptr;
        }
        wordList[end].remove(']');
    }
    if (wordList[begin] == ""){
        return parse(wordList, begin+1, end);
    }
    bool flag = true, flagTmp = true;
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
        reminder = "右转（RT）";
        int param = wordList[begin + 1].toInt(&flag);
        if (!flag) reminder += " 指令参数错误,请重新输入";
        return new command(SETANGLE, param, parse(wordList, begin+2, end));
    } else if (wordList[begin] == "LT") {
        reminder = "左转（LT）";
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
        if(begin + 2 > end) {
            reminder += " 指令参数错误,请重新输入";
            return nullptr;
        }
        int x = wordList[begin + 1].toInt(&flag);
        int y = wordList[begin + 2].toInt(&flagTmp);
        if (!flag || !flagTmp) reminder += " 指令参数错误,请重新输入";
        return new command(SETXY, x, y, parse(wordList, begin+3, end));
    } else if (wordList[begin] == "STAMPOVAL") {
        reminder = "画圆（STAMPOVAL）";
        if(begin + 2 > end) {
            reminder += " 指令参数错误,请重新输入";
            return nullptr;
        }
        int a = wordList[begin + 1].toInt(&flag);
        int b = wordList[begin + 2].toInt(&flagTmp);
        if(!flag || !flagTmp) reminder += " 指令参数错误,请重新输入";
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
            if (wordList[i] == "$") continue;
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
    } else if (wordList[begin] == "RESET") {
        reminder = "复位（RESET）";
        return new command(RESET, 0, parse(wordList, begin+1, end));
    } else if (wordList[begin] == "PU") {
        reminder = "提笔（PENUP）";
        return new command(PU, 0, parse(wordList, begin+1, end));
    } else if (wordList[begin] == "PD") {
        reminder = "落笔（PENDOWN）";
        return new command(PD, 0, parse(wordList, begin+1, end));
    } else if (wordList[begin] == "TO") {
        reminder = "子过程（TO）";
        int endpos;
        for (endpos = begin+1; endpos <= end; endpos++) if (wordList[endpos] == "END") break;   //可能要改进成计算TO和END的个数差进行判断。
        if(endpos > end) {
            reminder += " 指令需要END以结束声明";
            return nullptr;
        }
        procedures->insert(wordList[begin+1], Procedure(wordList, begin + 1, endpos - 1, procedures));   //同名procedure默认替换。
        return parse(wordList, endpos + 1, end);
    } else if (procedures->contains(wordList[begin])){   //调用子程序
        Procedure pro = (*procedures)[wordList[begin]];
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
    }
    else {
        // error
        if (reminder != "") {
            if (reminder.at(reminder.size() - 1) == "）") reminder += " 指令参数错误,请重新输入！";
            return nullptr;
        }
        reminder = "未输入指令或输入指令无效,请重新输入";
        return nullptr;
    }
}
