// Copyright (c) 2016 Evolution Team. All rights reserved.

#include "../../view/include/IViewModel.h"
#include "../../viewmodel/include/ViewModel.h"
#include "ViewOCV.h"
int main(int argc, char* argv[]) {
    ViewOCV *view = new ViewOCV(1000, 1000, "Game of Life (OpenCV)");
    view->show();
    return 0;
}
