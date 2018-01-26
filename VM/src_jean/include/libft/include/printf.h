/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:43:40 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/26 17:00:01 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

# define BUFF_SIZE_P 4096

# define RESET "\033[0m"
# define BLACK "\033[1;90m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define URED "\033[1;91m"
# define UGREEN "\033[1;92m"
# define UYELLOW "\033[1;93m"

typedef struct		s_spec
{
	char			*spc_conv;
	char			spc;
	int				undefined;
	int				tab_spec[13];
}					t_spec;

typedef struct		s_buff
{
	char			*sentence;
	int				len;
	int				count;
	int				check;
}					t_buff;

typedef struct		s_unicode
{
	unsigned char	octet;
	unsigned int	mask;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;
}					t_unicode;

typedef void		(*t_pft_flag)(t_spec*);
typedef void		(*t_pft_spec)(t_buff*, t_spec*, t_pft_flag*, va_list);

int					ft_printf(const char *restrict format, ...);
void				ft_inistruct(t_buff *buff, t_spec *spec);
void				ft_resetstruct(t_spec *spec);
void				ft_putinbuff(t_buff *buff, char *format, int indx_format);
void				ft_putspecinbuff(t_buff *buff, t_spec *spec);
int					ft_checkspec(t_spec *spec, char *format, int idx_frmt);
void				ft_spec(t_buff *buff, t_spec *spec, va_list ap);
void				ft_checkflags(t_spec *spec, t_pft_flag *tab_pft_flags);
void				ft_unicode(t_buff *buff, t_spec *spec, wchar_t result);
void				ft_spec_d(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap);
void				ft_spec_u(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap);
void				ft_spec_o(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap);
void				ft_spec_x(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap);
void				ft_spec_c(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap);
void				ft_spec_s(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap);
void				ft_spec_p(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap);
void				ft_spec_b(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap);
void				ft_prec_number(t_spec *spec);
void				ft_width_number(t_spec *spec);
void				ft_prec_string(t_spec *spec);
int					ft_prec_wchart(wchar_t uni);
void				ft_precandwidth(t_buff *b, t_spec *s, wchar_t *uni);
void				ft_width_string(t_buff *b, t_spec *s, int len_uni);
void				ft_plus(t_spec *spec);
void				ft_minus(t_spec *spec);
void				ft_zero(t_spec *spec);
void				ft_space(t_spec *spec);
void				ft_hash(t_spec *spec);
void				ft_hash_o(t_spec *spec);
void				ft_hash_x(t_spec *spec);
void				ft_hash_lx(t_spec *spec);
char				*ft_master_itoa(unsigned long long int n);

#endif
