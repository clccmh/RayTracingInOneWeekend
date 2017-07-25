/**
 * Author: Carter
 */

#include <iostream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

int main(int argc, char** argv) {

  if (argc != 2) {
    cout << "Incorrect number of arguments\nUsage: run.out output_file.png" << endl;
    return 1;
  }

  const int width = 1920;
  const int height = 1080;
  const char channels = 3;
  int index;

  unsigned char* data = new unsigned char[width * height * 3];

  for (int y = height - 1; y >= 0; y--) {
    for (int x = 0; x < width; x++) {

      index = ((height - 1 - y) * width * channels) + (x * channels);

      data[index]     = ((float) y / (float) height) * 255; // Red channel
      data[index + 1] = ((float) x / (float) width) * 255; // Green channel
      data[index + 2] = 0; // Blue channel
    }
  }

  stbi_write_png(argv[1], width, height, channels, data, width * channels);

  delete[] data;

  return 0;
}

