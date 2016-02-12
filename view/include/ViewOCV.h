// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef VIEW_INCLUDE_VIEW_H_
#define VIEW_INCLUDE_VIEW_H_

#include <opencv2/core/core.hpp>
#include "IViewModel.h"

struct KeyCodes {
    static const int ESC = 27;
};

class ViewOCV {
 private:
    static const int updateDelay = 17;
    IViewModel* viewModel;
    cv::Mat image;
    std::string windowTitle;
    int windowWidth;
    int windowHeight;
 public:
    ViewOCV(int width, int height, std::string windowTitle);
    void show();
};


#endif  // VIEW_INCLUDE_VIEW_H_
