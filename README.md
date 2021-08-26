# 3D Vector Library

This repository contains the header files for a variety of structs and methods related to the creation and maipulation of 3D vectors, lines and planes. The file ```testing.c``` contains some demo code that tests the functionality of the library.

----

## Functionality

| Vectors (vector.h) | Lines (line.h) | Planes (plane.h)|
| ------------------- | ---------------- | ------- |
| initialize a vector by its components (i, j, k) | initialize a line by a point on the line and a direction vector | initialize a plane in the format: Ax + By + Cz = D |
| cross product | find point of intersection between two lines | determine whether a point is on the plane |
| dot product | find distance between point and line | find point of intersection between a line and a plane |
| add/subtract vectors | determine whether a point is on the line | find line of intersection between two planes |
| find vector magnitude |  | find distance from a point to a plane |
| vector normalization |
| find angle between vectors |

----

## Usage
To use the structs and methods in this repository, clone the repository and delete the testing file. In the same directory as the header files, create a C file and insert the following code:

```C
#include <stdio.h>

#include "vector.h"
#include "line.h"
#include "plane.h"
```
Now, any method in this C file can use the structs and methods in the header files. To see an exmaple of this in action, see the file ```testing.c```.
