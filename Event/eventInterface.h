#ifndef EVENTINTERFACE_H
#define EVENTINTERFACE_H

class EventInterface{
public:
     virtual void trigger() = 0;
     virtual ~EventInterface(){};
};


#endif