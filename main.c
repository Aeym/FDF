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

int main(int ac, char **av)
{
	m_struct	m;
	g_struct	g;
	p_struct 	p;
	int			**tab_int;
	int tmp2;

	g.esp = ESP;
	if (ac != 2 || (tab_int = check_entry(av[1], &p)) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, 2400, 1350, "FDF");
	m.img = mlx_new_image(m.mlx, 2400, 1350);
	g.gda = mlx_get_data_addr(m.img, &g.bpp, &g.size_line, &g.end);
	printf("line_size ret de gda : %d\n", g.size_line);
	printf("line size : %d\n", p.line_size);
	

	//global_seg(10, 10, 10, 500, g);
	//put_tab_to_image(g, tab_int, p.line_size);
	draw_seg(tab_int, p.line_size, g);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	mlx_key_hook(m.win, esc_key, m.mlx);
	mlx_loop(m.mlx);	
	return (0);
}
