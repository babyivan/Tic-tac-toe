//
// Created by null on 26.07.2018.
//

#include "human.h"
#include "vars.h"

human::human() {
#ifdef G_DEBUG
  std::cout << "human()" << std::endl;
#endif
}

human::~human() {
#ifdef G_DEBUG
  std::cout << "~human()" << std::endl;
#endif
}

human::human(const std::string &name, const char &id)
    : player(name, id) {
#ifdef G_DEBUG
  std::cout << "human() with params" << std::endl;
#endif
}

int human::move(const char (&game_board)[9], const int &iter) {
  int move;

  std::cout << "Enter move (1-9): ";
  std::cin >> move;

  return move;
}