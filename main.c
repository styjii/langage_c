#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float a, b, x;
    printf("Enter a = ");
    scanf("%f", &a);
    printf("Enter b = ");
    scanf("%f", &b);
    if (a != 0) {
        x = -b / a;
    }
    else {
        printf("Pas de solution");
    }
    printf("La solution de x est %f\n", x);
}