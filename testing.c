#include <stdio.h>

#include "vector.h"
#include "line.h"
#include "plane.h"

int main() {
    // printing plane
    struct Plane p;
    
    struct Vector pp;
    struct Vector nn;

    p.A = 0;
    p.B = -5;
    p.C = 4;
    p.D = 22;

    printPlane(p);

    // checking for intersection of lines
    struct Line a;
    struct Line b;

    a.point.i = -2;
    a.point.j = -1;
    a.point.k = 0;
    a.dirVec.i = 1;
    a.dirVec.j = 1;
    a.dirVec.k = 1;
    b.point.i = 8;
    b.point.j = -6;
    b.point.k = -11;
    b.dirVec.i = -2;
    b.dirVec.j = 3;
    b.dirVec.k = 5;

    struct Vector vec1;
    vec1 = lineIntersectLine(a, b);

    printVector(vec1);

    // checking for intersection of skew lines
    struct Line c;
    struct Line d;

    a.point.i = 2;
    a.point.j = 2;
    a.point.k = 1;
    a.dirVec.i = 3;
    a.dirVec.j = 1;
    a.dirVec.k = -3;
    b.point.i = 1;
    b.point.j = 0;
    b.point.k = 1;
    b.dirVec.i = 6;
    b.dirVec.j = -4;
    b.dirVec.k = 9;

    struct Vector vec2;
    vec2 = lineIntersectLine(c, d);

    printVector(vec2);

    // normalize vector
    struct Vector test;
    
    test.i = 2;
    test.j = 3;
    test.k = 5;

    normalize(&test, magnitude(test));

    printVector(test);

    // intersection of line and plane (one soln)
    struct Line testLine;
    
    testLine.point.i = 2;
    testLine.point.j = 1;
    testLine.point.k = 0;
    testLine.dirVec.i = -1;
    testLine.dirVec.j = 1;
    testLine.dirVec.k = 3;

    struct Plane testPlane;

    testPlane.A = 3;
    testPlane.B = -2;
    testPlane.C = 1;
    testPlane.D = 10;

    struct Vector testVec;
    testVec = lineIntersectPlane(testLine, testPlane);
    printVector(testVec);

    // intersection of line and plane (zero solns)
    struct Line someLine;
    
    someLine.point.i = 1;
    someLine.point.j = -2;
    someLine.point.k = -1;
    someLine.dirVec.i = 2;
    someLine.dirVec.j = 3;
    someLine.dirVec.k = 4;

    struct Plane somePlane;

    somePlane.A = 1;
    somePlane.B = 2;
    somePlane.C = -2;
    somePlane.D = 5;

    struct Vector someVec;
    someVec = lineIntersectPlane(someLine, somePlane);
    printVector(someVec);

    // intersection of line and plane (inf solns)
    struct Line otherLine;
    
    otherLine.point.i = 1;
    otherLine.point.j = -2;
    otherLine.point.k = -1;
    otherLine.dirVec.i = 2;
    otherLine.dirVec.j = 3;
    otherLine.dirVec.k = 4;

    struct Plane otherPlane;

    otherPlane.A = 1;
    otherPlane.B = 2;
    otherPlane.C = -2;
    otherPlane.D = -1;

    struct Vector otherVec;
    otherVec = lineIntersectPlane(otherLine, otherPlane);
    printVector(otherVec);

    // intersection of two planes on a line
    struct Plane iPlane;
    iPlane.A = 3;
    iPlane.B = -1;
    iPlane.C = 2;
    iPlane.D = 4;

    struct Plane uPlane;
    uPlane.A = -2;
    uPlane.B = 1;
    uPlane.C = -4;
    uPlane.D = -3;

    struct Line ourLine;
    ourLine = planeIntersectPlane(iPlane, uPlane);
    printLine(ourLine);

    // distance from point to line
    struct Vector thisIsAPoint;
    
    thisIsAPoint.i = -2;
    thisIsAPoint.j = 8;
    thisIsAPoint.k = 1;

    struct Line thisIsALine;

    thisIsALine.point.i = 2.0 / 3.0;
    thisIsALine.point.j = 7.0 / 3.0;
    thisIsALine.point.k = 0;
    thisIsALine.dirVec.i = -1.0 / 3.0;
    thisIsALine.dirVec.j = -2.0 / 3.0;
    thisIsALine.dirVec.k = 1;

    float dist = pointLineDistance(thisIsAPoint, thisIsALine);

    printf("distance = %f\n", dist);

    // distance from point to plane
    struct Vector samplePoint;
    
    samplePoint.i = 4;
    samplePoint.j = -4;
    samplePoint.k = 3;

    struct Plane samplePlane;

    samplePlane.A = 2;
    samplePlane.B = -2;
    samplePlane.C = 5;
    samplePlane.D = -8;

    float ptPlnDist = pointPlaneDistance(samplePoint, samplePlane);

    printf("distance = %f\n", ptPlnDist);

    return 0;
}
