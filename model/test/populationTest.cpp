// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <Population.h>
#include <Map.h>
#include "gtest/gtest.h"

TEST(PopulationTest, canCreateEmptyPopulation) {
    IPopulation* population = nullptr;

    population = new Population(0, new std::vector<Individual>(), new Map(Vector2i(1,1)));

    ASSERT_NE(nullptr, population);
}

TEST(PopulationTest, canCreateNotEmptyPopulation) {
    IPopulation* population = nullptr;
    std::vector<Individual> individuals = { Individual(), Individual() };

    population = new Population(0, &individuals, new Map(Vector2i(1,1)));

    ASSERT_EQ(2, population->getIndividualsCount());
}

TEST(PopulationTest, canConstructNextGenerationOnMapSize1) {
    IPopulation* population = nullptr;
    std::vector<Individual> individuals = { Individual() };
    population = new Population(0, &individuals, new Map(Vector2i(1,1)));

    population->nextGeneration();
    population->updatePopulation();

    ASSERT_EQ(0, population->getIndividualsCount());
}

TEST(PopulationTest, canConstructNextGenerationOnMapSize10) {
    IPopulation* population = nullptr;
    std::vector<Individual> individuals = { Individual(0, 0), Individual(0, 1),
                                            Individual(1, 0), Individual(1, 1) };
    population = new Population(0, &individuals, new Map(Vector2i(10,10)));

    population->nextGeneration();
    population->updatePopulation();

    EXPECT_EQ(4, population->getIndividualsCount());
}
