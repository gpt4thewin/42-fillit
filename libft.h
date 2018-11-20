/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:18:06 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/19 11:45:21 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
*	Types.
*/

/*
*	Macros.
*/

#define ABS(n) ((n > 0) ? (n) : -(n))

/*
*	Output.
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char *str);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);

/*
*	Memory.
*/

void			*ft_memset(void *ptr, int value, size_t num);
void			*ft_memcpy(void *dst, const void *src, size_t num);
void			ft_bzero(void *s, int n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t num);
void			*ft_memchr(void *ptr, int value, size_t num);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

/*
*	String.
*/

int				ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strdup(char *src);
char			*ft_strcat(char *dest, char *src);
char			*ft_strncat(char *dest, char *src, int nb);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strchr(const char *str, int character);
char			*ft_strrchr(const char *str, int character);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strnstr(const char *big, const char *little, size_t len);

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

int				ft_atoi(char *str);

char			**ft_strsplit_by_substring(char *str, char *delimiter);

/*
*	Non libc.
*/

void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);

void		ft_strclr(char *s);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strsub(char const *s, unsigned int start, size_t len);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char *str, char *charset);

#endif
