https://www.youtube.com/watch?v=fO-BOwalGnk
https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCWsH9Tj9oWyDM4W43VMj5yo2PdyYMGst
https://www.youtube.com/watch?v=xZe0ZYPzxkg
https://www.youtube.com/watch?v=ebzlMOw79Yw
https://www.youtube.com/watch?v=2beZWqv_gGA
https://www.youtube.com/watch?v=g8p7nAbDz6Y
https://www.youtube.com/watch?v=G9i78WoBBIU
https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx
https://siril.readthedocs.io/fr/latest/processing/pixelmath.html
https://www.youtube.com/watch?v=ZnMU9MWU2pM
https://www.youtube.com/watch?v=Qr7UlrWVCpI 
https://www.youtube.com/watch?v=Cg-aWMDHFLE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>  // Pour _kbhit et _getch (sur Windows), sinon utilisez une autre méthode selon votre OS

#define DEG_TO_RAD (M_PI / 180.0)

float rotationSpeed = 45.0f;  // Vitesse de rotation en degrés par seconde
float currentEulerAngles[3] = {0.0f, 0.0f, 0.0f};  // X, Y, Z
float x = 0.0f, y = 0.0f, z = 0.0f;  // États des axes X, Y, Z

void updateRotation(float deltaTime) {
    // Modification de la rotation en fonction des entrées
    currentEulerAngles[0] += x * deltaTime * rotationSpeed;
    currentEulerAngles[1] += y * deltaTime * rotationSpeed;
    currentEulerAngles[2] += z * deltaTime * rotationSpeed;

    // Affichage des valeurs de rotation
    printf("Rotation X: %.2f Y: %.2f Z: %.2f\n", currentEulerAngles[0], currentEulerAngles[1], currentEulerAngles[2]);
}

void handleInput() {
    if (_kbhit()) {  // Vérifie si une touche est pressée (spécifique à Windows, voir une alternative pour Linux)
        char key = _getch();  // Récupère la touche pressée

        // Inverser les valeurs de x, y, z selon les touches pressées
        if (key == 'x' || key == 'X') {
            x = 1.0f - x;
        } else if (key == 'y' || key == 'Y') {
            y = 1.0f - y;
        } else if (key == 'z' || key == 'Z') {
            z = 1.0f - z;
        }
    }
}

int main() {
    // Simuler un deltaTime, en pratique, cela dépendra du temps réel écoulé entre les frames
    float deltaTime = 0.016f;  // Exemple avec 60 FPS, donc deltaTime = 1 / 60

    while (1) {
        handleInput();  // Vérifie les entrées clavier
        updateRotation(deltaTime);  // Met à jour la rotation

        // Attendre un peu pour simuler un FPS stable (ajuster selon besoin)
        _sleep(16);  // 16ms, pour environ 60 FPS
    }
    return 0;
}
