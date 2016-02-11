// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <Texture2D.h>

Texture2D::Texture2D(int width, int height, int channels)  : width(width), height(height), channels(channels) {
    colors = new unsigned char [width * height * channels];
}
