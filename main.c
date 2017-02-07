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
	p_struct 	p;

	if ((tab_int = check_entry(g->av1, &p)) == NULL)
		return (1);
	if (!(g->esp))
		g->esp = 2400 / (p.line_size * 2);
	if (!(g->posx))
	{
		g->posx = 1350 / 2.0 - g->esp * p.nbl / 2;
		g->posy = 2400 / 2.0 - g->esp * p.line_size / 2;
	}
	g->img = mlx_new_image(g->mlx, 2400, 1350);
	g->gda = mlx_get_data_addr(g->img, &g->bpp, &g->size_line, &g->end);
	draw_seg(tab_int, p.line_size, *g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (0);
}

// int 	key_hook(int key, g_struct *g)
// {
// 	printf("key :%d\n", key);
// 	if (key == 69)
// 		g->esp++;
// 	if (key == 78)
// 		g->esp--;
// 	if (key == 53)
// 		exit (EXIT_SUCCESS);
// 	if (key == 126)
// 		g->posx -= 10;;
// 	if (key == 125)
// 		g->posx += 10;
// 	if (key == 124)
// 		g->posy += 10;
// 	if (key == 123)
// 		g->posy -= 10;

// 	mlx_destroy_image(g->mlx, g->img);
// 	init_prog(g);
// 	return (0);
// }

int 	hook_key(int key, g_struct *g)
{
	printf("key :%d\n", key);
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

int main(int ac, char **av)
{
	g_struct	g;

	// g.esp = ESP;
	g.av1 = av[1];
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 2400, 1350, "FDF");
	if (ac != 2 || (init_prog(&g) == 1))
	{
		ft_putstr("error\n");
		return (0);
	}
	// m.img = mlx_new_image(m.mlx, 2400, 1350);
	// g.gda = mlx_get_data_addr(m.img, &g.bpp, &g.size_line, &g.end);
	//draw_seg(tab_int, p.line_size, g);
	//mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	
	//mlx_key_hook(g.win, key_hook, &g);
	mlx_hook(g.win, KeyPress, KeyPressMask, hook_key, &g);
	//mlx_do_key_autorepeaton(g.mlx);
	// mlx_key_hook(g.win, esc_key, &g);
	//mlx_key_hook(m.win, trans_key, &g);
	mlx_loop(g.mlx);
	return (0);
}