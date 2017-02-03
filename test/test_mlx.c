#include <mlx.h>
#include <math.h>

int main()
{
	void *mlx;
	void *win;
	int x;
	int y;
	
	x = 150;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx test");
	while (x < 200)
	{
		y = 150;
		while (y < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	x = 170;
	while (x < 180)
	{
		y = 200;
		while (y < 215)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	x = 140;
	while (x < 210)
	{
		y = 215;
		while (y < 315)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	x = 140;
	while (x < 155)
	{
		y = 315;
		while (y < 400)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	x = 195;
	while (x < 210)
	{
		y = 315;
		while (y < 400)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	x = 100;
	while (x < 140)
	{
		y = 215;
		while (y < 235)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	x = 210;
	while (x < 250)
	{
		y = 215;
		while (y < 235)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	x = 10;
	while (x < 100)
	{
		mlx_pixel_put(mlx, win, x, 10 + ((100 - 10) * (x - 10))/(100 - 10), 0x00FF00FF);
		x++;
	}
	int a = 0;
	while (a <= 360)
	{
		mlx_pixel_put(mlx, win, 300 + 50 * cos(a), 300 + 50 * sin(a), 0x0000FFFF);
		a++;
	}
	int x0 = 300;
	int y0 = 300;
	x = 250;
	y = 250;
	while (x < 350)
	{
		y = 250;
		if (x == 300)
			x++;
		while (y < 350)
		{
			if (y == 300)
				y++;
			mlx_pixel_put(mlx, win, (50 * 50) /((y - y0) * (y - y0)) + x0, (50 * 50)/((x - x0) * (x - x0)) + y0, 0x00FF0000);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
