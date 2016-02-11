// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <Texture2D.h>

Texture2D::Texture2D(int height, int width, int channels)  : height(height), width(width), channels(channels) {
    colors = new unsigned char [width * height * channels];
}
