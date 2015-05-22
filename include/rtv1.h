/*
** rtv1.h for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1/include
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon Feb  2 13:30:33 2015 hugo walbecq
** Last update Thu May  7 11:46:05 2015 walbec_h
*/

#ifndef		RTV_H
# define	RTV_H

# define	ABS(value)	((value) < 0 ? - (value) : (value))
# define	RAD(a)		(a * M_PI / 180)
# define	TAN(x)		(pow(tan(RAD(x)), 2))
# define	WIN_X		(800)
# define	WIN_Y		(800)
# define	D		(100)
# define	AMBIANCE	(0.2)
# define	REFLEX		(0.8)
# define	BRILL		(0)
# define	CONE		(0xFEED01)
# define	PLAN		(0x00FF00)
# define	SPHERE		(0xFF0000)
# define	CYLINDR		(0x0000FF)

typedef struct	s_color
{
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;
  unsigned char	a;
}		t_color;

typedef union	s_union
{
  int		color;
  t_color	rgb;
}		t_union;

typedef struct	s_obj
{
  int		**tab;
  /* int		*reflex; */
  /* int		*trans; */
  /* int		*brill; */
  int		here;
}		t_obj;

typedef struct	s_coord
{
  double	xo;
  double	yo;
  double	zo;
  double	vx;
  double	vy;
  double	vz;
  double	k;
  double	p[3];
}		t_coord;

typedef struct	s_rtv
{
  t_coord	coord;
  t_obj		sph;
  t_obj		plan;
  t_obj		cone;
  t_obj		cyl;
  t_obj		spot;
  int		flag;
  int		obj;
  int		aliasing;
  unsigned int	color;
  int		bpp;
  int		size_line;
  int		endian;
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  unsigned char	*data;
}		t_rtv;

void		init_image(t_rtv *, int, int);
void		my_lady(t_rtv *, t_coord *);
void		my_reflexion(t_rtv *, int);
int		my_pixel_put_to_image(t_rtv *, int, int);
int		check_place(t_rtv *);
int		my_calc(t_rtv *);
void		rotate_x(double *, double *, int);
void		rotate_y(double *, double *, int);
void		rotate_z(double *, double *, int);
void		delta_sphe(t_rtv *, double, double, int);
void		delta_cone(t_rtv *, double, double, int);
void		delta_cyl(t_rtv *, double, double, int);
void		inter_obj(t_rtv *);
void		inter_sphe(t_coord *, t_rtv *, int);
void		inter_cyl(t_coord *, t_rtv *, int);
void		inter_plan(t_coord *, t_rtv *, int);
void		inter_cone(t_coord *, t_rtv *, int);
void		my_rotate(t_coord *, int, int, int);
void		rotate(t_coord *, int, int, int);
void		translat(t_coord *, int, int, int);
void		my_light(t_rtv *, t_coord *);
void		check_obj(t_rtv *, t_coord *, double *);
void		my_shadow(t_coord *, t_rtv *);
void		my_aliasing(int, int, t_rtv *);
char		*find_number(char *, int);
int		check_arg_obj(char *);
int		check_buff(char *);
int		my_average(int *, int);
int		gere_key(int, t_rtv *);
int		gere_expose(t_rtv *);

#endif		/* !RTV_H */
