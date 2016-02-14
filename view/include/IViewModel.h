// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef VIEW_INCLUDE_IVIEWMODEL_H_
#define VIEW_INCLUDE_IVIEWMODEL_H_

#include "../../viewmodel/include/IGameProcess.h"
#include "../../viewmodel/include/Texture2D.h"

class IViewModel {
 protected:
    IGameProcess *gameProcess;
    IViewModel() { }
 public:
    Texture2D *texture;
    virtual void updateTexture() = 0;

};

#endif  // VIEW_INCLUDE_IVIEWMODEL_H_
