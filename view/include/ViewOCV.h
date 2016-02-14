// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef VIEW_INCLUDE_VIEWOCV_H_
#define VIEW_INCLUDE_VIEWOCV_H_

#include <opencv2/core/core.hpp>
#include "IViewModel.h"

struct KeyCodes {
    static const int ESC = 27;
    static const int SPACE = 32;
};

class ViewOCV {
 private:
    static const int updateDelay = 60;
    IViewModel* viewModel;
    cv::Mat image;
    std::string windowTitle;
    int windowWidth;
    int windowHeight;

    static void onMouse(int event, int x, int y, int, void*);
 public:
    ViewOCV(Vector2i textureSize, Vector2i mapSize, std::string windowTitle);
    void show();
};


#endif  // VIEW_INCLUDE_VIEWOCV_H_
