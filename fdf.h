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
# define KeyPress 	2
# define KeyPressMask	(1L<<0)

typedef struct  gda_struct
{
	char *av1;
	char *gda;
	int bpp;
	int size_line;
	int end;
	int esp;
	float deep;
	float a;
	void *mlx;
	void *win;
	void *img;
	int posx;
	int posy;
}				g_struct;

typedef struct pars_struct
{
	int fd;
	int nbl;
	int line_size;
	char *line;
	char **line_split;
	int zmax;
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
	int z1;
	int x2;
	int y2;
	int z2;
}				se_struct;

int 			init_prog(g_struct *g);
int 			hook_key(int key, g_struct *g);
void 			trace_line(g_struct g, c_struct c);
void 			fill_se(se_struct *s, c_struct c1, c_struct c2);
int				**create_tab(int nbl, int line_size);
int				**fill_tab(p_struct *p, char *file, int **tab);
int 			**prop_tab(p_struct *p, int **tab);
int				check_line_size(char **tab);
int				**check_entry(char *file, p_struct *p);
void			draw_seg1(int **tab, int line_size, g_struct g, c_struct c);
void			draw_seg2(int **tab, int line_size, g_struct g, c_struct c);
void			test_segv(se_struct s, c_struct c, g_struct g);
void			test_segh(se_struct s, c_struct c, g_struct g);
void			global_seg(se_struct s, c_struct c, g_struct g);
c_struct		proj_para(c_struct c, g_struct g);
c_struct		proj_iso(c_struct c, g_struct g);
void			swap_se(se_struct *s);
int				ft_abs(int x);
c_struct 		rot(c_struct c, g_struct g);
c_struct		rot_x(c_struct c, g_struct g);
c_struct		rot_y(c_struct c, g_struct g);
c_struct		rot_z(c_struct c, g_struct g);
int				prop(int c);

#endif
