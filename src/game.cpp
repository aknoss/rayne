#include "game.h"
#include "input_manager.h"

Game::Game() : running{true}, rendererManager(), inputManager(this) {}

Game::~Game() {}

void Game::run() {
  while (running) {
    inputManager.readInput();
    rendererManager.waitNextFrame();
  }
}

void Game::exit() { running = false; }
