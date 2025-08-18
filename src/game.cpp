#include "game.h"
#include "input_manager.h"

Game::Game() : running(false), rendererManager(), inputManager(this) {}

Game::~Game() {}

void Game::run() {
  while (true) {
    inputManager.readInput();
    rendererManager.waitNextFrame();
  }
}
