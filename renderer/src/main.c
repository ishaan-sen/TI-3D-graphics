#include "3d-gfx.h"
#include "asset/wolf.mesh" // include the actual mesh data file
#include <ti/getcsc.h>


int main(void)
{
    gfx_Begin();
    gfx_SetDrawBuffer();
    int n_tri = 128; // you need to set this manually for each different mesh. 
    // Feel free to fix it; some semi-functioning code to do this exists in a comment (3d-gfx.c). 
    triangle_t *mesh = loadmesh(triarr, n_tri);
    p3_t scale = genp3(1, 1, 1);
    p3_t origin = genp3(0, 0, 4); // p3_t is used for vectors, scaling, and rotations as well as point definitions. 
    p3_t rotation;

    gfx_FillScreen(0xE9);
    rotation = genp3(0, 0, M_PI);
    draw_mesh(mesh, &origin, n_tri, &rotation, &scale);

    gfx_BlitBuffer();
    while (!os_GetCSC());
    gfx_End();
    return 0;
}
