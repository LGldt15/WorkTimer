#include <iostream>
#include "time.h"
using namespace std;




class Settings{
    
private:
    bool set;
    unsigned int wIndex;
    unsigned int bIndex;
   // unsigned int workDuration;
  //  unsigned int breakDuration;






public:
void selectMode();
void timeLoop(unsigned int workDuration,unsigned int breakDuration);
//bool stop(string cmd) const;
//bool reset(string cmd) const;
//void stopLoop() const;
//void resetLoop();
void pomodoroShort(unsigned int workDuration,unsigned int breakDuration) ;
void pomodoroMedium(unsigned int workDuration,unsigned int breakDuration) ;
void pomodoroLong(unsigned int workDuration,unsigned int breakDuration) ;
//Extras
void endAnimation()const;


};