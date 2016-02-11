// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef VIEWMODEL_INCLUDE_VIEWMODEL_H_
#define VIEWMODEL_INCLUDE_VIEWMODEL_H_

#include "../../view/include/IViewModel.h"

#define BACKGROUND_COLOR 80
#define GRID_LINE_COLOR 255
#define POPULATION_COLOR_R 254
#define POPULATION_COLOR_G 0
#define POPULATION_COLOR_B 0

class ViewModel : public IViewModel {
private:
    void fillBackgroundPixels();
    void fillGridLinesPixels(int stepX, int stepY, int lineWidth);
    void fillGenerationPixels(int stepX, int stepY, int lineWidth);
public:
    ViewModel(int width, int height);
    virtual void updateTexture();

};

#endif  // VIEWMODEL_INCLUDE_VIEWMODEL_H_
