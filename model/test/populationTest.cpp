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

TEST(PopulationTest, canConstructNextStaticGeneration) {
    IPopulation* population = nullptr;
    std::vector<Individual> individuals = { Individual(0, 0), Individual(0, 1),
                                            Individual(1, 0), Individual(1, 1) };
    population = new Population(0, &individuals, new Map(Vector2i(10,10)));

    population->nextGeneration();
    population->updatePopulation();

    EXPECT_EQ(4, population->getIndividualsCount());
    EXPECT_EQ(Vector2i(0, 0), population->getIndividual(0).getPosition());
    EXPECT_EQ(Vector2i(0, 1), population->getIndividual(1).getPosition());
    EXPECT_EQ(Vector2i(1, 0), population->getIndividual(2).getPosition());
    EXPECT_EQ(Vector2i(1, 1), population->getIndividual(3).getPosition());
}

TEST(PopulationTest, canConstructNextDynamicGeneration) {
    IPopulation* population = nullptr;
    std::vector<Individual> individuals = { Individual(0, 0), Individual(0, 1), Individual(0, 2) };
    population = new Population(0, &individuals, new Map(Vector2i(10,10)));

    population->nextGeneration();
    population->updatePopulation();

    EXPECT_EQ(3, population->getIndividualsCount());
    EXPECT_EQ(Vector2i(0, 1), population->getIndividual(0).getPosition());
    EXPECT_EQ(Vector2i(1, 1), population->getIndividual(1).getPosition());
    EXPECT_EQ(Vector2i(9, 1), population->getIndividual(2).getPosition());
}

TEST(PopulationTest, canConstructThirdDynamicGeneration) {
    IPopulation* population = nullptr;
    std::vector<Individual> individuals = { Individual(0, 0), Individual(0, 1), Individual(0, 2) };
    population = new Population(0, &individuals, new Map(Vector2i(10,10)));

    for (int i = 0; i < 2; i++) {
        population->nextGeneration();
        population->updatePopulation();
    }

    EXPECT_EQ(3, population->getIndividualsCount());
    EXPECT_EQ(Vector2i(0, 0), population->getIndividual(0).getPosition());
    EXPECT_EQ(Vector2i(0, 1), population->getIndividual(1).getPosition());
    EXPECT_EQ(Vector2i(0, 2), population->getIndividual(2).getPosition());
}

TEST(PopulationTest, canConstructGlidersFifthGeneration) {
    IPopulation* population = nullptr;
    std::vector<Individual> individuals = { Individual(0, 2), Individual(1, 2), Individual(2, 2), Individual(2, 1),
                                            Individual(1, 0)};
    population = new Population(0, &individuals, new Map(Vector2i(10,10)));

    for (int i = 0; i < 4; i++) {
        population->nextGeneration();
        population->updatePopulation();
    }

    EXPECT_EQ(5, population->getIndividualsCount());
    EXPECT_EQ(Vector2i(1, 3), population->getIndividual(0).getPosition());
    EXPECT_EQ(Vector2i(2, 1), population->getIndividual(1).getPosition());
    EXPECT_EQ(Vector2i(2, 3), population->getIndividual(2).getPosition());
    EXPECT_EQ(Vector2i(3, 2), population->getIndividual(3).getPosition());
    EXPECT_EQ(Vector2i(3, 3), population->getIndividual(4).getPosition());
}