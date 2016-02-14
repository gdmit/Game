// Copyright (c) 2016 Evolution Team. All rights reserved.

#include "../include/ViewModel.h"
#include "../../model/include/GameProcess.h"
#include "../../model/include/Vector3D.h"

Vector3uc ViewModel::populationColorsBGR[MAX_POPULATION_COUNT] = {
    Vector3uc(0, 255, 0), Vector3uc(255, 0, 0), Vector3uc(0, 0, 255), Vector3uc(80, 127, 255),
    Vector3uc(32, 165, 218), Vector3uc(255, 255, 0), Vector3uc(255, 0, 255), Vector3uc(254, 0, 0),
    Vector3uc(19, 69, 139), Vector3uc(0, 128, 128) };

Vector3uc ViewModel::backgroundColorBGR = Vector3uc(255, 255, 255);
Vector3uc ViewModel::gridLineColorBGR = Vector3uc(0, 0, 0);

ViewModel::ViewModel(Vector2i textureSize, Vector2i mapSize) {
    gameProcess = new GameProcess(mapSize);

    horizontalLinesCount = gameProcess->getMapHeight() + 1;
    verticalLinesCount = gameProcess->getMapWidth() + 1;
    lineWidth = 1;

    texture = new Texture2D(textureSize.x, textureSize.y, 3);

    float stepX = static_cast<float>((texture->width - verticalLinesCount * lineWidth)) / gameProcess->getMapWidth();
    float stepY = static_cast<float>((texture->height - horizontalLinesCount * lineWidth)) / gameProcess->getMapHeight();
    cellSize = std::min(stepX, stepY);

    horizontalCellsBorders = new int[gameProcess->getMapHeight() * 2];
    verticalCellsBorders = new int[gameProcess->getMapWidth() * 2];
    calculateCellsBorders();

    fillBackgroundPixels();
    fillGridLinesPixels();
    fillGenerationPixels();
}

void ViewModel::updateTexture() {
    gameProcess->getNextGeneration();

    fillBackgroundPixels();
    fillGridLinesPixels();
    fillGenerationPixels();
}

void ViewModel::calculateCellsBorders() {
    float rowOffset = cellSize + lineWidth;
    float upCornerOffset = lineWidth;
    float downCornerOffset = lineWidth + cellSize;
    for (int row = 0; row < 2 * (horizontalLinesCount - 1); row += 2, upCornerOffset += rowOffset,
                                                                      downCornerOffset += rowOffset) {
        horizontalCellsBorders[row + 0] = static_cast<int>(upCornerOffset);
        horizontalCellsBorders[row + 1] = static_cast<int>(downCornerOffset);
    }

    float colOffset = (cellSize + lineWidth) * texture->channels;
    float leftCornerOffset = lineWidth * texture->channels;
    float rightCornerOffset = (lineWidth + cellSize) * texture->channels;
    for (int col = 0; col < 2 * (verticalLinesCount - 1); col += 2, leftCornerOffset += colOffset,
                                                                    rightCornerOffset += colOffset) {
        verticalCellsBorders[col + 0] = static_cast<int>(leftCornerOffset) - static_cast<int>(leftCornerOffset) % texture->channels;
        verticalCellsBorders[col + 1] = static_cast<int>(rightCornerOffset) - static_cast<int>(rightCornerOffset) % texture->channels;
    }
}

void ViewModel::fillBackgroundPixels() {
    for (int i = 0; i < texture->height * texture->width * texture->channels; i += texture->channels) {
        texture->colors[i + 0] = backgroundColorBGR.x;
        texture->colors[i + 1] = backgroundColorBGR.y;
        texture->colors[i + 2] = backgroundColorBGR.z;
    }
}

void ViewModel::fillGridLinesPixels() {
    fillHorizontalLinesPixels();
    fillVerticalLinesPixels();
}

