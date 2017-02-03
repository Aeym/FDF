/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:02:26 by ealrick           #+#    #+#             */
/*   Updated: 2017/01/27 15:52:14 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main()
{
	void *mlx;
	void *win;
	void *img;
	char *gda;
	int	bpp;
	int size_line;
	int end;
	int x;
	int y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "test");
	img = mlx_new_image(mlx, 400, 400);
	gda = mlx_get_data_addr(img, &bpp, &size_line, &end);
	x = 150;
	while (x < 250)
	{
		y = 150;
		while (y < 250)
		{
			*(unsigned*)(gda + (x * size_line + y * bpp / 8)) = 0x00FF0000;
			y++;
		}
		x++;
	}
	*(unsigned*)(gda + (100 * size_line + 100 * bpp / 8)) = 0x00FFFFFF;
	*(unsigned*)(gda + (100 * size_line + 101 * bpp / 8)) = 0x00FFFFFF;
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}
