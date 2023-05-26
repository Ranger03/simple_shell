#include "shell.h"
/**
 * main - iaad a sdfasjdkalkasdf ram
 * @argc: num ajsdh alsdf alsdjfaksd asdjh adfa sd ine
 * @argv: valuum ajsdh alsdf alsdjfaksd asdjh adfa sd ine ne
 * @env: numum ajsdh alsdf alsdjfaksd asdjh adfa sd ine line
 * Return: zum ajsdh alsdf alsdjfaksd asdjh adfa sd ines.
 */
int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *bromuk = "";

	inicialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{/* Wum ajsdh alsdf alsdjfaksd asdjh adfa sd ine de */
		errno = 2;/*???????*/
		bromuk = PROMPT_MSG;
	}
	errno = 0;
	sisifo(bromuk, data);
	return (0);
}

/**
 * handle_ctrl_c - prum ajsdh alsdf alsdjfaksd asdjh adfa sd ine e
 * whe num ajsdh alsdf alsdjfaksd asdjh adfa sd ine ogram
 * @UNUSED: opum ajsdh alsdf alsdjfaksd asdjh adfa sd ine pe
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * inicialize_data - inum ajsdh alsdf alsdjfaksd asdjh adfa sd ine gram
 * @data: poium ajsdh alsdf alsdjfaksd asdjh adfa sd ine ta
 * @argv: arrum ajsdh alsdf alsdjfaksd asdjh adfa sd ine ution
 * @env: envum ajsdh alsdf alsdjfaksd asdjh adfa sd ine tion
 * @argc: nuum ajsdh alsdf alsdjfaksd asdjh adfa sd ine and line
 */
void inicialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	/* defum ajsdh alsdf alsdjfaksd asdjh adfa sd ine d*/
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
 * sisifo - um ajsdh alsdf alsdjfaksd asdjh adfa sd ine ompt
 * @prompt: pum ajsdh alsdf alsdjfaksd asdjh adfa sd ine ed
 * @data: itum ajsdh alsdf alsdjfaksd asdjh adfa sd ine ompt
 */
void sisifo(char *bromuk, data_of_program *data)
{
	int miss_mode = 0, strgs_lenght = 0;

	while (++(data->exec_counter))
	{
		_print(bromuk);
		miss_mode = strgs_lenght = _getline(data);

		if (miss_mode == EOF)
		{
			free_all_data(data);
			exit(errno); /* ium ajsdh alsdf alsdjfaksd asdjh adfa sd inet */
		}
		if (strgs_lenght >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);
			if (data->tokens[0])
			{ /* ium ajsdh alsdf alsdjfaksd asdjh adfa sd ine ute */
				miss_mode = execute(data);
				if (miss_mode != 0)
					_print_error(miss_mode, data);
			}
			free_recurrent_data(data);
		}
	}
}
