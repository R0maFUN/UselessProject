#pragma once

#include <memory>

#include "common.h"

const char STONE_N = '#';
const char EMPTY_N = '.';
const char PREY_N = 'f';
const char PREDATOR_N = 'S';

enum class ObjType { STONE, EMPTY, PREY, PREDATOR };

class Cell;
class Object
{
public:
	Object(std::weak_ptr<Cell> = std::weak_ptr<Cell>());
	//virtual ~Object();
	virtual void live() = 0; // жизнь объекта
	void setCell(std::weak_ptr<Cell>);
protected:
	std::weak_ptr<Cell> cell;
	unsigned int health;
	ObjType type;
};