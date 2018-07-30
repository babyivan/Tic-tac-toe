//
// Created by null on 26.07.2018.
//

#include <iostream>
#include <vector>

#include "src/vars.h"
#include "src/human.h"
#include "src/computer.h"
#include "src/board.h"

int main() {
  std::vector<player *> players;
  board b;

  player *p = new human("USER_01", CELL_X);
  //player *p = new computer("AI_02", CELL_X);
  player *c = new computer("AI_01", CELL_O);
  int step = 0;

  players.push_back(p);
  players.push_back(c);
  // Печатаем доску с разметкой ячеек чтобы пользователь знал что можно нажимать
  b.print_tutorial_board();
  // Игровой цыкл
  while (b.get_game_state()) {
    // По очереди кидаем игрока на поле
    b.game_process(players[step++]);
    if (step > players.size() - 1)
      step = 0;
  }
  // Печатаем поле после игры
  b.print_game_board();
  // Печатаем победителя после матча
  std::cout << "~+~+~+~+~+~+~" << std::endl;
  if (b.get_winner() != nullptr) {
    std::cout << b.get_winner()->get_name() << " win." << std::endl;

  } else
    std::cout << "    draw." << std::endl;
  std::cout << "~+~+~+~+~+~+~" << std::endl;

  // Чистим после себя выделенную память
  delete c;
  delete p;

  return 0;
}