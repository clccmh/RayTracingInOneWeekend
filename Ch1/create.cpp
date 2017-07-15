#include <stdlib.h>
#include <iostream>

int main() {
  int width = 7680;
  int height = 4320;

  std::cout << "P3\n" << width << " " << height << "\n255\n";

  //std::cout << 255/float(width) << std::endl;

  for (float g = 0; g < height; g++) {
    for (float r = 0; r < width; r++) {
      
      std::cout << int((r/width)*255) << " " << int((g/height)*255) << " 0\n";
    }
  }

  return 0;
}
