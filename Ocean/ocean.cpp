// Copyright <Roman Balayan> @ 2021

#include "ocean.h"

Ocean::Ocean() {
}

void Ocean::print() const {
    system("cls");
    for (const auto& row : this->cells) {
        for (const auto& cell : row) {
            if (cell->getObjType() == ObjType::EMPTY) {
                std::cout << ".";
            } else if (cell->getObjType() == ObjType::STONE) {
                std::cout << "#";
            } else if (cell->getObjType() == ObjType::PREY) {
                std::cout << "f";
            } else if (cell->getObjType() == ObjType::PREDATOR) {
                std::cout << "S";
            }
        }
        std::cout << "\n";
    }
}

void Ocean::addObjects() {
    for (unsigned int i{ 0 }; i < Constants::Y; ++i) {
        std::vector<std::shared_ptr<Cell> > row;
        for (unsigned int j{ 0 }; j < Constants::X; ++j) {
            std::shared_ptr<Cell> cell;
            std::shared_ptr<Object> object;
            int casino = rand() % 100;

            cell = std::make_shared<Cell>(Pair(j, i), shared_from_this());

            if (casino <= 40) {
                object = std::make_shared<Object>(cell);
            } else if (casino <= 60) {
                object = std::make_shared<Stone>(cell);
            } else if (casino <= 80) {
                object = std::make_shared<Prey>(cell);
            } else {
                object = std::make_shared<Predator>(cell);
            }
            cell->setObject(object);
            row.push_back(cell);
            this->stuff.push_back(object);
        }
        this->cells.push_back(row);
    }
}

void Ocean::addObject(std::shared_ptr<Object> obj) {
    this->stuff.push_back(obj);
}

void Ocean::removeObject(std::shared_ptr<Object> obj) {
    this->stuff.remove(obj);
}

void Ocean::run() {
    char c;
    while (1) {
        for (auto& obj : this->stuff)
            obj->live();
        this->print();
        std::cin >> c;
    }
}

std::shared_ptr<Cell> Ocean::getEmptyCell() {
    for (const auto& cell : this->cells) {
        auto result = std::find_if(cell.begin(), cell.end(), [](std::shared_ptr<Cell> cellI) {
                return cellI->getObjType() == ObjType::EMPTY;
            });
        if (result != cell.end())
            return *result;
    }
    return nullptr;
}

std::shared_ptr<Cell> Ocean::getCell(int x, int y) {
    return this->cells[y][x];
}
