#include "game.h"

Game::Game() : running(false), rendererManager() {}

Game::~Game() {}

void Game::run() {
  while (true) {
    rendererManager.waitNextFrame();
  }
}
