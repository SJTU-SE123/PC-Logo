#ifndef COMMAND_H
#define COMMAND_H

typedef enum {SETPC, SETBG, SETXY, SETANGLE, STRAIGHTMOVE, OVALMOVE, REPEAT} cmdType;

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
   }u;
   command* next;

public:
   cmdType getType() {return type;}
   int getDistance() {return u.distance;}
   command* getNext() {return next;}
   command(cmdType type, int x, command* next);
   command(cmdType type, int x, int y, command* next);
   command(cmdType type, int times, command* content, command* next);
};

#endif // COMMAND_H
