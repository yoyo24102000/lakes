#include <stdio.h>

typedef struct {
    char **map;
    int w;
    int h;
} LakeParams;

void Lake(LakeParams *params, int i, int j)
{
    if (i < 0 || j < 0)
        return;
    if (j >= params->h || i >= params->w)
        return;
    if (params->map[j][i] == '#' || params->map[j][i] == '4')
        return;
    params->map[j][i] = '4';
    Lake(params, i, j - 1);
    Lake(params, i, j + 1);
    Lake(params, i - 1, j);
    Lake(params, i + 1, j);
}

int lakes(char **map, int width, int height)
{
    int comp = 0;
    for (int j = 0; j < height; j++)
    {
        int i = 0;
        while (i < width)
        {
            if (map[j][i] != '.')
            {
                i++;
                continue;
            }
            LakeParams params = {map, width, height};
            Lake(&params, i, j);
            comp++;
            i++;
        }
    }
    return comp;
}
