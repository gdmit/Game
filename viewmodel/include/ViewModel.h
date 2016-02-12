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

    void fillBackgroundPixels();
    void fillGridLinesPixels(int stepX, int stepY, int lineWidth);
    void fillGenerationPixels(int stepX, int stepY, int lineWidth);
public:
    ViewModel(int width, int height);
    virtual void updateTexture();

};
#endif  // VIEWMODEL_INCLUDE_VIEWMODEL_H_
