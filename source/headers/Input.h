#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <map>
#include <SDL_scancode.h>
#include <SDL_events.h>

class Input {
public:
   void beginNewFrame();
   void keyUpEvent(const SDL_Event& event);
   void keyDownEvent(const SDL_Event& event);

   bool wasKeyPressed(SDL_Scancode key);
   bool wasKeyReleased(SDL_Scancode key);
   bool isKeyHeld(SDL_Scancode key);
private:
    std::map<SDL_Scancode, bool> heldKeys;
    std::map<SDL_Scancode, bool> pressedKeys;
    std::map<SDL_Scancode, bool> releasedKeys;
};

#endif
