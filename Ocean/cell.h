// Copyright <Roman Balayan> @ 2021

#pragma once

#include <utility>
#include <memory>

#include "common.h"
#include "object.h"
#include "ocean.h"

using Pair = std::pair<int, int>;

class Ocean;
enum class ObjType;
class Object;

class Cell : std::enable_shared_from_this<Cell>
{
	friend Ocean;
public:
	explicit Cell(Pair coords = { 0, 0 }, std::shared_ptr<Ocean> oceanPtr = nullptr) :
		coords(coords),
		obj(nullptr),
		ocean(oceanPtr) {}
	void init(Pair coords, std::shared_ptr<Ocean> oceanPtr);
	std::shared_ptr<Object> getObject() const;
	void setObject(std::shared_ptr<Object> newObjectPtr);
	void killMe();
	bool isEmpty();
	std::shared_ptr<Cell> getNeighbour();
	ObjType getObjType();
	std::shared_ptr<Ocean> getOcean();
private:
	Pair coords;
	std::shared_ptr<Object> obj;
	std::shared_ptr<Ocean> ocean;
};
