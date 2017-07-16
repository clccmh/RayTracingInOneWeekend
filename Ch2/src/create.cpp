#include <stdlib.h>
#include <iostream>
#include "vec3.h"

int main() {
  int width = 1920;
  int height = 1080;

  std::cout << "P3\n" << width << " " << height << "\n255\n";
  
  for (float g = 0; g < height; g++) {
    for (float r = 0; r < width; r++) {
      vec3 col(r/width, g/height, 0.0);
      std::cout << int(col.x * 255) << " " << int(col.y * 255) << " " << int(col.z) << std::endl;
    }
  }

  return 0;
}
