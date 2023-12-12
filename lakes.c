#include <stdio.h>
void Lake(char **map, int i, int j, int w, int h)
{
    if (i < 0 || j < 0)
        return;
    if (j >= h || i >= w)
        return;
    if (map[j][i] == '#' || map[j][i] == '4')
        return;
    map[j][i] = '4';
    Lake(map, i, j - 1, w, h);
    Lake(map, i, j + 1, w, h);
    Lake(map, i - 1, j, w, h);
    Lake(map, i + 1, j, w, h);
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
            Lake(map, i, j, width, height);
            comp++;
            i++;
        }
    }
    return comp;
}
