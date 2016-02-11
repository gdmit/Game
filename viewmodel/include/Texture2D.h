// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef VIEWMODEL_INCLUDE_TEXTURE2D_H_
#define VIEWMODEL_INCLUDE_TEXTURE2D_H_


class Texture2D {
 public:
    int width;
    int height;
    unsigned char *colors;
    int channels;

    Texture2D(int height, int width, int channels);
};

#endif  // VIEWMODEL_INCLUDE_TEXTURE2D_H_
