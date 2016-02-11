// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <gtest/gtest.h>
#include <ViewModel.h>
#include "../../view/include/IViewModel.h"


TEST(ViewModelTest, canCreateViewModel) {
    IViewModel *viewModel = nullptr;

    viewModel = new ViewModel(100, 100);

    ASSERT_NE(nullptr, viewModel);
}


TEST(ViewModelTest, isTextureContainGrid) {
    IViewModel *viewModel = new ViewModel(122, 122);

    viewModel->updateTexture();
    int backgroundComponentCount = 0;
    int gridComponentCount = 0;
    int generationComponentCount = 0;
    for (int row = 0; row < viewModel->texture->height; row++) {
        int width = viewModel->texture->width * viewModel->texture->channels;
        for (int col = 0; col < width; col++) {
            if (viewModel->texture->colors[row * width + col] == BACKGROUND_COLOR) {
                backgroundComponentCount++;
            } else if (viewModel->texture->colors[row * width + col] == GRID_LINE_COLOR) {
                gridComponentCount++;
            } else {
                generationComponentCount++;
            }
        }
    }

    EXPECT_EQ(28500, backgroundComponentCount);
    EXPECT_EQ(1500, generationComponentCount);
    EXPECT_EQ(14652, gridComponentCount);
}

int main(int argc, char **argv) {
    std::cout << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

