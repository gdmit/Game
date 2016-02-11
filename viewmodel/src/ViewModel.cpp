// Copyright (c) 2016 Evolution Team. All rights reserved.

#include "../include/ViewModel.h"
#include "../../model/include/GameProcess.h"
#include "../../model/include/Vector2D.h"

ViewModel::ViewModel(int width, int height) {
    gameProcess = new GameProcess();
    texture = new Texture2D(width, height, 3);
}

void ViewModel::updateTexture() {
    gameProcess->getNextGeneration();

    Vector2i mapSize = gameProcess->getMapSize();

    int linesCountX = gameProcess->getMapHeight() + 1;
    int linesCountY = gameProcess->getMapWidth() + 1;
    int lineWidth = 2;
    int stepX = (texture->width - linesCountX * lineWidth) / gameProcess->getMapHeight();
    int stepY = (texture->height - linesCountY * lineWidth) / gameProcess->getMapWidth();
    fillBackgroundPixels();
    fillGridLinesPixels(stepX, stepY, lineWidth);
    fillGenerationPixels(stepX, stepY, lineWidth);
}

void ViewModel::fillBackgroundPixels() {
    for (int i = 0; i < texture->height * texture->width * texture->channels; i++) {
        texture->colors[i] = 80;
    }
}

void ViewModel::fillGridLinesPixels(int stepX, int stepY, int lineWidth) {
    for (int row = 0; row < texture->height; row++) {
        for (int col = 0; col < texture->width * texture->channels; col += (stepY + lineWidth) * texture->channels) {
            for (int width = 0; width < lineWidth * texture->channels; width++) {
                texture->colors[row * texture->width * texture->channels + col + width] = GRID_LINE_COLOR;
            }
        }
    }

    for (int row = 0; row < texture->height; row += stepX + lineWidth) {
        for (int col = 0; col < texture->width * texture->channels; col+= texture->channels) {
            for (int width = 0; width < lineWidth; width++) {
                for (int ch = 0; ch < texture->channels; ch++) {
                    texture->colors[(row + width) * texture->width * texture->channels + col + ch] = GRID_LINE_COLOR;
                }
            }
        }
    }
}

void ViewModel::fillGenerationPixels(int stepX, int stepY, int lineWidth) {
    for (int row = 0; row < gameProcess->getMapHeight(); row++) {
        for (int col = 0; col < gameProcess->getMapWidth(); col++) {
            if (gameProcess->generation[row * gameProcess->getMapWidth() + col] != -1) {
                int sRowStart = lineWidth * (row + 1) + stepX * row;
                int sRowEnd = sRowStart + stepX;

                int sColStart = (lineWidth * (col + 1) + stepY * col) * texture->channels;
                int sColStep = texture->channels;
                int sColEnd = sColStart + stepY * texture->channels;

                int stride = texture->width * texture->channels;
                
                for (int sRow = sRowStart; sRow < sRowEnd; sRow++) {
                    for (int sCol = sColStart; sCol < sColEnd; sCol += sColStep) {
                        texture->colors[sRow * stride + sCol + 0] = POPULATION_COLOR_R;
                        texture->colors[sRow * stride + sCol + 1] = POPULATION_COLOR_G;
                        texture->colors[sRow * stride + sCol + 2] = POPULATION_COLOR_B;
                    }
                }
            }
        }
    }
}
