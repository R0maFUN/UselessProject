// Copyright <Roman Balayan> @ 2021

#include "prey.h"
#include "cell.h"
#include "ocean.h"

Prey::Prey(std::weak_ptr<Cell> cell) : Object(cell) {
    this->type = ObjType::PREY;
    this->health = Constants::preyHealth;
}

void Prey::live() {
    if (--health <= 0)
        this->cell.lock()->killMe();
    auto neighbourCell = this->cell.lock()->getNeighbour();
    if (neighbourCell->getObjType() == ObjType::EMPTY) {
        this->moveTo(neighbourCell);
    } else if (neighbourCell->getObjType() == ObjType::PREY) {
        this->reproduction();
    } else if (neighbourCell->getObjType() == ObjType::PREDATOR) {
        //std::shared_ptr<Predator> predator = dynamic_cast<Predator*>(neighbourCell->getObject()); // mb need cast
        //predator->eat();
        this->cell.lock()->killMe();
    }
    //  in the case of stone do nothing
}

void Prey::reproduction() {
    //  could find the closest empty cell but im lazy
    /*auto*/ std::shared_ptr<Cell> emptyCell = this->cell.lock()->getOcean()->getEmptyCell();
    if (emptyCell) {
        std::shared_ptr<Object> child = std::make_shared<Prey>(emptyCell);
        emptyCell->setObject(child);
        this->cell.lock()->getOcean()->addObject(child);
    }
}

Predator::Predator(std::weak_ptr<Cell> cell) : Prey(cell) {
    this->type = ObjType::PREDATOR;
    this->health = Constants::predatorHealth;
}

void Predator::live() {
    if (--health <= 0)
        this->cell.lock()->killMe();
    auto neighbourCell = this->cell.lock()->getNeighbour();
    if (neighbourCell->getObjType() == ObjType::EMPTY) {
        this->moveTo(neighbourCell);
    }
    else if (neighbourCell->getObjType() == ObjType::PREY) {
        this->eat();
        neighbourCell->killMe();
        this->moveTo(neighbourCell);
    }
    else if (neighbourCell->getObjType() == ObjType::PREDATOR) {
        this->reproduction();
    }
    //  in the case of stone do nothing
}

void Predator::reproduction() {
    /*auto*/ std::shared_ptr<Cell> emptyCell = this->cell.lock()->getOcean()->getEmptyCell();
    if (emptyCell) {
        std::shared_ptr<Object> child = std::make_shared<Predator>(emptyCell);
        emptyCell->setObject(child);
        this->cell.lock()->getOcean()->addObject(child);
    }
}

void Predator::eat() {
    this->health += 2;
    this->health = this->health > Constants::predatorHealth ?
        Constants::predatorHealth : this->health;
}

Stone::Stone(std::weak_ptr<Cell> cell) : Object(cell) {
    this->type = ObjType::STONE;
}

void Stone::live() {
}
