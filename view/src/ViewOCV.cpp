// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <opencv2/highgui/highgui.hpp>
#include "ViewOCV.h"
#include "../../viewmodel/include/ViewModel.h"

ViewOCV::ViewOCV(int width, int height, std::string title) {
    windowWidth = width;
    windowHeight = height;
    windowTitle = title;

    viewModel = new ViewModel(windowWidth, windowHeight);
}

void ViewOCV::show() {
    cv::namedWindow(windowTitle, CV_WINDOW_NORMAL);

    while (true) {
        viewModel->updateTexture();
        image = cv::Mat(windowHeight, windowWidth, CV_8UC3, viewModel->texture->colors,
                        static_cast<size_t>(windowWidth * 3));
        cv::imshow(windowTitle, image);

        char keyCode = static_cast<char>((cv::waitKey(updateDelay)));
        if (keyCode == KeyCodes::ESC) {
            break;
        }
    }
}

