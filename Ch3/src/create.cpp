#include <iostream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "vec3.h"
#include "ray.h"

using namespace std;

// I need to grok this. I have no idea what it does.
vec3 color(const ray& r) {
  vec3 unit_direction = unit_vector(r.direction());
  // Scale the unit vector down such that 1.0 = BLue, and 0.0 = White
  // Originaly such that -1.0 = White and 1.0 = Blue
  float t = 0.5*(unit_direction.y + 1.0);
  return (1.0f-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Incorrect number of arguments\nUsage: run.out output_file.png" << endl;
    return 1;
  }

  const unsigned int width = 200;
  const unsigned int height = 100;
  const unsigned char channels = 3;
  unsigned int index;

  unsigned char* data = new unsigned char[width * height * channels];

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {

      index = (y * width * channels) + (x * channels);
      
      vec3 col(float(x) / float(width), float(y) / float(height), 0.0);

      data[index]     = col.x * 255; // Red channel
      data[index + 1] = col.y * 255; // Green channel
      data[index + 2] = 0; // Blue channel
    }
  }

  stbi_write_png(argv[1], width, height, channels, data, width * channels);

  delete[] data;

  return 0;
}
