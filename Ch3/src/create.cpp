#include <stdlib.h>
#include <iostream>
#include "vec3.h"

// I need to grok this. I have no idea what it does.
vec3 color(const ray& r) {
  vec3 unit_direction = r.direction().unit_vector();
  // Scale the unit vector down such that 1.0 = BLue, and 0.0 = White
  // Originaly such that -1.0 = White and 1.0 = Blue
  float t = 0.5*(unit_direction.y() + 1.0);
  return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main() {
  int width = 200;
  int height = 100;

  std::cout << "P3\n" << width << " " << height << "\n255\n";
  
  for (float g = 0; g < height; g++) {
    for (float r = 0; r < width; r++) {
      
      vec3 col(float(r) / float(width), float(g) / float(height), 0.0);
      std::cout << int(col.x*255) << " " << int(col.y*255) << col.z << std::endl;
    }
  }

  return 0;
}
