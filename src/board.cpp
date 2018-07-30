//
// Created by null on 26.07.2018.
//

#include <iostream>
#include "board.h"
#include "vars.h"

board::board() {
  iter = 0;
  winner = nullptr;
  game_state = true;
}

void board::print_tutorial_board() {
  std::cout << std::endl;
  std::cout << "[ Board rules ]" << std::endl;
  std::cout << "***************" << std::endl;
  std::cout << "*| 1 | 2 | 3 |*" << std::endl;
  std::cout << "*| 4 | 5 | 6 |*" << std::endl;
  std::cout << "*| 7 | 8 | 9 |*" << std::endl;
  std::cout << "***************" << std::endl;
  std::cout << std::endl;
}

void board::print_game_board() {
  std::cout << std::endl;
  std::cout << "[    Board    ]" << std::endl;
  std::cout << "***************" << std::endl;
  std::cout << "*| " << game_board[0] << " | " << game_board[1] << " | " << game_board[2] << " |*" << std::endl;
  std::cout << "*| " << game_board[3] << " | " << game_board[4] << " | " << game_board[5] << " |*" << std::endl;
  std::cout << "*| " << game_board[6] << " | " << game_board[7] << " | " << game_board[8] << " |*" << std::endl;
  std::cout << "***************" << std::endl;
  std::cout << std::endl;
}

bool board::check_winner(player *p) {
  char ret = CELL_EMPTY;
  for (int i = 0; i < 3; i++) {
    // 1-2-3; 4-5-6; 7-8-9.
    if (game_board[i * 3] == game_board[i * 3 + 1] && game_board[i * 3] == game_board[i * 3 + 2])
      ret = game_board[i * 3 + 1];
      // 1-4-7; 2-5-8; 3-6-9.
    else if (game_board[i] == game_board[i + 3] && game_board[i] == game_board[i + 6])
      ret = game_board[i + 3];
      // 1-5-9; 3-5-7.
    else if ((game_board[0] == game_board[4] && game_board[0] == game_board[8]) ||
        (game_board[2] == game_board[4] && game_board[2] == game_board[6]))
      ret = game_board[4];
  }

  return ret == p->get_id();
}

bool board::game_process(player *p) {
  print_game_board();
  bool while_cond = true;

  //проверяем ввод на валидность
  while (while_cond && iter <= 9) {
    // ожидаем ввод от игрока
    int player_move = p->move(game_board, iter);
    if (check_player_move(player_move)) {
      while_cond = false;
      // Вносим изменения на доску
      apply_progress(player_move, p);
    }
  }
  // Проверяем есть ли у нас победитель
  bool b = check_winner(p);
  if (iter >= 5 && iter < 9) {
    if (b) {
      winner = p;
      game_state = false;
    }
    // на этом шаге игра уже окончена
  } else if (iter == 9) {
    game_state = false;
    // проверяем победителя
    if (b) {
      winner = p;
    }
  }
  return game_state;
}

bool board::check_player_move(int move) {
  return (move >= 1 && move <= 9 && game_board[move - 1] == CELL_EMPTY);
}

void board::apply_progress(int cell, player *p) {
  game_board[cell - 1] = p->get_id();
  iter++;
  std::cout << p->get_name() << " put [" << p->get_id() << "] at " << cell << std::endl;
}

player *board::get_winner() {
  return winner;
}

const bool &board::get_game_state() {
  return game_state;
}
