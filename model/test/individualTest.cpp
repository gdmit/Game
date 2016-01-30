#include "gtest/gtest.h"
#include "../include/Individual.h"

TEST(IndividualTest, canCreateIndividual) {
    Individual* individual = nullptr;

    individual = new Individual();

    ASSERT_NE(nullptr, individual);
}

