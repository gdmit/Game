// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <Population.h>
#include "gtest/gtest.h"
#include "../include/IPopulation.h"

TEST(PopulationTest, canCreatePopulation) {
    IPopulation* population = nullptr;

    population = new Population(0, 0);

    ASSERT_NE(nullptr, population);
}
