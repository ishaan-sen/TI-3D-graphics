#include "3d-gfx.h"
#include <graphx.h>
#include <math.h>

triangle_t *loadmesh(float triarr[][3][3], int n_tri)
{
    //*n_tri = sizeof(*triarr) / sizeof(*triarr[0]);
    triangle_t *mesh = malloc(n_tri * sizeof(triangle_t));

    for (int i = 0; i < n_tri; i++)
    {
        mesh[i].p1.x = triarr[i][0][0];
        mesh[i].p1.y = triarr[i][0][1];
        mesh[i].p1.z = triarr[i][0][2];

        mesh[i].p2.x = triarr[i][1][0];
        mesh[i].p2.y = triarr[i][1][1];
        mesh[i].p2.z = triarr[i][1][2];

        mesh[i].p3.x = triarr[i][2][0];
        mesh[i].p3.y = triarr[i][2][1];
        mesh[i].p3.z = triarr[i][2][2];
    }
    return mesh;
}

void draw_triangle(triangle_t *tri, p3_t *origin, p3_t *rot, p3_t *scale)
{
    p3_t p3_1;
    p3_t p3_2;
    p3_t p3_3;

    p3_1.x =
        (tri->p1.x * (cos(rot->y) * cos(rot->z))) +
        (tri->p1.y * (cos(rot->y) * sin(rot->z))) -
        (tri->p1.z * (sin(rot->y)));
    p3_1.y =
        -(tri->p1.x * ((sin(rot->x) * sin(rot->y) * cos(rot->z)) + (cos(rot->x) * sin(rot->z)))) -
        (tri->p1.y * ((sin(rot->x) * sin(rot->y) * sin(rot->z)) - (cos(rot->x) * cos(rot->z)))) -
        (tri->p1.z * (sin(rot->x) * cos(rot->y)));
    p3_1.z =
        (tri->p1.x * ((cos(rot->x) * sin(rot->y) * cos(rot->z)) - (sin(rot->x) * sin(rot->z)))) +
        (tri->p1.y * ((cos(rot->x) * sin(rot->y) * sin(rot->z)) + (sin(rot->x) * cos(rot->z)))) +
        (tri->p1.z * (cos(rot->x) * cos(rot->y)));

    p3_2.x =
        (tri->p2.x * (cos(rot->y) * cos(rot->z))) +
        (tri->p2.y * (cos(rot->y) * sin(rot->z))) -
        (tri->p2.z * (sin(rot->y)));
    p3_2.y =
        -(tri->p2.x * ((sin(rot->x) * sin(rot->y) * cos(rot->z)) + (cos(rot->x) * sin(rot->z)))) -
        (tri->p2.y * ((sin(rot->x) * sin(rot->y) * sin(rot->z)) - (cos(rot->x) * cos(rot->z)))) -
        (tri->p2.z * (sin(rot->x) * cos(rot->y)));
    p3_2.z =
        (tri->p2.x * ((cos(rot->x) * sin(rot->y) * cos(rot->z)) - (sin(rot->x) * sin(rot->z)))) +
        (tri->p2.y * ((cos(rot->x) * sin(rot->y) * sin(rot->z)) + (sin(rot->x) * cos(rot->z)))) +
        (tri->p2.z * (cos(rot->x) * cos(rot->y)));

    p3_3.x =
        (tri->p3.x * (cos(rot->y) * cos(rot->z))) +
        (tri->p3.y * (cos(rot->y) * sin(rot->z))) -
        (tri->p3.z * (sin(rot->y)));
    p3_3.y =
        -(tri->p3.x * ((sin(rot->x) * sin(rot->y) * cos(rot->z)) + (cos(rot->x) * sin(rot->z)))) -
        (tri->p3.y * ((sin(rot->x) * sin(rot->y) * sin(rot->z)) - (cos(rot->x) * cos(rot->z)))) -
        (tri->p3.z * (sin(rot->x) * cos(rot->y)));
    p3_3.z =
        (tri->p3.x * ((cos(rot->x) * sin(rot->y) * cos(rot->z)) - (sin(rot->x) * sin(rot->z)))) +
        (tri->p3.y * ((cos(rot->x) * sin(rot->y) * sin(rot->z)) + (sin(rot->x) * cos(rot->z)))) +
        (tri->p3.z * (cos(rot->x) * cos(rot->y)));

    p2_t p2_1;
    p2_1.y2 = (((p3_1.y * scale->y) + origin->y) * view_dist / ((p3_1.z * scale->z) + origin->z)) + y_offset;
    p2_1.x2 = 0 - (((p3_1.x * scale->x) + origin->x) * view_dist / ((p3_1.z * scale->z) + origin->z)) + x_offset;

    p2_t p2_2;
    p2_2.y2 = (((p3_2.y * scale->y) + origin->y) * view_dist / ((p3_2.z * scale->z) + origin->z)) + y_offset;
    p2_2.x2 = 0 - (((p3_2.x * scale->x) + origin->x) * view_dist / ((p3_2.z * scale->z) + origin->z)) + x_offset;

    p2_t p2_3;
    p2_3.y2 = (((p3_3.y * scale->y) + origin->y) * view_dist / ((p3_3.z * scale->z) + origin->z)) + y_offset;
    p2_3.x2 = 0 - (((p3_3.x * scale->x) + origin->x) * view_dist / ((p3_3.z * scale->z) + origin->z)) + x_offset;

    gfx_FillTriangle((int)p2_1.x2, (int)p2_1.y2, (int)p2_2.x2, (int)p2_2.y2, (int)p2_3.x2, (int)p2_3.y2);
}

void draw_mesh(triangle_t *mesh, p3_t *origin, int n_tri, p3_t *rot, p3_t *scale)
{
    for (int i = 0; i < n_tri; i++)
    {
        draw_triangle(&(mesh[i]), origin, rot, scale);
    }
}

p3_t genp3(float x, float y, float z)
{
    p3_t p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}