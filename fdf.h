/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:17:46 by ealrick           #+#    #+#             */
/*   Updated: 2017/02/01 15:28:42 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# define ESP 10

typedef struct	mlx_struct
{
	void *mlx;
	void *win;
	void *img;
}				m_struct;

typedef struct  gda_struct
{
	char *gda;
	int bpp;
	int size_line;
	int end;
	int esp;
}				g_struct;

typedef struct pars_struct
{
	int fd;
	int nbl;
	int line_size;
	char *line;
	char **line_split;
}				p_struct;

typedef struct co_struct
{
	int x;
	int y;
	int z;
}				c_struct;

typedef struct seg_struct
{
	int x1;
	int y1;
	int x2;
	int y2;
}				se_struct;

int		esc_key(int key, void *mlx);
void    put_tab_to_image(g_struct g, int **tab, int line_size);
int		**create_tab(int nbl, int line_size);
int		**fill_tab(p_struct p, char *file, int **tab);
int		check_line_size(char **tab);
int		**check_entry(char *file, p_struct *p);
void	draw_seg(int **tab, int line_size, g_struct g);
void test_segv(se_struct s, c_struct c, g_struct g);
void test_segh(se_struct s, c_struct c, g_struct g);
void global_seg(se_struct s, c_struct c, g_struct g);

#endif
