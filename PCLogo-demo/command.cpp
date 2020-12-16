#include "command.h"

command::command(cmdType type, int x, command* next) {
    this->type = type;
    this->u.color = x;
    this->next = next;
}
command::command(cmdType type, int x, int y, command* next) {
    this->type = type;
    this->u.pos.x = x;
    this->u.pos.y = y;
    this->next = next;
}
command::command(cmdType type, int times, command* content, command* next) {
    this->type = type;
    this->u.info.times = times;
    this->u.info.content = content;
    this->next = next;
}

command::command(cmdType type, command* body, command* next){
    this->type = type;
    this->u.body = body;
    this->next = next;
}
