#include "shell.h"

/**
 * builtin_exit - sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased status
 * @data: stsdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased's data
 * sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * Return: zero sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es arguments
 */
int builtin_exit(data_of_program *data)
{
	int p;

	if (data->tokens[1] != NULL)
	{/*sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es*/
		for (p = 0; data->tokens[1][p]; p++)
			if ((data->tokens[1][p] < '0' || data->tokens[1][p] > '9')
				&& data->tokens[1][p] != '+')
			{/*sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es*/
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	free_all_data(data);
	exit(errno);
}

/**
 * builtin_cd - sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * @data: sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * Return: zersdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es arguments
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
 * set_work_directory - sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * @data: stsdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es data
 * @new_dir: pasdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk esrectory
 * sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * Return: zesdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es the arguments
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
 * builtin_help - ssdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk esell runs
 * @data: struct fosdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk ess data
 * sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * Return: zerosdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es arguments
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
		/*sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es */
		length = str_length(data->tokens[1]);
		if (str_compare(data->tokens[1], mensajes[i], length))
		{
			_print(mensajes[i] + length + 1);
			return (1);
		}
	}
	/*sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es */
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

/**
 * builtin_alias - sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * @data: stsdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk esata
 * sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es
 * Return: zesdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk es arguments
 */
int builtin_alias(data_of_program *data)
{
	int t = 0;

	/* ifsdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk esonment */
	if (data->tokens[1] == NULL)
		return (print_alias(data, NULL));

	while (data->tokens[++t])
	{/* if sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk esiable*/
		if (count_characters(data->tokens[t], "="))
			set_alias(data->tokens[t], data);
		else
			print_alias(data, data->tokens[t]);
	}

	return (0);
}
