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

ViewModel::ViewModel(int width, int height) {
    gameProcess = new GameProcess();
    texture = new Texture2D(width, height, 3);
}

void ViewModel::updateTexture() {
    gameProcess->getNextGeneration();

    Vector2i mapSize = gameProcess->getMapSize();

    int linesCountX = gameProcess->getMapHeight() + 1;
    int linesCountY = gameProcess->getMapWidth() + 1;
    int lineWidth = 1;
    int stepX = (texture->width - linesCountX * lineWidth) / gameProcess->getMapHeight();
    int stepY = (texture->height - linesCountY * lineWidth) / gameProcess->getMapWidth();
    fillBackgroundPixels();
    fillGridLinesPixels(stepX, stepY, lineWidth);
    fillGenerationPixels(stepX, stepY, lineWidth);
}

void ViewModel::fillBackgroundPixels() {
    for (int i = 0; i < texture->height * texture->width * texture->channels; i += texture->channels) {
        texture->colors[i + 0] = backgroundColorBGR.x;
        texture->colors[i + 1] = backgroundColorBGR.y;
        texture->colors[i + 2] = backgroundColorBGR.z;
    }
}

void ViewModel::fillGridLinesPixels(int stepX, int stepY, int lineWidth) {
    for (int row = 0; row < texture->height; row++) {
        for (int col = 0; col < texture->width * texture->channels; col += (stepY + lineWidth) * texture->channels) {
            for (int width = 0; width < lineWidth * texture->channels; width += texture->channels) {
                texture->colors[row * texture->width * texture->channels + col + width + 0] = gridLineColorBGR.x;
                texture->colors[row * texture->width * texture->channels + col + width + 1] = gridLineColorBGR.y;
                texture->colors[row * texture->width * texture->channels + col + width + 2] = gridLineColorBGR.z;
            }
        }
    }

    for (int row = 0; row < texture->height; row += stepX + lineWidth) {
        for (int col = 0; col < texture->width * texture->channels; col+= texture->channels) {
            for (int width = 0; width < lineWidth; width++) {
                texture->colors[(row + width) * texture->width * texture->channels + col + 0] = gridLineColorBGR.x;
                texture->colors[(row + width) * texture->width * texture->channels + col + 1] = gridLineColorBGR.y;
                texture->colors[(row + width) * texture->width * texture->channels + col + 2] = gridLineColorBGR.z;
            }
        }
    }
}

void ViewModel::fillGenerationPixels(int stepX, int stepY, int lineWidth) {
    static int colorCounter;
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
                        texture->colors[sRow * stride + sCol + 0] = populationColorsBGR[colorCounter%10].x;
                        texture->colors[sRow * stride + sCol + 1] = populationColorsBGR[colorCounter%10].y;
                        texture->colors[sRow * stride + sCol + 2] = populationColorsBGR[colorCounter%10].z;
                    }
                }
            }
        }
    }
    colorCounter++;
}
