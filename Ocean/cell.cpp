// Copyright <Roman Balayan> @ 2021

#include "cell.h"

void Cell::init(Pair coords, std::shared_ptr<Ocean> oceanPtr) {
    this->coords = coords;
    this->ocean = oceanPtr;
}

std::shared_ptr<Object> Cell::getObject() const {
    return this->obj;
}

void Cell::setObject(std::shared_ptr<Object> newObjectPtr) {
    this->obj = newObjectPtr;
    //newObjectPtr->setCell(shared_from_this());
}

void Cell::killMe() {
    this->ocean->removeObject(this->obj);
    this->obj = std::make_shared<Object>(shared_from_this());
    // old obj is automatically deleted
}

bool Cell::isEmpty()
{
    return obj ? false : true;
}

std::shared_ptr<Cell> Cell::getNeighbour()
{
    unsigned int direction = rand() % 4;
    int newY = this->coords.second, newX = this->coords.first;
    switch (direction) {
    case 0:
        newY = this->coords.second - 1;
        break;
    case 1:
        newY = this->coords.second + 1;
        break;
    case 2:
        newX = this->coords.first - 1;
        break;
    case 3:
        newX = this->coords.first + 1;
        break;
    }
    if (newY >= 0 && newY < Constants::Y && newX >= 0 && newX < Constants::X)
        return this->ocean->getCell(newX, newY);
    return nullptr;
}

ObjType Cell::getObjType() {
    return this->isEmpty() ? ObjType::EMPTY : this->obj->getType();
}

std::shared_ptr<Ocean> Cell::getOcean() {
    return this->ocean;
}
