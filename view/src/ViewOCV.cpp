// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <opencv2/highgui/highgui.hpp>
#include "ViewOCV.h"
#include "../../viewmodel/include/ViewModel.h"

ViewOCV::ViewOCV(Vector2i textureSize, Vector2i mapSize, std::string title) {
    windowWidth = textureSize.x;
    windowHeight = textureSize.y;
    windowTitle = title;

    viewModel = new ViewModel(textureSize, mapSize);
}

void ViewOCV::onMouse(int event, int x, int y, int, void*) {
    if (event == cv::EVENT_LBUTTONDOWN) {
        return;
    }
}

void ViewOCV::show() {
    int delay = updateDelay;
    cv::namedWindow(windowTitle, CV_WINDOW_NORMAL);
    cv::setMouseCallback(windowTitle, onMouse, 0);
    while (true) {
        image = cv::Mat(windowHeight, windowWidth, CV_8UC3, viewModel->texture->colors,
                        static_cast<size_t>(windowWidth * 3));
        cv::imshow(windowTitle, image);

        char keyCode = static_cast<char>((cv::waitKey(delay)));
        switch (keyCode) {
            case KeyCodes::ESC:
                return;
            case KeyCodes::SPACE:
                delay = (delay > 0) ? 0 : updateDelay;
                break;
            default:
                break;
        }
        viewModel->updateTexture();
    }
}

