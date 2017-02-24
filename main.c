/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:11:24 by ealrick           #+#    #+#             */
/*   Updated: 2017/01/27 19:58:54 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int init_prog(g_struct *g)
{
	int			**tab_int;
	c_struct	c;
	p_struct 	p;

	c.x = 0;
	c.y = 0;
	c.z = 0;
	if ((tab_int = check_entry(g->av1, &p)) == NULL)
		return (1);
	if (g->esp == 0)
		g->esp = 2400.0 / (p.line_size * 2);
	if (!(g->posx))
	{
		g->posx = 1350 / 2.0 - g->esp * p.nbl / 2;
		g->posy = 2400 / 2.0 - g->esp * p.line_size / 2;
	}
	g->img = mlx_new_image(g->mlx, 2400, 1350);
	g->gda = mlx_get_data_addr(g->img, &g->bpp, &g->size_line, &g->end);
	draw_seg1(tab_int, p.line_size, *g, c);
	draw_seg2(tab_int, p.line_size, *g, c);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (0);
}

int main(int ac, char **av)
{
	g_struct	g;

	g.deep = 0.009;
	g.esp = 0;
	g.a = 160;
	g.av1 = av[1];
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 2400, 1350, ft_strjoin("FDF : ", av[1]));
	if (ac != 2 || (init_prog(&g) == 1))
	{
		ft_putstr("error\n");
		return (0);
	}
	mlx_hook(g.win, KeyPress, KeyPressMask, hook_key, &g);
	mlx_loop(g.mlx);
	return (0);
}