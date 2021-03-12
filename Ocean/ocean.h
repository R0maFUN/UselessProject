// Copyright <Roman Balayan> @ 2021

#pragma once

#include "common.h"
#include "Cell.h"
#include <list>
#include <vector>

class Ocean
{
public:
	Ocean();
	void print() const;
	void addObjects();
	void run();
	std::shared_ptr<Cell> getCell(int x, int y);
private:
	std::vector<std::vector<std::shared_ptr<Cell> > > cells;
	std::list<Object*> stuff;
};
