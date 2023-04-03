/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:59:56 by amak              #+#    #+#             */
/*   Updated: 2023/04/03 22:07:22 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

/* STRUCTURES: */
typedef struct s_pipex
{
	int		pipe_tube[2];
	int		infile;
	int		outfile;
	char	**directories;
	char	**cmd_flags;
	char	*cmd;
	char	*cmd_path;
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
void	error_exit(char *error_msg);
char	**find_directories(char **envp);
void	free_pipex(t_pipex *pipex);
void	close_pipe(t_pipex *pipex);

/* PROCESSES FUNCTION: */
char	*find_cmdpath(char **paths, char *cmd);
void	free_process(t_pipex *pipex);
void	first_process(t_pipex pipex, char **argv, char **envp);
void	second_process(t_pipex pipex, char **argv, char **envp);

#endif
