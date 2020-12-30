#ifndef COMMAND_H
#define COMMAND_H

#include "procedure.h"

typedef enum {SETPC, SETBG, SETXY, SETANGLE, STRAIGHTMOVE, OVALMOVE, REPEAT, PROCEDURE, CLEAN, PU, PD} cmdType;

class command
{
private:
   cmdType type;
   union {
       int color;
       struct {int x; int y;} pos;
       int angle;
       int distance;
       struct {int times; command* content;} info;
       command* body;   //FOR PROCEDURE
   }u;
   command* next;

public:
   cmdType getType() {return type;}
   int getDistance() {return u.distance;}
   int getColor() {return u.color;}
   int getAngle() {return u.angle;}
   int getTimes() {return u.info.times;}
   int getX() {return u.pos.x;}
   int getY() {return u.pos.y;}
   command* getContent() {return u.info.content;}
   command* getBody() {return u.body;}
   command* getNext() {return next;}
   command(cmdType type, int x, command* next);
   command(cmdType type, int x, int y, command* next);
   command(cmdType type, int times, command* content, command* next);
   command(cmdType type, command* body, command* next);
};

#endif // COMMAND_H
