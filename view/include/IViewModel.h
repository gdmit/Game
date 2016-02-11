// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef VIEW_INCLUDE_IVIEWMODEL_H_
#define VIEW_INCLUDE_IVIEWMODEL_H_

#include "../../viewmodel/include/IGameProcess.h"
class IViewModel {
 protected:
    IGameProcess *gameProcess;
    int textureWidth;
    int textureHeight;
    float *textureColor;
    IViewModel() { }

};

#endif  // VIEW_INCLUDE_IVIEWMODEL_H_
