// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <Map.h>
#include "../include/Population.h"

Population::Population(int ID, std::vector<Individual> *individuals, IMap *map) : IPopulation(ID, individuals, map) {
    updateMap();
}

Population::~Population() {
    delete individuals;
}

int Population::getIndividualsCount() const {
    return static_cast<int>(individuals->size());
}

void Population::addIndividual(Individual individual) {
    individuals->push_back(individual);
}

void Population::deleteIndividual(int individualNumber) {
    individuals[individualNumber] = individuals[individuals->size() - 1];
    individuals->pop_back();
}

void Population::nextGeneration() {
    Vector2i mapSize = map->getSize();
    int* nextGeneration = new int[mapSize.x * mapSize.y];
    for (auto row = 0; row < mapSize.y; row++) {
        for (auto col = 0; col < mapSize.x; col++) {
            nextGeneration[row * mapSize.x + col] = map->getIndividualID(Vector2i(col, row));

            int neighborsCount = 0;
            if (map->getIndividualID(col - 1, row - 1) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(col, row - 1) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(col + 1, row - 1) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(col - 1, row) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(col + 1, row) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(col - 1, row + 1) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(col, row + 1) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(col + 1, row + 1) == ID) {
                neighborsCount++;
            }

            if (neighborsCount == 3) {
                nextGeneration[row * mapSize.x + col] = ID;
            } else if (neighborsCount < 2 || neighborsCount > 3) {
                nextGeneration[row * mapSize.x + col] = -1;
            }
        }
    }

    for (auto row = 0; row < mapSize.y; row++) {
        for (auto col = 0; col < mapSize.x; col++) {
            map->setIndividualID(col, row, nextGeneration[row * mapSize.x + col]);
        }
    }
}

void Population::updateMap() const {
    for (auto it = individuals->begin(); it != individuals->end(); it++) {
        map->setIndividualID(it->getPosition(), ID);
    }
}

void Population::updatePopulation() {
    Vector2i mapSize = map->getSize();
    individuals->clear();
    for (auto row = 0; row < mapSize.y; row++) {
        for (auto col = 0; col < mapSize.x; col++) {
            if (map->getIndividualID(col, row) == ID) {
                individuals->push_back(Individual(Vector2i(col, row)));
            }
        }
    }
}

Individual& Population::getIndividual(int index) {
    return individuals->operator[](static_cast<unsigned long>(index));
}
