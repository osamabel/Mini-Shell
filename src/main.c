#include "minishell.h"

void	prompt(char *_prompt, char **envp)
{
	char	*cmd;
	while (1)
	{
		struct termios tp;
		if (tcgetattr(STDIN_FILENO, &tp))
			perror("tcgetattr");
		tp.c_lflag &= ~ECHOCTL;
		if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp))
			perror("tcsetattr");
		cmd = readline(_prompt);
		if (cmd)
			history(cmd, envp);
	}
}


int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	update_shlvl(envp);
	history(NULL, envp);
	prompt("$minishll ", envp);


}
