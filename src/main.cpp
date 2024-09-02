#include <cstdlib>
#include <iostream>

namespace rt {
extern void renderImage();
}

int main() {
  rt::renderImage();

  return EXIT_SUCCESS;
}