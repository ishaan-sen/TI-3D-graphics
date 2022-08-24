#include <graphx.h>
#include <math.h>

#define x_offset (GFX_LCD_WIDTH / 2)
#define y_offset (GFX_LCD_HEIGHT / 2)

#define view_dist 7

#define TO_RAD (M_PI / 180)

typedef struct p3_t // basic 3-D point type
{
    float x;
    float y;
    float z;
} p3_t;

typedef struct p2_t // basic 3-D point type
{
    float x2;
    float y2;
} p2_t;

typedef struct triangle_t // Triangle with three points. These are projected onto the screen and drawn by the gfx_fillTriangle() function in graphx.h
{
    p3_t p1;
    p3_t p2;
    p3_t p3;

    // uint16_t color;
    // vec3_t normal;
} triangle_t;

triangle_t *loadmesh(float triarr[][3][3], int n_tri);
//loads a triangle array (mesh) from an array

void draw_triangle(triangle_t *tri, p3_t *origin, p3_t *rot, p3_t *scale);

void draw_mesh(triangle_t *mesh, p3_t *origin, int n_tri, p3_t *rot, p3_t *scale);

p3_t genp3(float x, float y, float z);
