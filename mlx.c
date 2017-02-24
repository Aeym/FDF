#include "fdf.h"

int **create_tab(int nbl, int line_size)
{
	int i;
	int **tab;
	int *tab2;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * (nbl + 1))))
		return (NULL);
	if (!(tab2 = (int *)malloc((sizeof(int) * line_size * nbl ))))
			return (NULL);
	while (i < nbl)
	{
		tab[i] = &tab2[i * line_size];
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int **fill_tab(p_struct *p, char *file, int **tab)
{
	int i;
	int j;

	p->zmax = 0;
	p->fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(p->fd, &p->line) && i < p->nbl)
	{
		p->line_split = ft_strsplit(p->line, ' ');
		j = 0;
		while (j < p->line_size)
		{
			tab[i][j] = ft_atoi(p->line_split[j]);
			if (ft_abs(tab[i][j]) > p->zmax)
				p->zmax = ft_abs(tab[i][j]);	
			j++;
		}
		i++;
	}
	return (prop_tab(p, tab));
}

int **prop_tab(p_struct *p, int **tab)
{
	float c;
	int i;
	int j;

	i = 0;
	c = p->zmax / 100.0;

		while (i < p->nbl)
		{
			j = 0;
			while (j < p->line_size)
			{
					tab[i][j] /= c;
				j++;
			}
			i++;
		}
	return (tab);
}

int check_line_size(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int **check_entry(char *file, p_struct *p)
{
	int tmp;
	
	p->fd = open(file, O_RDONLY);
	tmp = 0;
	p->nbl = 0;
	while (get_next_line(p->fd, &p->line) > 0)
	{
		p->line_split = ft_strsplit(p->line, ' ');
		p->line_size = check_line_size(p->line_split);
		if (tmp == 0)
			tmp = p->line_size;
		if (tmp != p->line_size)
			return (NULL);
		p->nbl++;
	}
	close(p->fd);
	return (fill_tab(p, file, create_tab(p->nbl, p->line_size)));
}