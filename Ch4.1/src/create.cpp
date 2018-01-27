/*
 * Questions to keep in mind:
 * - When scaling to larger aspect ratio numbers, how do I keep the scene the same size?
 */

#include <iostream>
#include <numeric>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "vec3.h"
#include "ray.h"

using namespace std;

bool hit_sphere(const vec3& center, float radius, const ray& r) {
 vec3 oc = r.origin() - center;
 float a = dot(r.direction(), r.direction());
 float b = 2.0 * dot(oc, r.direction());
 float c = dot(oc, oc) - radius * radius;
 float discriminant = b * b - 4 * a * c;
 return (discriminant > 0);
}


vec3 color(const ray& r) {
  if (hit_sphere(vec3(0,0,-1), 0.5, r)) {
    return vec3(1,0,0);
  }

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

  const int width = 1920;
  const int height = 1080;
  const int divisor = gcd(width, height);
  const int horizontal_scale = width / divisor;
  const int vertical_scale = height / divisor;
  const unsigned char channels = 3;
  int index;

  unsigned char* data = new unsigned char[width * height * channels];

  vec3 lower_left_corner(-1 * horizontal_scale, -1 * vertical_scale, -1.0);
  vec3 horizontal(horizontal_scale * 2, 0.0, 0.0);
  vec3 vertical(0.0, vertical_scale * 2, 0.0);
  vec3 origin(0.0, 0.0, 0.0);

  for (int y = height - 1; y >= 0; y--) {
    for (int x = 0; x < width; x++) {

      index = ((height - 1 - y) * width * channels) + (x * channels);

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
