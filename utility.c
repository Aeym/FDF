/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:00:33 by ealrick           #+#    #+#             */
/*   Updated: 2017/02/26 17:03:42 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_se(t_seg *s)
{
	int a;

	a = s->x1;
	s->x1 = s->x2;
	s->x2 = a;
	a = s->y1;
	s->y1 = s->y2;
	s->y2 = a;
}

int		ft_abs(int x)
{
	return ((x < 0) ? -x : x);
}

void	trace_line(t_gda g, t_coo c)
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
	if ((c.x + g.posx) < WIND_Y && (c.y + g.posy) < WIND_X &&
		(c.x + g.posx) > 0 && (c.y + g.posy) > 0)
		*(unsigned*)(g.gda + (c.x + g.posx) * g.size_line +
		(c.y + g.posy) * g.bpp / 8) = color + g.c;
}

void	fill_se(t_seg *s, t_coo c1, t_coo c2)
{
	s->x1 = c1.x;
	s->y1 = c1.y;
	s->x2 = c2.x;
	s->y2 = c2.y;
}
