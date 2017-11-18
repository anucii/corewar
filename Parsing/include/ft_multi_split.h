/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_split.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:21:49 by jgonthie          #+#    #+#             */
/*   Updated: 2017/11/18 13:24:33 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MULTI_SPLIT_H
# define FT_MULTI_SPLIT_H

# include "./libft/libft.h"
# include <fcntl.h>

# define HASH			'#'
# define SPACE			' '
# define TAB			'\t'
# define DOT			'.'
# define COMMA			','
# define COTE			'\"'
# define COLON			':'
# define LABEL_CHAR 	"abcdefghijklmnopqrstuvwxyz_0123456789"

# define INFO			0
# define LABEL			1
# define NAME			0
# define COMMENT		1

typedef struct			s_info
{
	int					type;
	char				name[129];
	char				comment[2047];
}						t_info;

typedef struct			s_order
{
	int					op_code;
	int					nb_param;
	char				param[129][129];
}						t_order;

typedef struct			s_label
{
	char				name[129];
	struct s_order		order;
}						t_label;

typedef struct			s_token
{
	int					type;
	struct s_info		info;
	struct s_label		label;
	struct s_order		order;
}						t_token;

typedef struct			s_file
{
	char				*line;
	int					fd;
	int					ret;
}						t_file;

int			ft_multi_split(char ***token, char *s);
int			ft_multi_split_2(t_token *token, t_file file);
int			ft_count_line(char *s);
int			ft_is_label_char(char c, char *label_char);
int     	ft_info_line(t_token **token, char *s);
int     	ft_info_label(t_token **token, t_file file);

#endif
