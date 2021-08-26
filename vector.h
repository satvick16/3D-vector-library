#include <stdio.h>
#include <math.h>

struct Vector {
    float i;
    float j;
    float k;
};

void printVector(struct Vector vec) {
    printf("[%f, %f, %f]\n", vec.i, vec.j, vec.k);
}

int equals(struct Vector a, struct Vector b) {
    return (a.i == b.i) && (a.j == b.j) && (a.k == b.k);
}

struct Vector cross(struct Vector a, struct Vector b) {
    struct Vector new;

    new.i = (a.j) * (b.k) - (a.k) * (b.j);
    new.j = (a.k) * (b.i) - (a.i) * (b.k);
    new.k = (a.i) * (b.j) - (a.j) * (b.i);

    return new;
}

struct Vector add(struct Vector a, struct Vector b) {
    struct Vector new;

    new.i = a.i + b.i;
    new.j = a.j + b.j;
    new.k = a.k + b.k;

    return new;
}

struct Vector subtract(struct Vector a, struct Vector b) {
    struct Vector new;

    new.i = a.i - b.i;
    new.j = a.j - b.j;
    new.k = a.k - b.k;

    return new;
}

float dot(struct Vector a, struct Vector b) {
    return (a.i) * (b.i) + (a.j) * (b.j) + (a.k) * (b.k);
}

float magnitude(struct Vector vec) {
    return sqrt((vec.i * vec.i) + (vec.j * vec.j) + (vec.k * vec.k));
}

// converts a vector into one with the same direction and magnitude of 1
void normalize(struct Vector *vec, float mag) {
    vec -> i /= mag;
    vec -> j /= mag;
    vec -> k /= mag;
}

float angleBetween(struct Vector a, struct Vector b) {
    return dot(a, b) / magnitude(a) * magnitude(b);
}
