#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SetLoc;
// step 4
char turn(char c)
{
    char *set = "URDL";
    if (c == 'L')
    {
        if(set[SetLoc] == 'U')
        {
            SetLoc = 3;
        }
        else
        {
            SetLoc --;
        }
        return set[SetLoc];
    }
    else if (c == 'R')
    {
        if(set[SetLoc] == 'L')
        {
            SetLoc = 0;
        }
        else
        {
            SetLoc ++;
        }
        return set[SetLoc];
    }
    return 0;
}
//step 3
void advance(char pos, int *coord)
{
    switch (pos)
    {
        case 'U':
            coord[1]-= 1;
            break;
        case 'D':
            coord[1]+= 1;
            break;            
        case 'L':
            coord[0]-= 1;
            break;       
        case 'R':
            coord[0]+= 1;
            break;       
        default:
            break;            
    }
}
//step 2
char* my_spaceship(char* s)
{
    char *res = malloc(sizeof(char) * 150);
    char *dir = malloc(sizeof(int)*20);

    int *coor = malloc(sizeof(int) * 2);
    memset(coor, 0, sizeof(int) * 2);
    char pos = 'U';
    int i= 0;
    for (i = 0; s[i]; i++ )
    {
        if ( s[i] == 'A')
        {
            advance(pos, coor);
        }
        else
        {
            pos = turn(s[i]);
        }
    }
    switch (pos)
    {
        case 'U':
            dir = "up";
            break;
        case 'D':
            dir = "down";
            break;            
        case 'L':
            dir = "left";
            break;       
        case 'R':
            dir = "right";
            break;    
    }
    int x = coor[0];
    int y = coor[1];
    sprintf(res, "{x: %d, y: %d, direction: '%s'}", x, y, dir);

    return res;
}


int main()
{
    printf("%s\n",my_spaceship("RAARA"));
    return 0;

}
