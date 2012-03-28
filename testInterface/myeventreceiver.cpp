#include "myeventreceiver.h"

bool eventReceiver::MyEventReceiver::OnEvent(const irr::SEvent & event){
    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT){
        switch(event.MouseInput.Event)
        {
        case irr::EMIE_LMOUSE_PRESSED_DOWN:
                MouseState.LeftButtonDown = true;
                break;
        case irr::EMIE_LMOUSE_LEFT_UP:
                MouseState.LeftButtonDown = false;
                break;
        case irr::EMIE_MOUSE_MOVED:
                MouseState.Position.X = event.MouseInput.X;
                MouseState.Position.Y = event.MouseInput.Y;
                break;
        default:
                break;
        }
    }
    else if(event.EventType == irr::EET_KEY_INPUT_EVENT){
         KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }
    return false;
}


