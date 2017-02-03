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

void trace_pixel(g_struct g, c_struct c)
{
	int color;

	if (c.z < 3)
		color = 0x00FF6600;
	if (c.z < 5 && c.z >= 3)
		color = 0x00FFFFFF;
	if (c.z >= 5 && c.z < 10)
		color = 0x00FF0000;
	if (c.z >= 10)
		color = 0x00FFFF00;
	*(unsigned*)(g.gda + (c.x + 20) * 4 * g.size_line + (c.y + 20) * 4 * g.bpp / 8) = color;
}

c_struct	proj_3d(c_struct c);

void	put_tab_to_image(g_struct g, int **tab, int line_size, int esp)
{
	c_struct c;
	c_struct c2;
	int k;

	c.x = 0;
	printf("bpp : %d\n", g.bpp);
	while (tab[c.x] != NULL)
	{
		c.y = 0;
		while (c.y < line_size)
		{
			c.z = tab[c.x][c.y];
			c2 = proj_3d(c);
			trace_pixel(g, c2);
			c.y++;
			
//			k = ((i - 1) * 20);
//			while (k < (i * 20))   //    a revoir colorie les faces ??
//				{
//					*(unsigned*)(gda + k * size_line + ((j - 1) + ((j - (j - 1))*(k - ((i - 1) * 20)) / ((i * 20) - ((i - 1) * 20)))) * bpp / 8) = 0x00FFFFFF;
//					k++;
//				}
			
		}
		c.x++;
	}
}

c_struct 	proj_3d(c_struct c)
{
	float p;
	if (c.z != 0)
	{
		c.x += c.z;
		p = 0.5 * c.z;
		c.y += p;
		printf("y = %d\n", c.y);
	}
	return (c);
}

void	draw_seg(int **tab, int esp, int line_size, g_struct g)
{
	c_struct c;
	se_struct s;

	c.x = 0;
	while (tab[c.x] != NULL)
	{
		c.y = 0;
		while (c.y < line_size)
		{
			if ((c.y + 1) < line_size)
			{
				c.z = tab[c.x][c.y];
				s.x1 = c.x * esp;
				s.y1 = c.y * esp;
				s.x2 = c.x * esp;
				c.x = s.x1;
				c.y = s.y1;
				s.y2 = (c.y + 1) * esp;
				
				draw_segh(g, s, c);
			}
			if (tab[c.x + 1] != NULL)
			{
				s.x1 = c.x * esp;
				s.y1 = c.y * esp;
				s.x2 = (c.x + 1) * esp;
				s.y2 = c.y * esp;
				c.z = tab[c.x][c.y];
				draw_segv(g, s, c);
			}
			c.y++;
		}
		c.x++;
	}
}

void	draw_segh(g_struct g, se_struct s, c_struct c)
{
	int dx;
	int dy;

	dx = s.x2 - s.x1;
	dy = s.y2 - s.y1;
	if (dy > 0 && dx == 0)
	{
		while (s.y1 < s.y2)
		{
			c.x = s.x1;
			c.y = s.y1;
			trace_pixel(g, c);
			s.y1++;
		}
	}
}

void	draw_segv(g_struct g, se_struct s, c_struct c)
{
	int dx;
	int dy;

	dx = s.x2 - s.x1;
	dy = s.y2 - s.y1;
	if (dx > 0 && dy == 0)
	{
		while (s.x1 < s.x2)
		{
			c.x = s.x1;
			c.y = s.y1;
			c.z = 0;
			trace_pixel(g, c);
			s.x1++;
		}
	}
}