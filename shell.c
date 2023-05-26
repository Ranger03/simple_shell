#include "shell.h"
/**
 * main - asjd fasdgfad as dkjfasd kfa skd faksda ksdfak 
 * @argc: nasjd fasdgfad as dkjfasd kfa skd faksda ksdfak ine
 * @argv: vaasjd fasdgfad as dkjfasd kfa skd faksda ksdfak e
 * @env: nuasjd fasdgfad as dkjfasd kfa skd faksda ksdfak nd line
 * Return: zasjd fasdgfad as dkjfasd kfa skd faksda ksdfak es.
 */
int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	inicialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{/* Wasjd fasdgfad as dkjfasd kfa skd faksda ksdfak ode */
		errno = 2;/*???????*/
		prompt = PROMPT_MSG;
	}
	errno = 0;
	sisifo(prompt, data);
	return (0);
}

/**
 * handle_ctrl_c - pasjd fasdgfad as dkjfasd kfa skd faksda ksdfak ne
 * whasjd fasdgfad as dkjfasd kfa skd faksda ksdfak ogram
 * @UNUSED: oasjd fasdgfad as dkjfasd kfa skd faksda ksdfak ype
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * inicialize_data - inasjd fasdgfad as dkjfasd kfa skd faksda ksdfak gram
 * @data: poiasjd fasdgfad as dkjfasd kfa skd faksda ksdfak ta
 * @argv: aasjd fasdgfad as dkjfasd kfa skd faksda ksdfak tion
 * @env: envasjd fasdgfad as dkjfasd kfa skd faksda ksdfak ution
 * @argc: nuasjd fasdgfad as dkjfasd kfa skd faksda ksdfak nd line
 */
void inicialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	/* deasjd fasdgfad as dkjfasd kfa skd faksda ksdfak ded*/
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
 * sisifo - iasjd fasdgfad as dkjfasd kfa skd faksda ksdfak mpt
 * @prompt: pasjd fasdgfad as dkjfasd kfa skd faksda ksdfak ed
 * @data: itasjd fasdgfad as dkjfasd kfa skd faksda ksdfak mpt
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
			exit(errno); /* iasjd fasdgfad as dkjfasd kfa skd faksda ksdfak xit*/
		}
		if (string_len >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);
			if (data->tokens[0])
			{ /* iasjd fasdgfad as dkjfasd kfa skd faksda ksdfak ute */
				error_code = execute(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			free_recurrent_data(data);
		}
	}
}
