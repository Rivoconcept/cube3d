/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examshell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:45:01 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/12 19:32:33 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EXAMSHELL_H
# define EXAMSHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_export
{
	char			*name;
	char			*value;
	struct s_export	*next;
}					t_export;

typedef struct s_cmd
{
	char			**cmd;
	int				rank_less_error;
	int				dgreat_error;
	int				less_error;
	int				here;
	int				rank_here;
	int				flag_less;
	char			*less;
	int				rank_less;
	char			*great;
	int				rank_great;
	char			*dgreat;
	int				rank_dgreat;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}					t_cmd;

typedef struct s_params
{
	t_cmd			*command;
	t_env			*myenvp;
	int				flag_env;
	int				fd_in;
	int				fd_out;
	t_export		*myexport;
	char			**envp;
	int				last_exit_code;
	pid_t			*pid_tab;
	int				prev_pipe_read;
	int				rank_cmd;
	char			*new_input;
	char			**parsed;
}					t_params;


int word_count(char *str);
void print_argv(char **argv);
char **parse_command(const char *input);
void free_array(char **arr);
void free_list_cmd(t_cmd *command);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
int ft_strlen(char *str);
t_cmd *add_command(t_cmd *command, char **argv);
void exec_cmd(t_cmd *command, char **envp);
//void run_examshell(char *input, t_cmd *cmd, char **envp);

char	*join_paths(const char *path1, const char *path2);
int	standard_path(char **dirs, int *i, char **temp_path);

int	ft_cd(t_cmd *cmd, char *arg);
char *format_quotes(char *command);
void	del_quotes(char **argv);
#endif