
/**
 * AUTHOR: Carter Hay
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define RGB 3
#define GREYSCALE 1

int main(int argc, char** argv) {

  int width  = 7680*2;
  int height = 4320*2;
  int comp   = RGB;
  int width_for_calc = width * comp;
  int y, x;
  char* data = malloc(width * height * comp * sizeof(char));

  if (argc == 2) {

    time_t before = time(0);

    for (y = 0; y < height; y++) {
      for (x = 0; x < width_for_calc; x+=comp) {
        data[y * width_for_calc + x] = 255 * ((float) x / (float) width_for_calc);
        data[y * width_for_calc + x + 1] = 0;
        data[y * width_for_calc + x + 2] = 255 * ((float) y / (float) height);
      }
    }

    stbi_write_png(argv[1], width, height, comp, data, width * comp);

    printf("Image was generated in %d seconds.", time(0) - before);

  } else {
    printf("Argument not included");
    return 1;
  }

  return 0;
}
