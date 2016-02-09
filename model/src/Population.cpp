// Copyright (c) 2016 Evolution Team. All rights reserved.

#include "../include/Population.h"

Population::Population(int ID, std::vector<Individual> *individuals, IMap *map) : IPopulation(ID, individuals, map) {
    for (auto it = individuals->begin(); it != individuals->end(); it++) {
        map->setIndividualID(it->getPosition(), ID);
    }
}

Population::~Population() {
    delete individuals;
}

int Population::getIndividualsCount() const {
    return static_cast<int>(individuals->size());
}

void Population::addIndividual(Individual &individual) {
    individuals->push_back(individual);
}

void Population::deleteIndividual(int individualNumber) {
    individuals[individualNumber] = individuals[individuals->size() - 1];
    individuals->pop_back();
}

void Population::nextGeneration() {
    Vector2i mapSize = map->getSize();
    for (auto row = 0; row < mapSize.x; row++) {
        for (auto col = 0; col < mapSize.y; col++) {
            int neighborsCount = 0;
            if (map->getIndividualID(Vector2i(row - 1, col - 1)) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(Vector2i(row - 1, col)) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(Vector2i(row - 1, col + 1)) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(Vector2i(row, col - 1)) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(Vector2i(row, col + 1)) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(Vector2i(row + 1, col - 1)) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(Vector2i(row + 1, col)) == ID) {
                neighborsCount++;
            }
            if (map->getIndividualID(Vector2i(row + 1, col + 1)) == ID) {
                neighborsCount++;
            }

            if (neighborsCount == 3) {
                map->setIndividualID(Vector2i(row, col), ID);
            } else if (neighborsCount < 2 || neighborsCount > 3) {
                map->setIndividualID(Vector2i(row, col), -1);
            }
        }
    }
}

void Population::updatePopulation() {
    Vector2i mapSize = map->getSize();
    individuals->clear();
    for (auto row = 0; row < mapSize.x; row++) {
        for (auto col = 0; col < mapSize.y; col++) {
            if (map->getIndividualID(row, col) == ID) {
                individuals->push_back(Individual(Vector2i(row, col)));
            }
        }
    }
}
