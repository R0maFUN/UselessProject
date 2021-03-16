// Copyright <Roman Balayan> @ 2021

#pragma once

#include "common.h"
//#include "object.h"
#include "cell.h"
//#include "stone.h"
//#include "predator.h"
#include "prey.h"

#include <list>
#include <vector>
#include <iostream>

class Object;
class Cell;
class Prey;
class Predator;
class Stone;
class Ocean : std::enable_shared_from_this<Ocean>
{
public:
	Ocean();
	void print() const;
	void addObjects();
	void addObject(std::shared_ptr<Object> obj);
	void removeObject(std::shared_ptr<Object> obj);
	void run();
	std::shared_ptr<Cell> getEmptyCell();
	std::shared_ptr<Cell> getCell(int x, int y);
private:
	std::vector<std::vector<std::shared_ptr<Cell> > > cells;
	std::list<std::shared_ptr<Object> > stuff;
};
