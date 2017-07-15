#include <stdlib.h>
#include <iostream>
#include "vec3.h"

int main() {
  int width = 3840;
  int height = 2160;

  std::cout << "P3\n" << width << " " << height << "\n255\n";
  
  for (float g = 0; g < height; g++) {
    for (float r = 0; r < width; r++) {
      
      vec3 col(float(r) / float(width), float(g) / float(height), 0.0);
      std::cout << int(col.x*255) << " " << int(col.y*255) << col.z << std::endl;
    }
  }

  return 0;
}
