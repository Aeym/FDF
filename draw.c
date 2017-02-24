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

void	draw_seg1(int **tab, int line_size, g_struct g, c_struct c)
{
	c_struct c2;
	c_struct c3;
	se_struct s;

	c.x = -1;
	while (tab[++c.x] != NULL)
	{
		c.y = -1;
		while (++c.y < line_size)
		{
			c.z = tab[c.x][c.y];
			c2 = rot(proj_para(c, g), g);
			if ((c.y + 1) < line_size)
			{
				c3.x = c.x;
				c3.y = c.y + 1;
				c3.z = tab[c3.x][c3.y];
				if (ft_abs(c3.z) > ft_abs(c.z))
				 	c.z = c3.z;
				c3 = rot(proj_para(c3, g), g);
				fill_se(&s, c2, c3);
				global_seg(s, c, g);
			}
		}
	}
}

void	draw_seg2(int **tab, int line_size, g_struct g, c_struct c)
{
	c_struct c2;
	c_struct c3;
	se_struct s;

	c.x = -1;
	while (tab[++c.x] != NULL)
	{
		c.y = -1;
		while (++c.y < line_size)
		{
			c.z = tab[c.x][c.y];
			c2 = rot(proj_para(c, g), g);
			if (tab[c.x + 1] != NULL)
			{
				c3.x = c.x + 1;
				c3.y = c.y;
				c3.z = tab[c3.x][c3.y];
				if (ft_abs(c3.z) > ft_abs(c.z))
					c.z = c3.z;
				c3 = rot(proj_para(c3, g), g);
				fill_se(&s, c2, c3);
				global_seg(s, c, g);
			}
		}
	}
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
	while (c.y <= s.y2 && dy != 0)
	{
		c.x = s.x1 + dx * (c.y - s.y1) / dy;
		trace_line(g, c);
		c.y++;
	}
}