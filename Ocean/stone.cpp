#include "stone.h"

Stone::Stone(std::weak_ptr<Cell> cell) : Object(cell) {
    this->type = ObjType::STONE;
}

void Stone::live() {
}
