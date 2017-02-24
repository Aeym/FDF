#include "fdf.h"

void swap_se(se_struct *s)
{
	int a;
	
	a = s->x1;
	s->x1 = s->x2;
	s->x2 = a;
	a = s->y1;
	s->y1 = s->y2;
	s->y2 = a;
}


int ft_abs(int x)
{
	return ((x < 0) ? -x : x);
}

void trace_line(g_struct g, c_struct c)
{
	int color;

	if (c.z < -5)
		color = 0x00333333;
	if (c.z < 0 && c.z >= -5)
		color = 0x00B8B7C8;
	if (c.z == 0)
		color = 0x00221F50;
	if (c.z < 3 && c.z > 0)
		color = 0x00025F22;
	if (c.z < 5 && c.z >= 3)
		color = 0x00097E31;
	if (c.z >= 5 && c.z <= 20)
		color = 0x0010903C;
	if (c.z > 20 && c.z < 40)
		color = 0x00B3C62C;
	if (c.z >= 40 && c.z < 50)
		color = 0x00A76E0F;
	if (c.z >= 50)
		color = 0x005E4315;
	if ((c.x + g.posx) < 1350 && (c.y + g.posy) < 2400 && 
		(c.x + g.posx) > 0 && (c.y + g.posy) > 0)
		*(unsigned*)(g.gda + (c.x + g.posx) * g.size_line +
		 (c.y + g.posy) * g.bpp / 8) = color;
}

void 	fill_se(se_struct *s, c_struct c1, c_struct c2)
{
	s->x1 = c1.x;
	s->y1 = c1.y;
	s->x2 = c2.x;
	s->y2 = c2.y;
}

int 	hook_key(int key, g_struct *g)
{
	if (key == 46)
		g->deep *= 1.5;
	if (key == 37)
		g->deep /= 1.5;
	if (key == 33)
		g->a += 4 * 3.14 / 180;
	if (key == 30)
		g->a -= 4 * 3.14 / 180;
	if (key == 69)
		g->esp++;
	if (key == 78 && g->esp > 0)
		g->esp--;
	if (key == 53)
		exit (EXIT_SUCCESS);
	if (key == 126)
		g->posx -= 50;;
	if (key == 125)
		g->posx += 50;
	if (key == 124)
		g->posy += 50;
	if (key == 123)
		g->posy -= 50;
	mlx_destroy_image(g->mlx, g->img);
	init_prog(g);
	return (0);
}