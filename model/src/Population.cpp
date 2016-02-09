// Copyright (c) 2016 Evolution Team. All rights reserved.

#include "../include/Population.h"

Population::Population(int ID, int individualsCount) :
    IPopulation(ID, individualsCount) {
    individuals = new std::vector<Individual>(
        static_cast<unsigned long>(individualsCount));
}

Population::~Population() {
    delete individuals;
}