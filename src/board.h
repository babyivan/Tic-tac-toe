//
// Created by null on 26.07.2018.
//

#ifndef XO_BOARD_H
#define XO_BOARD_H

#include <vector>
#include "player.h"
#include "vars.h"

class board {
 public:
  board();

  void print_game_board();
  void print_tutorial_board();
  // Проверка на победителя
  bool check_winner(player *p);
  bool game_process(player *p);
  // Идет ли сейчас игра
  const bool &get_game_state();
  // Получаем победителя по указателю
  player *get_winner();

 private:
  // Проверка хода на валидность
  // Всегда ход -1 ибо масив начинается с "0"
  bool check_player_move(int move);
  // Вносим изменения в игровую доску и увеличиваем общее количество ходов на 1
  void apply_progress(int cell, player *p);

 private:
  char game_board[9] = {
      CELL_EMPTY, CELL_EMPTY, CELL_EMPTY,
      CELL_EMPTY, CELL_EMPTY, CELL_EMPTY,
      CELL_EMPTY, CELL_EMPTY, CELL_EMPTY
  };
  player *winner;
  int iter;
  bool game_state;

};

#endif //XO_BOARD_H
