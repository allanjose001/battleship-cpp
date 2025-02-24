#include "../controllers/boardController.h"

#include "player.h"

BoardController::BoardController() : board() {}

BoardController::~BoardController() {}

void BoardController::placeShip(int x, int y, Ship& ship) {
    try {
        board.placeShip(ship, x, y);
#ifdef USE_QT
        emit boardUpdated();
#endif
    } catch (const std::exception& e) {
        std::cerr << "erro ao posicionar navio: " << e.what() <<std::endl;
    }
}

Position (&BoardController::getBoardState())[10][10] {
    return board.getPositions();
}

void BoardController::randomizeShips() {
    // Cria um jogador temporário
    Player player("Player 1");

    // Posiciona os navios aleatoriamente
    player.positionShipsRandomly();

    // Limpa o tabuleiro atual
    board = Board(); // Reseta o tabuleiro

    // Atualiza o tabuleiro com as novas posições dos navios
    Position (&boardState)[10][10] = player.getBoard().getPositions();
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (boardState[i][j].getShipReference() != nullptr) {
                board.placeShip(*boardState[i][j].getShipReference(), i, j);
            }
        }
    }

    // Emite o sinal para atualizar a interface gráfica
    emit boardUpdated();
}


// void Controller::attackPosition(int x, int y) {
//     try {
//         board.attack(x, y);
//         bool hit = board.getPositions()[x][y].getShipReference() != nullptr;
//         emit attackResult(hit);
//         emit boardUpdated();
//     } catch (const std::exception& e) {
//         std::cerr << "erro ao atacar posição: " << e.what() << std::endl;
//     }
// }

