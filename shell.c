#include "shell.h"
/**
 * main - sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk
 * whesdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkprogram
 * whesdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkprogram
 * whesdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkprogram
 * @argc: numbsdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkmand line
 * @argv: vasdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk line
 * @env: nsdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkmand line
 * Return: sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk
 */
int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	inicialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{/*sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk */
		errno = 2;/*sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjase ldk*/
		prompt = PROMPT_MSG;
	}
	errno = 0;
	sisifo(prompt, data);
	return (0);
}

/**
 * handle_ctrl_c - sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkline
 * whesdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkprogram
 * whesdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkprogram
 * whesdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkprogram
 * @UNUSED: sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * inicialize_data - insdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkgram
 * @data: psdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk  ata
 * @argv: arraysdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk execution
 * @env: envirosdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk ion
 * @argc: number sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk mand line
 */
void inicialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	/* sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjase ldk */
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
 * sisifo - sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjase ldk
 * whesdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldkprogram
 * @prompt: sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjase ldk
 * @data: itssdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjase ldk prompt
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
			exit(errno); /* isdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjase ldkxit*/
		}
		if (string_len >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);
			if (data->tokens[0])
			{ /* if sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjase ldk te */
				error_code = execute(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			free_recurrent_data(data);
		}
	}
}
