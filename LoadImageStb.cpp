#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../stb-master/stb_image.h"
#include "../stb-master/stb_image_write.h"

int main() {
    int width, height, channels;

    // Abre a imagem
    unsigned char* img = stbi_load("images/aic-home.jpg", &width, &height, &channels, 4);

    // Escreve
    stbi_write_png("images/output/outStb.png", width, height, 4, img, width * 4);

    // Libera memoria usada da imagem
    stbi_image_free(img);
    return 0;
}
