#include <stdio.h>
#include <math.h>

struct Line {
    struct Vector point;
    struct Vector dirVec;
};

void printLine(struct Line a) {
    printf("[%f, %f, %f] + t[%f, %f, %f]\n", a.point.i, a.point.j, a.point.k, a.dirVec.i, a.dirVec.j, a.dirVec.k);
}

// solves a system of three parametric equations using a modified version of Cramer's rule
struct Vector lineIntersectLine(struct Line line1, struct Line line2) {
    float a = line1.dirVec.i;
    float b = -1 * line2.dirVec.i;
    float e = line2.point.i - line1.point.i;
    
    float c = line1.dirVec.j;
    float d = -1 * line2.dirVec.j;
    float f = line2.point.j - line1.point.j;

    float determinant = a*d - b*c;

    struct Vector ans;

    float alpha = (e*d - b*f) / determinant;
    float beta = (a*f - e*c) / determinant;

    if (determinant != 0 && (line1.point.k + alpha*line1.dirVec.k) == (line2.point.k + beta*line2.dirVec.k)) {
        ans.i = line1.point.i + alpha*line1.dirVec.i;
        ans.j = line1.point.j + alpha*line1.dirVec.j;
        ans.k = line1.point.k + alpha*line1.dirVec.k;
    } else {
        ans.i = INFINITY;
        ans.j = INFINITY;
        ans.k = INFINITY;
    }

    return ans;
}

float pointLineDistance(struct Vector x0, struct Line line) {
    struct Vector x1;
    
    x1.i = line.point.i;
    x1.j = line.point.j;
    x1.k = line.point.k;

    struct Vector x2;

    x2.i = line.point.i + line.dirVec.i;
    x2.j = line.point.j + line.dirVec.j;
    x2.k = line.point.k + line.dirVec.k;
    
    return magnitude(cross(subtract(x0, x1), subtract(x0, x2))) / magnitude(subtract(x2, x1));
}

int pointOnLine(struct Vector pt, struct Line line) {
    float tx = (pt.i - line.point.i) / line.dirVec.i;
    float ty = (pt.j - line.point.j) / line.dirVec.j;
    float tz = (pt.k - line.point.k) / line.dirVec.k;

    return (tx == ty) && (ty == tz);
}
