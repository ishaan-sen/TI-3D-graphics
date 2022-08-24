import trimesh
from sys import argv

myobj = trimesh.load_mesh(argv[1], enable_post_processing=True, solid=True)

out = "float triarr[][3][3] = {\n"

for face in myobj.faces:
    out = out + "  {\n"
    for vertex in face:
        out = out + "    {"
        for i in myobj.vertices[vertex]:
            out = out + str(i) + ","
        out = out + "},\n"
    out = out + "  },\n"
out = out + "};\n"

print(out)