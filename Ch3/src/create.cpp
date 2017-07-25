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

  const int width = 200;
  const int height = 100;
  const unsigned char channels = 3;
  int index;

  unsigned char* data = new unsigned char[width * height * channels];

  vec3 lower_left_corner(-2.0, -1.0, -1.0);
  vec3 horizontal(4.0, 0.0, 0.0);
  vec3 vertical(0.0, 2.0, 0.0);
  vec3 origin(0.0, 0.0, 0.0);

  for (int y = height - 1; y >= 0; y--) {
    for (int x = 0; x < width; x++) {

      // Calculate the index using top left as origin
      index = (y * width * channels) + (x * channels);
      // Flip it to use bottom left as origin
      index = (width * height * channels) - index;

      float u = (float) x / (float) width;
      float v = (float) y / (float) height;
      
      ray r(origin, lower_left_corner + u * horizontal + v * vertical);
      vec3 col = color(r);

      data[index]     = col.x * 255; // Red channel
      data[index + 1] = col.y * 255; // Green channel
      data[index + 2] = col.z * 255; // Blue channel
    }
  }

  stbi_write_png(argv[1], width, height, channels, data, width * channels);

  delete[] data;

  return 0;
}
