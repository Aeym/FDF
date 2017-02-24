#include "fdf.h"

c_struct rot(c_struct c, g_struct g)
{
	return(rot_x(rot_y(rot_z(c, g), g), g));
}

c_struct rot_x(c_struct c, g_struct g)
{
	float y;
	float z;

	y = (c.y) * cos(g.a) + (c.z) * sin(g.a);
	z = c.z * cos(g.a) - c.y * sin(g.a);
	c.y = y;
	c.z = z;
	return (c);
}

c_struct	rot_z(c_struct c, g_struct g)
{
	float x;
	float y;

	x = (c.x) * cos(g.a) - (c.y) * sin(g.a);
	y = (c.x) * sin(g.a) + (c.y) * cos(g.a);
	c.x = x;
	c.y = y;
	return (c);
}

c_struct	rot_y(c_struct c, g_struct g)
{
	float x;
	float z;

	
	x = (c.x) * cos(g.a) - c.z* sin(g.a);
	z = c.x * sin(g.a) +  c.z* cos(g.a);
	
	c.x = x;
	c.z = z;
	return (c);
}

c_struct 	proj_para(c_struct c, g_struct g)
{
	float x;
	float y;
	
		x = c.x - g.deep * c.z;
		y = c.y - g.deep / 2 * c.z;
	
	c.x = x * g.esp;
	c.y = y * g.esp;
	return (c);
}
