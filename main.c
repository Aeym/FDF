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
	int 		esp;

	esp = 4;
	if (ac != 2 || (tab_int = check_entry(av[1], &p)) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, 1600, 900, "FDF");
	m.img = mlx_new_image(m.mlx, 1600, 900);
	g.gda = mlx_get_data_addr(m.img, &g.bpp, &g.size_line, &g.end);
	printf("line size : %d\n", p.line_size);
	put_tab_to_image(g, tab_int, p.line_size, esp);
	//draw_seg(tab_int, esp, p.line_size, g);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 160, 90);
	mlx_key_hook(m.win, esc_key, m.mlx);
	mlx_loop(m.mlx);	
	return (0);
}
