// Copyright <Roman Balayan> @ 2021

#pragma once

#include "object.h"
#include "cell.h"

class Stone : public Object {
public:
    Stone(std::weak_ptr<Cell> cell = std::weak_ptr<Cell>());
    void live() override;
};