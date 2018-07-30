//
// Created by null on 26.07.2018.
//

#include "player.h"
#include "vars.h"

player::player() {
#ifdef G_DEBUG
  std::cout << "player()" << std::endl;
#endif
}

player::~player() {
#ifdef G_DEBUG
  std::cout << "~player()" << std::endl;
#endif
}

player::player(std::string name, char id) {
  this->name = name;
  this->id = id;
#ifdef G_DEBUG
  std::cout << "player() with params" << std::endl;
#endif
}
const char &player::get_id() {
  return id;
}

const std::string &player::get_name() {
  return name;
}
