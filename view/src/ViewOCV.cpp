// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <opencv2/highgui/highgui.hpp>
#include "ViewOCV.h"
#include "../../viewmodel/include/ViewModel.h"

ViewOCV::ViewOCV(Vector2i textureSize, Vector2i mapSize) {
    viewModel = new ViewModel(textureSize, mapSize);
}

void ViewOCV::onMouse(int event, int x, int y, int flags, void* params) {
    ViewModel* viewModel = static_cast<ViewModel*>(params);

    if (event == cv::EVENT_LBUTTONDOWN) {
        if (x < 0 || x > viewModel->texture->width || y < 0 || y > viewModel->texture->height) {
            return;
        }

        viewModel->setMapCell(x, y, 0);
        viewModel->updateTexture();
        drawViewModel(viewModel);
    }
}

void ViewOCV::show() {
    int delay = updateDelay;
    cv::namedWindow(windowTitle, CV_WINDOW_NORMAL);
    cv::setMouseCallback(windowTitle, onMouse, viewModel);
    while (true) {
        drawViewModel(viewModel);

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
        viewModel->nextGeneration();
        viewModel->updateTexture();
    }
}

void ViewOCV::drawViewModel(IViewModel* viewModel) {
    cv::Mat image(viewModel->texture->height, viewModel->texture->width, CV_8UC3, viewModel->texture->colors,
                  static_cast<size_t>(viewModel->texture->width * 3));
    cv::imshow(windowTitle, image);
}

