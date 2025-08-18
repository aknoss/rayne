#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "input_manager.h"
#include "renderer_manager.h"
#include <SDL3/SDL.h>

class Game {
private:
  RendererManager rendererManager;
  InputManager inputManager;
  bool running;

public:
  Game();
  ~Game();

  void run();
  void exit();
};

#endif // GAME_MANAGER_H
