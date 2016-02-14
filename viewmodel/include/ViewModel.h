// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef VIEWMODEL_INCLUDE_VIEWMODEL_H_
#define VIEWMODEL_INCLUDE_VIEWMODEL_H_

#include <../../model/include/Vector3D.h>
#include "../../view/include/IViewModel.h"

class ViewModel : public IViewModel {
private:
    static const int MAX_POPULATION_COUNT = 10;
    static Vector3uc populationColorsBGR[MAX_POPULATION_COUNT];
    static Vector3uc backgroundColorBGR;
    static Vector3uc gridLineColorBGR;

    int horizontalLinesCount;
    int verticalLinesCount;
    int lineWidth;
    float cellSize;

    int* horizontalCellsBorders;
    int* verticalCellsBorders;

    void calculateCellsBorders();
    void fillBackgroundPixels();
    void fillGridLinesPixels();
    void fillGenerationPixels();
    void fillHorizontalLinesPixels();
    void fillVerticalLinesPixels();
public:
    ViewModel(Vector2i textureSize, Vector2i mapSize);
    virtual void updateTexture();
    virtual void nextGeneration();
    void setMapCell(int x, int y, int populationID);
};
#endif  // VIEWMODEL_INCLUDE_VIEWMODEL_H_
