#include "vector_to_img.h"
#include <iostream>

bool ImageExporter::saveImage(const std::vector<std::vector<Vector3D<int>>>& pixels, const std::string& filename, const std::string& format) {
    int width = pixels[0].size();
    int height = pixels.size();
    std::vector<unsigned char> imageData(width * height * 3);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            imageData[3 * (y * width + x) + 0] = pixels[y][x].x;
            imageData[3 * (y * width + x) + 1] = pixels[y][x].y;
            imageData[3 * (y * width + x) + 2] = pixels[y][x].z;
        }
    }

    if (format == "png") {
        return stbi_write_png(filename.c_str(), width, height, 3, imageData.data(), width * 3);
    } else if (format == "bmp") {
        return stbi_write_bmp(filename.c_str(), width, height, 3, imageData.data());
    } else if (format == "jpg") {
        return stbi_write_jpg(filename.c_str(), width, height, 3, imageData.data(), 100);
    } else {
        std::cerr << "Unsupported format: " << format << std::endl;
        return false;
    }
}
