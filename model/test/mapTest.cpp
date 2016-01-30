#include "gtest/gtest.h"
#include "../include/IMap.h"
#include "../include/Map.h"

TEST(MapTest, canCreateMap) {
    IMap* map = nullptr;

    map = new Map();

    ASSERT_NE(nullptr, map);
}

TEST(MapTest, byDefaultMapHaveZeroSize) {
    IMap* map = new Map();

    EXPECT_EQ(IVector2D(0, 0), map->getSize());
}

TEST(MapTest, canCreateMapWithNonZeroSize) {
    IMap* map = new Map(IVector2D(10, 10));

    EXPECT_EQ(IVector2D(10, 10), map->getSize());
}

TEST(MapTest, byDefaultTypeOfFirstCellIsPlains) {
    IMap* map = new Map(IVector2D(10, 10));

    ASSERT_EQ(CellType::PLAINS, map->getCellType(IVector2D(0, 0)));
}

TEST(MapTest, isBadCellTypeReturnsWhenIndexIsOutOfRange) {
    IMap* map = new Map(IVector2D(10, 10));

    EXPECT_EQ(CellType::BAD_TYPE, map->getCellType(IVector2D(10, 0)));
    EXPECT_EQ(CellType::BAD_TYPE, map->getCellType(IVector2D(0, 10)));
    EXPECT_EQ(CellType::BAD_TYPE, map->getCellType(IVector2D(10, 10)));
}

TEST(MapTest, canSetCellType) {
    IMap* map = new Map(IVector2D(10, 10));

    map->setCellType(IVector2D(0, 0), CellType::FOREST);

    ASSERT_EQ(CellType::FOREST, map->getCellType(IVector2D(0, 0)));
}

TEST(MapTest, byDefaultFirstCellHasNoIndividuals) {
    IMap* map = new Map(IVector2D(10, 10));

    ASSERT_EQ(0, map->getIndividualID(IVector2D(0, 0)));
}

TEST(MapTest, isBadIDReturnsWhenIndexIsOutOfRange) {
    IMap* map = new Map(IVector2D(10, 10));

    EXPECT_EQ(-1, map->getIndividualID(IVector2D(10, 0)));
    EXPECT_EQ(-1, map->getIndividualID(IVector2D(0, 10)));
    EXPECT_EQ(-1, map->getIndividualID(IVector2D(10, 10)));
}

TEST(MapTest, canSetIndividualID) {
    IMap* map = new Map(IVector2D(10, 10));

    map->setIndividualID(IVector2D(0, 0), 1);

    ASSERT_EQ(1, map->getIndividualID(IVector2D(0, 0)));
}