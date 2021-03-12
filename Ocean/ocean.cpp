#include "ocean.h"

Ocean::Ocean() {
}

std::shared_ptr<Cell> Ocean::getCell(int x, int y)
{
    return this->cells[y][x];
}
