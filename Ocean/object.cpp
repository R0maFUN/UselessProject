#include "object.h"

Object::Object(std::weak_ptr<Cell> cell) : cell(cell)
                                         , health(10)
                                         , type(ObjType::EMPTY){
}

void Object::setCell(std::weak_ptr<Cell> newCell) {
    this->cell = newCell;
}

