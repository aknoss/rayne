#include "game_manager.h"
#include "render_manager.h"
#include <SDL3/SDL.h>

GameManager::GameManager() : running(false), renderManager() {}

GameManager::~GameManager() {}

void GameManager::handleEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_KEY_DOWN || event.type == SDL_EVENT_QUIT) {
      running = false;
    }
  }
}

void GameManager::update() {}

int GameManager::run() {
  while (running) {
    handleEvents();
    update();
    renderManager.waitNextFrame();
  }

  return 0;
}
