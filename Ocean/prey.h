// Copyright <Roman Balayan> @ 2021

#pragma once

#include <memory>

#include "object.h"
#include "cell.h"

class Prey : public Object {
public:
    Prey(std::weak_ptr<Cell> cell = std::weak_ptr<Cell>());
    void live() override;
};