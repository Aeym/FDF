/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:17:46 by ealrick           #+#    #+#             */
/*   Updated: 2017/06/21 15:33:27 by ealrick          ###   ########.fr       */
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
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define WIND_X 2400
# define WIND_Y 1350

typedef struct	s_gda
{
	char		*av1;
	char		*gda;
	int			bpp;
	int			size_line;
	int			end;
	int			esp;
	float		deep;
	float		a;
	void		*mlx;
	void		*win;
	void		*img;
	int			posx;
	int			posy;
	int			c;
}				t_gda;

typedef struct	s_pars
{
	int			fd;
	int			nbl;
	int			line_size;
	char		*line;
	char		**line_split;
	int			zmax;
}				t_pars;

typedef struct	s_coo
{
	int			x;
	int			y;
	int			z;
}				t_coo;

typedef struct	s_seg
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			z1;
	int			z2;
}				t_seg;

int				init_prog(t_gda *g);
int				hook_key(int key, t_gda *g);
void			key_help(int key, t_gda *g);
void			trace_line(t_gda g, t_coo c);
void			fill_se(t_seg *s, t_coo c1, t_coo c2);
int				**create_tab(int nbl, int line_size);
int				**fill_tab(t_pars *p, char *file, int **tab);
int				**prop_tab(t_pars *p, int **tab);
int				check_line_size(char **tab);
int				**check_entry(char *file, t_pars *p);
void			draw_seg1(int **tab, int line_size, t_gda g, t_coo c);
void			draw_seg2(int **tab, int line_size, t_gda g, t_coo c);
void			test_segv(t_seg s, t_coo c, t_gda g);
void			test_segh(t_seg s, t_coo c, t_gda g);
void			global_seg(t_seg s, t_coo c, t_gda g);
t_coo			proj_para(t_coo c, t_gda g);
t_coo			proj_iso(t_coo c, t_gda g);
void			swap_se(t_seg *s);
int				ft_abs(int x);
t_coo			rot(t_coo c, t_gda g);
t_coo			rot_x(t_coo c, t_gda g);
t_coo			rot_y(t_coo c, t_gda g);
t_coo			rot_z(t_coo c, t_gda g);
int				prop(int c);

#endif
