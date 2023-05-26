#include "shell.h"

/**
 * builtin_exit - ed fghjdfg hsf hsfgdh sfds
 * @data: ss dfgh sghdfgjdf ghsa
 * Return: ze dfgj fgshs dftgh autjaghs fdgents
 */
int builtin_exit(data_of_program *data)
{
	int i;

	if (data->tokens[1] != NULL)
	{/*isgh s gfhsdfgjsdgf hsmber*/
		for (i = 0; data->tokens[1][i]; i++)
			if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
				&& data->tokens[1][i] != '+')
			{/*i dfgjs fg hser*/
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	free_all_data(data);
	exit(errno);
}

/**
 * builtin_cd - csgh sgj sfgh fsdgry
 * @data: st hsgfjs ghs fdghta
 * Return: zesghsdf gjs fdghsdfh sdfgh fgh nts
 */
int builtin_cd(data_of_program *data)
{
	char *dir_home = env_get_key("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (str_compare(data->tokens[1], "-", 0))
		{
			dir_old = env_get_key("OLDPWD", data);
			if (dir_old)
				error_code = set_work_directory(data, dir_old);
			_print(env_get_key("PWD", data));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (set_work_directory(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (set_work_directory(data, dir_home));
	}
	return (0);
}

/**
 * set_work_directory - ss fgdjdhf jsfg hsory
 * @data: sts gfjfhg g gfdhd fgta
 * @new_dir: p sdfgjdfg sdfgh dfghjd gfory
 * Return: ze fgjdfhgjs fgh sghj dfg dfhgj nts
 */
int set_work_directory(data_of_program *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!str_compare(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		env_set_key("PWD", new_dir, data);
	}
	env_set_key("OLDPWD", old_dir, data);
	return (0);
}

/**
 * builtin_help - sh dfgjsdfg hfg fdgh dfgh fgl runs
 * @data: str dfgjdf ghfdhdfgh dfhga
 * Return: ze dfgj dfgh dfgj dfg dfhgj ments
 */
int builtin_help(data_of_program *data)
{
	int i, length = 0;
	char *mensajes[6] = {NULL};

	mensajes[0] = HELP_MSG;

	/* validate args */
	if (data->tokens[1] == NULL)
	{
		_print(mensajes[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	mensajes[1] = HELP_EXIT_MSG;
	mensajes[2] = HELP_ENV_MSG;
	mensajes[3] = HELP_SETENV_MSG;
	mensajes[4] = HELP_UNSETENV_MSG;
	mensajes[5] = HELP_CD_MSG;

	for (i = 0; mensajes[i]; i++)
	{
		/*p gfdjdfg hdfg df jdfg ing */
		length = str_length(data->tokens[1]);
		if (str_compare(data->tokens[1], mensajes[i], length))
		{
			_print(mensajes[i] + length + 1);
			return (1);
		}
	}
	/*if gdjdfhgj dfg dfgj dfg fgn -1 */
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

/**
 * builtin_alias -  dfgjdfg dfghj dfghd es
 * @data: stdf gjdfg hg hdfg jkdfg fga
 * Return: zdfg jdf jdfg dfgjdfg jdf gents
 */
int builtin_alias(data_of_program *data)
{
	int i = 0;

	/* if th dfgjksdfg hfdghjsdfg hnment */
	if (data->tokens[1] == NULL)
		return (print_alias(data, NULL));

	while (data->tokens[++i])
	{/* if dfg jdsfg hgdhfjdfg fgfd riable*/
		if (count_characters(data->tokens[i], "="))
			set_alias(data->tokens[i], data);
		else
			print_alias(data, data->tokens[i]);
	}

	return (0);
}
