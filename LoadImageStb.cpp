#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../stb-master/stb_image.h"
#include "../stb-master/stb_image_write.h"
#include <iostream>

using namespace std;

int main() {
    int width, height, channels;

    // Abre a imagem
    unsigned char* img = stbi_load("images/aic-home.jpg", &width, &height, &channels, 4);

    if(img==nullptr){
        cerr << "Error loading image" << endl;
        return 1;
    }

    // Process pixels
    int total_pixels = width * height * 4; // 4 canais por pixel
    for (int i = 0; i < width * height * 4; i += 4) {
        img[i] = 255 - img[i];     // R
        img[i + 1] = 255 - img[i + 1]; // G
        img[i + 2] = 255 - img[i + 2]; // B
        // img[i + 3] é o Alpha → não mexe
    }


    // Escreve
    stbi_write_png("images/output/outStb.png", width, height, 4, img, width * 4);

    // Libera memoria usada da imagem
    stbi_image_free(img);
    return 0;
}
