/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:59:56 by amak              #+#    #+#             */
/*   Updated: 2023/03/20 23:03:22 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

/* STRUCTURES: */
typedef struct s_pipex
{
	int		tube[2];
	char	**paths;
	int		infile;
	int		outfile;
	char	**cmd_flags;
	char	*cmd_path;
	char	*cmd;

}	t_pipex;

/* LIBFT FUNCTIONS: */
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

/* UTILS FUNCTIONS: */
void	file_error(char *filename);
void	error_exit(char *error_msg);
char	**find_paths(char **envp);
void	init_pipex(char **argv, char **envp, t_pipex *pipex);
void	free_pipex(t_pipex *pipex);

/* PROCESSES FUNCTION: */
char	*find_cmdpath(char **paths, char *cmd);
void	first_process(t_pipex *pipex, char **argv, char **envp);
void	second_process(t_pipex *pipex, char **argv, char **envp);

#endif
