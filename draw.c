/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:41:58 by ealrick           #+#    #+#             */
/*   Updated: 2017/01/28 16:35:04 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void trace_pixel(g_struct g, c_struct c)
// {
// 	int color;
// 	char *str;
// 	int tmp;

// 	if (c.z < 3)
// 		color = 0x00FF6600;
// 	if (c.z < 5 && c.z >= 3)
// 		color = 0x00FFFFFF;
// 	if (c.z >= 5 && c.z < 10)
// 		color = 0x00FF0000;
// 	if (c.z >= 10)
// 		color = 0x00FFFF00;
// 		*(unsigned*)(g.gda + (c.x) * g.esp * g.size_line + (c.y)* g.esp * g.bpp / 8) = color;
// }

int ft_abs(int x)
{
	return ((x < 0) ? -x : x);
}


void trace_line(g_struct g, c_struct c)
{
	int color;

	// if (!(g.posx))
	// {
	// 	g.posx = 1350 - ;
	// 	g.posy = 0;
	// }
	if (c.z <= -10)
		color = 0x00333333;
	if (c.z > -10 && c.z < -5)
		color = 0x005C5C5C;
	if (c.z < 0 && c.z >= -5)
		color = 0x00979797;
	if (c.z < 3 && c.z >= 0)
		color = 0x00ACACAC;
	if (c.z < 5 && c.z >= 3)
		color = 0x00669999;
	if (c.z >= 5 && c.z < 10)
		color = 0x00D5D5D5;
	if (c.z >= 10)
		color = 0x00FFFFFF;
	if ((c.x + g.posx) < 1350 && (c.y + g.posy) < 2400 && (c.x + g.posx) > 0 && (c.y + g.posy) > 0)
		*(unsigned*)(g.gda + (c.x + g.posx) * g.size_line + (c.y + g.posy) * g.bpp / 8) = color;
}

c_struct	proj_para(c_struct c);
c_struct	proj_iso(c_struct c);

// void	put_tab_to_image(g_struct g, int **tab, int line_size)
// {
// 	c_struct c;
// 	c_struct c2;

// 	int k;

// 	c.x = 0;
// 	printf("bpp : %d\n", g.bpp);
// 	while (tab[c.x] != NULL)
// 	{
// 		c.y = 0;
// 		while (c.y < line_size)
// 		{
// 			c.z = tab[c.x][c.y];
// 			c2 = proj_para(c);
// 			trace_pixel(g, c2);
// 			//c3 = proj_para(c.x, c.y + 1, tab[c.x][c.y + 1]);
// 			c.y++;
			
// //			k = ((i - 1) * 20);
// //			while (k < (i * 20))   //    a revoir colorie les faces ??
// //				{
// //					*(unsigned*)(gda + k * size_line + ((j - 1) + ((j - (j - 1))*(k - ((i - 1) * 20)) / ((i * 20) - ((i - 1) * 20)))) * bpp / 8) = 0x00FFFFFF;
// //					k++;
// //				}
			
// 		}
// 		c.x++;
// 	}
// }

c_struct 	proj_para(c_struct c)
{
	if (c.z != 0)
	{
		c.x += 0.5 *c.z;
		c.y += 0.25 * c.z;
	}
	return (c);
}

c_struct	proj_iso(c_struct c)
{
	if (c.z != 0)
	{
		c.x = c.x + (c.z * 1.0);
		c.y = c.y + 0.8 * (c.z * 1.0);
	}
	return (c);
}


void	draw_seg(int **tab, int line_size, g_struct g)
{
	c_struct c;
	c_struct c2;
	c_struct c3;
	c_struct c4;
	se_struct s;

	c.x = 0;
	while (tab[c.x] != NULL)
	{
		c.y = 0;
		while (c.y < line_size)
		{
			c.z = tab[c.x][c.y];
			c2 = proj_iso(c);
			s.x1 = c2.x * g.esp;
			s.y1 = c2.y * g.esp;
			if ((c.y + 1) < line_size)
			{
				c3.x = c.x;
				c3.y = c.y + 1;
				c3.z = tab[c3.x][c3.y];
				// if (ft_abs(c3.z) > ft_abs(c.z))
				// 	c.z = c3.z;
				s.z2 = c3.z;
				c4 = proj_iso(c3);
				s.x2 = c4.x * g.esp;
				s.y2 = c4.y * g.esp;
				
				global_seg(s, c, g);
			}
			if (tab[c.x + 1] != NULL)
			{
				c3.x = c.x + 1;
				c3.y = c.y;
				c3.z = tab[c3.x][c3.y];
				// if (ft_abs(c3.z) > ft_abs(c.z))
				// 	c.z = c3.z;
				s.z2 = c3.z;
				c4 = proj_iso(c3);
				s.x2 = c4.x * g.esp;
				s.y2 = c4.y * g.esp;
				global_seg(s, c, g);
			}
			c.y++;
		}
		c.x++;
	}
}

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

void global_seg(se_struct s, c_struct c, g_struct g)
{
	if (ft_abs(s.x2 - s.x1) >= ft_abs(s.y2 - s.y1))
	{
		if (s.x1 < s.x2)
			test_segv(s, c, g);
		else
		{
			swap_se(&s);
			test_segv(s, c, g);
		}
	}
	else
	{
		if (s.y1 < s.y2)
			test_segh(s, c, g);
		else
		{
			swap_se(&s);
			test_segh(s, c, g);
		}
	}
}

void test_segv(se_struct s, c_struct c, g_struct g)
{
	int dx;
	int dy;

	c.x = s.x1;
	dx = s.x2 - s.x1;
	dy = s.y2 - s.y1;
	while (c.x <= s.x2 && dx != 0)
	{
		c.y = s.y1 + dy * (c.x - s.x1) / dx;
		trace_line(g, c);
		c.x++;
	}
}

void	test_segh(se_struct s, c_struct c, g_struct g)
{
	int dx;
	int dy;


	c.y = s.y1;
	dx = s.x2 - s.x1;
	dy = s.y2 - s.y1;
	// printf("s.z2 : %d\nc.z%d\n", s.z2, c.z);
	// printf("dz = %d\n", dz);
	while (c.y <= s.y2 && dy != 0)
	{
		c.x = s.x1 + dx * (c.y - s.y1) / dy;
		trace_line(g, c);
		c.y++;
	}
}