void ViewModel::fillHorizontalLinesPixels() {
    int byteInRow = texture->width * texture->channels;
    int byteInLine = lineWidth * texture->channels;
    for (int i = 0, row = 0; i < 2 * gameProcess->getMapHeight(); i += 2, row = horizontalCellsBorders[i] - lineWidth) {
        for (int col = 0; col < verticalCellsBorders[2 * gameProcess->getMapWidth() - 1] + byteInLine; col += texture->channels) {
            for (int width = 0; width < lineWidth; width++) {
                texture->colors[(row + width) * byteInRow + col + 0] = gridLineColorBGR.x;
                texture->colors[(row + width) * byteInRow + col + 1] = gridLineColorBGR.y;
                texture->colors[(row + width) * byteInRow + col + 2] = gridLineColorBGR.z;
            }
        }
    }

    float rowOffset = (cellSize + lineWidth) * (horizontalLinesCount - 1);
    for (int col = 0; col < verticalCellsBorders[2 * gameProcess->getMapWidth() - 1] + byteInLine; col += texture->channels) {
        for (int width = 0; width < lineWidth; width++) {
            int pixelOffset = static_cast<int>(rowOffset);
            texture->colors[(pixelOffset + width) * byteInRow + col + 0] = gridLineColorBGR.x;
            texture->colors[(pixelOffset + width) * byteInRow + col + 1] = gridLineColorBGR.y;
            texture->colors[(pixelOffset + width) * byteInRow + col + 2] = gridLineColorBGR.z;
        }
    }
}

void ViewModel::fillVerticalLinesPixels() {
    int byteInRow = texture->width * texture->channels;
    int byteInLine = lineWidth * texture->channels;
    for (int row = 0; row < horizontalCellsBorders[2 * gameProcess->getMapHeight() - 1] + lineWidth; row++) {
        for (int i = 0, col = 0; i < 2 * gameProcess->getMapWidth(); i += 2, col = verticalCellsBorders[i] - byteInLine) {
            for (int width = 0; width < byteInLine; width += texture->channels) {
                texture->colors[row * byteInRow + col + width + 0] = gridLineColorBGR.x;
                texture->colors[row * byteInRow + col + width + 1] = gridLineColorBGR.y;
                texture->colors[row * byteInRow + col + width + 2] = gridLineColorBGR.z;
            }
        }

        float colOffset = (cellSize + lineWidth) * texture->channels * (verticalLinesCount - 1);
        for (int width = 0; width < lineWidth * texture->channels; width += texture->channels) {
            int pixelOffset = static_cast<int>(colOffset) - static_cast<int>(colOffset) % 3;
            texture->colors[row * byteInRow + pixelOffset + width + 0] = gridLineColorBGR.x;
            texture->colors[row * byteInRow + pixelOffset + width + 1] = gridLineColorBGR.y;
            texture->colors[row * byteInRow + pixelOffset + width + 2] = gridLineColorBGR.z;
        }
    }
}
void ViewModel::fillGenerationPixels() {
    static int colorCounter;
    int byteInRow = texture->width * texture->channels;
    for (int row = 0; row < gameProcess->getMapHeight(); row++) {
        for (int col = 0; col < gameProcess->getMapWidth(); col++) {
            if (gameProcess->generation[row * gameProcess->getMapWidth() + col] != -1) {
                for (int sRow = horizontalCellsBorders[2 * row]; sRow < horizontalCellsBorders[2 * row + 1]; sRow++) {
                    for (int sCol = verticalCellsBorders[2 * col]; sCol < verticalCellsBorders[2 * col + 1]; sCol += texture->channels) {
                        texture->colors[sRow * byteInRow + sCol + 0] = populationColorsBGR[colorCounter % 10].x;
                        texture->colors[sRow * byteInRow + sCol + 1] = populationColorsBGR[colorCounter % 10].y;
                        texture->colors[sRow * byteInRow + sCol + 2] = populationColorsBGR[colorCounter % 10].z;
                    }
                }
            }
        }
    }
    colorCounter++;
}
