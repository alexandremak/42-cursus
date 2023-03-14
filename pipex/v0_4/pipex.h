/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:59:56 by amak              #+#    #+#             */
/*   Updated: 2023/03/14 21:31:21 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	*infile;
	char	**cmd_flags1;
	char	*cmd_path1;
	char	**cmd_flags2;
	char	*cmd_path2;
	char	*outfile;
}	t_pipex;

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putstr(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	check_file(char *pathfile);
char	*find_path_line(char **envp);
char	*find_pathfile(char **envp, char *cmd);

#endif
