// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <GameProcess.h>
#include <Population.h>

void GameProcess::getNextGeneration() {
    population->nextGeneration();
    population->updatePopulation();

    for (auto row = 0; row < map->getSize().x; row++) {
        for (auto col = 0; col < map->getSize().y; col++) {
            generation[row * map->getSize().y + col] =  map->getIndividualID(row, col);
        }
    }
    generationNumber++;
}

GameProcess::GameProcess() {
    generationNumber = 0;
    map = new Map(Vector2i(50, 50));
    individuals = { Individual(0, 2), Individual(1, 2), Individual(2, 2), Individual(2, 1), Individual(1, 0) };
    population = new Population(0, &individuals, map);

    generation = new int[map->getSize().x * map->getSize().y];
    for (int i = 0; i < map->getSize().x * map->getSize().y; i++) {
        generation[i] = -1;
    }
}

int GameProcess::getMapHeight() {
    return map->getSize().x;
}

int GameProcess::getMapWidth() {
    return map->getSize().y;
}

Vector2i GameProcess::getMapSize() {
    return map->getSize();
}
