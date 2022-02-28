/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:06:27 by ijmari            #+#    #+#             */
/*   Updated: 2022/02/28 18:05:20 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);
void	error1(char **av);
void	error2(char **av);
char	*path_valid(char **paths, char **arg, int i, int j);
void	ft_free(char **ptr1);
#endif