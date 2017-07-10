/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:11:24 by ealrick           #+#    #+#             */
/*   Updated: 2017/06/21 16:49:00 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_prog(t_gda *g)
{
	int		**tab_int;
	t_coo	c;
	t_pars	p;

	c.x = 0;
	c.y = 0;
	c.z = 0;
	if ((tab_int = check_entry(g->av1, &p)) == NULL)
		return (1);
	if (g->esp == 0)
		g->esp = WIND_Y / (p.line_size * 2.0);
	if (!(g->posx))
	{
		g->posx = WIND_Y / 2.0 - g->esp * p.nbl / 2;
		g->posy = WIND_X / 2.0 - g->esp * p.line_size / 2;
	}
	g->img = mlx_new_image(g->mlx, WIND_X, WIND_Y);
	g->gda = mlx_get_data_addr(g->img, &g->bpp, &g->size_line, &g->end);
	draw_seg1(tab_int, p.line_size, *g, c);
	draw_seg2(tab_int, p.line_size, *g, c);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (0);
}

void	key_help(int key, t_gda *g)
{
	if (key == 6)
		g->c -= 5;
	if (key == 7)
		g->c += 5;
	if (key == 46)
		g->deep *= 1.5;
	if (key == 37)
		g->deep /= 1.5;
}

int		hook_key(int key, t_gda *g)
{
	key_help(key, g);
	if (key == 33)
		g->a += 4 * 3.14 / 180;
	if (key == 30)
		g->a -= 4 * 3.14 / 180;
	if (key == 69)
		g->esp++;
	if (key == 78 && g->esp > 0)
		g->esp--;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 126)
		g->posx -= 50;
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

int		main(int ac, char **av)
{
	t_gda	g;

	g.deep = 0.009;
	g.esp = 0;
	g.a = 160;
	g.c = 0;
	if (ac != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	g.av1 = av[1];
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, WIND_X, WIND_Y, ft_strjoin("FDF : ", av[1]));
	if (init_prog(&g) == 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	mlx_hook(g.win, KEYPRESS, KEYPRESSMASK, hook_key, &g);
	mlx_loop(g.mlx);
	return (0);
}
