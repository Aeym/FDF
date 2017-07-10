/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:04:07 by ealrick           #+#    #+#             */
/*   Updated: 2017/02/26 17:06:16 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coo		rot(t_coo c, t_gda g)
{
	return (rot_x(rot_y(rot_z(c, g), g), g));
}

t_coo		rot_x(t_coo c, t_gda g)
{
	float	y;
	float	z;

	y = (c.y) * cos(g.a) + (c.z) * sin(g.a);
	z = c.z * cos(g.a) - c.y * sin(g.a);
	c.y = y;
	c.z = z;
	return (c);
}

t_coo		rot_z(t_coo c, t_gda g)
{
	float	x;
	float	y;

	x = (c.x) * cos(g.a) - (c.y) * sin(g.a);
	y = (c.x) * sin(g.a) + (c.y) * cos(g.a);
	c.x = x;
	c.y = y;
	return (c);
}

t_coo		rot_y(t_coo c, t_gda g)
{
	float	x;
	float	z;

	x = c.x * cos(g.a) - c.z * sin(g.a);
	z = c.x * sin(g.a) + c.z * cos(g.a);
	c.x = x;
	c.z = z;
	return (c);
}

t_coo		proj_para(t_coo c, t_gda g)
{
	float	x;
	float	y;

	x = c.x - g.deep * c.z;
	y = c.y - g.deep / 2 * c.z;
	c.x = x * g.esp;
	c.y = y * g.esp;
	return (c);
}
