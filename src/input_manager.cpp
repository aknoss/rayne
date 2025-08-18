#include "input_manager.h"
#include "game.h"
#include <SDL3/SDL.h>

InputManager::InputManager(Game *g) : game{g} {}

InputManager::~InputManager() {}

void InputManager::readInput() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_KEY_DOWN || event.type == SDL_EVENT_QUIT) {
      game->exit();
    }
  }
}
