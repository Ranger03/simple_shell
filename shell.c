#include "shell.h"
/**
 * main -  xzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfa
 * @argc: nxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfad line
 * @argv: valuxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfaand line
 * @env: numbxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfaommand line
 * Return: zxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfan succes.
 */
int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	inicialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{/* xzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfae */
		errno = 2;/*???????*/
		prompt = PROMPT_MSG;
	}
	errno = 0;
	sisifo(prompt, data);
	return (0);
}

/**
 * handle_ctrxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfa prxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfat in a new line
 * when the sigxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfa the program
 * @UNUSED: opxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfatype
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * inicialize_data - ixzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfam
 * @data: pxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfaata
 * @argv: arraxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfarogram execution
 * @env: envirxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfam execution
 * @argc: number oxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfacommand line
 */
void inicialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	/* defxzcvlzkc zx cv;l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfa be readed*/
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = str_duplicate(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}
/**
 * sisifo - ixzcvlzkc zx cvld  asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfarompt
 * @prompt: prxzcvlzkc zx cd dl asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfaprinted
 * @data: its a xzcvlzkc zx d l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfahows the prompt
 */
void sisifo(char *prompt, data_of_program *data)
{
	int error_code = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = string_len = _getline(data);

		if (error_code == EOF)
		{
			free_all_data(data);
			exit(errno); /* is a xzcvlzkc zx d l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfahows thexit*/
		}
		if (string_len >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);
			if (data->tokens[0])
			{ /* if a texs a xzcvlzkc zx d l asdfasdj fhasdf asdflaa sdfl asdfaiuos dhfahows thexecute */
				error_code = execute(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			free_recurrent_data(data);
		}
	}
}
