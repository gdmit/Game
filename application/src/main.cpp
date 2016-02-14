// Copyright (c) 2016 Evolution Team. All rights reserved.

#include "../../view/include/IViewModel.h"
#include "../../viewmodel/include/ViewModel.h"
#include "ViewOCV.h"
int main(int argc, char* argv[]) {
    ViewOCV *view = new ViewOCV(Vector2i(1920, 1080), Vector2i(70, 50));
    view->show();
    return 0;
}
