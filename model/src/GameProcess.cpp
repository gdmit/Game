// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <GameProcess.h>
#include <Population.h>

GameProcess::GameProcess(Vector2i mapSize) {
    generationNumber = 0;
    map = new Map(Vector2i(mapSize.x, mapSize.y));

    population = new Population(0, &individuals, map);
    fillMapWithRandomPopulations(0);

    generation = new int[map->getSize().x * map->getSize().y];
    for (auto row = 0; row < map->getSize().y; row++) {
        for (auto col = 0; col < map->getSize().x; col++) {
            generation[row * map->getSize().x + col] = map->getIndividualID(col, row);
        }
    }
}

GameProcess::GameProcess() {
    generationNumber = 0;
    map = new Map(Vector2i(10, 15));

    individuals = { Individual(2, 0), Individual(2, 1), Individual(2, 2), Individual(1, 2), Individual(0, 1) };
    population = new Population(0, &individuals, map);
    population->updateMap();

    generation = new int[map->getSize().x * map->getSize().y];
    for (auto row = 0; row < map->getSize().y; row++) {
        for (auto col = 0; col < map->getSize().x; col++) {
            generation[row * map->getSize().x + col] = map->getIndividualID(col, row);
        }
    }
}

void GameProcess::getNextGeneration() {
    population->nextGeneration();
    population->updatePopulation();

    for (auto row = 0; row < map->getSize().y; row++) {
        for (auto col = 0; col < map->getSize().x; col++) {
            generation[row * map->getSize().x + col] = map->getIndividualID(col, row);
        }
    }
    generationNumber++;
}

int GameProcess::getMapHeight() {
    return map->getSize().y;
}

int GameProcess::getMapWidth() {
    return map->getSize().x;
}

Vector2i GameProcess::getMapSize() {
    return map->getSize();
}

void GameProcess::fillMapWithRandomPopulations(unsigned int seed) {
    srand(seed);

    for (int i = 0; i < map->getSize().x * map->getSize().y; i++) {
        population->addIndividual(Individual(rand() % map->getSize().x, rand() % map->getSize().y));
    }
    population->updateMap();
}
