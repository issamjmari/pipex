#ifndef PIPEX_H
# define PIPEX_H
#include <unistd.h>
#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);
void error1 (char **av);
void error2 (char **av);
#endif