#ifndef MYEVENTRECEIVER_H
#define MYEVENTRECEIVER_H
#include<irrlicht.h>
#include <QtGui>

namespace eventReceiver{
class MyEventReceiver : public irr::IEventReceiver
{
public:
    struct SMouseState {
            irr::core::vector2di Position;
            bool LeftButtonDown;
            SMouseState() : LeftButtonDown(false) { }
    } MouseState;
    virtual bool OnEvent(const irr::SEvent&);
    virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const{return  KeyIsDown[keyCode];}
    const SMouseState & GetMouseState() const{ return MouseState; }
    MyEventReceiver(){
        for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
    }
    ~MyEventReceiver(){}

private:
    bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};//fim da classe MyEventReceiver

}//fim namespace
#endif // MYEVENTRECEIVER_H


