// Copyright <Roman Balayan> @ 2021

#pragma once

#include <memory>

#include "common.h"
#include "cell.h"

enum class ObjType { STONE, EMPTY, PREY, PREDATOR };

class Cell;
class Object : std::enable_shared_from_this<Object>
{
public:
	Object(std::weak_ptr<Cell> = std::weak_ptr<Cell>());
	virtual void live(); // жизнь объекта, is not pure virtual coz of EMPTY obj
	void setCell(std::weak_ptr<Cell>);
	ObjType getType();
	bool moveTo(std::shared_ptr<Cell>& dest);
protected:
	std::weak_ptr<Cell> cell;
	ObjType type;
};
