#include <stdio.h>
#include <math.h>

struct Plane {
    // Ax + By + Cz = D
    float A;
    float B;
    float C;
    float D;
};

int pointOnPlane(struct Vector pt, struct Plane pln) {
    return (pln.A*pt.i + pln.B*pt.j + pln.C*pt.k) == pln.D;
}

struct Vector lineIntersectPlane(struct Line line, struct Plane p) {
    struct Vector ans;

    float d = line.dirVec.i;
    float e = line.dirVec.j;
    float f = line.dirVec.k;

    if (p.A*d + p.B*e + p.C*f == 0) {
        // zero or infinite points of intersection
        ans.i = INFINITY;
        ans.j = INFINITY;
        ans.k = INFINITY;
    } else {
        // single point of intersection
        float a = line.point.i;
        float b = line.point.j;
        float c = line.point.k;

        float t = (p.D - p.A*a - p.B*b - p.C*c) / (p.A*d + p.B*e + p.C*f);

        ans.i = a + t*d;
        ans.j = b + t*e;
        ans.k = c + t*f;
    }

    return ans;
}

struct Line planeIntersectPlane(struct Plane p1, struct Plane p2) {
    struct Vector p1n;
    p1n.i = p1.A;
    p1n.j = p1.B;
    p1n.k = p1.C;

    struct Vector p2n;
    p2n.i = p2.A;
    p2n.j = p2.B;
    p2n.k = p2.C;

    // direction vector for line of intersection
    struct Vector a;
    a = cross(p1n, p2n);

    struct Line ans;

    if (a.i != 0) {
        // set x = 0 and use Cramer's rule
        float det = p1.B*p2.C - p1.C*p2.B;
        
        if (det != 0) {
            ans.point.i = 0;
            ans.point.j = (p1.D*p2.C - p1.C*p2.D) / det;
            ans.point.k = (p1.B*p2.D - p1.D*p2.B) / det;
            ans.dirVec = a;
            
            return ans;
        }
    } else if (a.j != 0) {
        // set y = 0 and use Cramer's rule
        float det = p1.A*p2.C - p1.C*p2.A;
        
        if (det != 0) {
            ans.point.i = (p1.D*p2.C - p1.C*p2.D) / det;
            ans.point.j = 0;
            ans.point.k = (p1.A*p2.D - p1.D*p2.A) / det;
            ans.dirVec = a;
            
            return ans;
        }
    } else {
        // set z = 0 and use Cramer's rule
        float det = p1.A*p2.B - p1.B*p2.A;
        
        if (det != 0) {
            ans.point.i = (p1.D*p2.B - p1.B*p2.D) / det;
            ans.point.j = (p1.A*p2.D - p1.D*p2.A) / det;
            ans.point.k = 0;
            ans.dirVec = a;
            
            return ans;
        }
    }

    ans.point.i = INFINITY;
    ans.point.j = INFINITY;
    ans.point.k = INFINITY;
    ans.dirVec.i = INFINITY;
    ans.dirVec.j = INFINITY;
    ans.dirVec.k = INFINITY;

    return ans;
}

float pointPlaneDistance(struct Vector pt, struct Plane p) {
    return (p.A*pt.i + p.B*pt.j + p.C*pt.k - p.D) / sqrt(p.A*p.A + p.B*p.B + p.C*p.C);
}

void printPlane(struct Plane p) {
    printf("%f 𝔁 ", p.A);

    if (p.B < 0) {
        printf("- %f 𝔂 ", -1 * p.B);
    } else {
        printf("+ %f 𝔂 ", p.B);
    }

    if (p.C < 0) {
        printf("- %f 𝔃 = ", -1 * p.C);
    } else {
        printf("+ %f 𝔃 = ", p.C);
    }

    printf("%f\n", p.D);
}
