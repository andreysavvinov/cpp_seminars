#pragma once

#include <vec3D.h>
#include <string>
#include <vector>
#include "stb_image_write.h"

class ImageExporter {
    public:
        static bool saveImage(const std::vector<std::vector<Vector3D<int>>>& pixels, const std::string& filename, const std::string& format);
    };
