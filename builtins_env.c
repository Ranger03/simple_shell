#include "shell.h"

/**
 * builtin_env - shows sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * @data:  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es data
 * sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * Return: zero  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es sdfgsdf d
 */
int builtin_env(data_of_program *data)
{
	int i;
	char kvnum[50] = {'\0'};
	char *var_copy = NULL;

	/*  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es */
	if (data->tokens[1] == NULL)
		print_environ(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{/*  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es char = */
			if (data->tokens[1][i] == '=')
			{/*  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es value*/
			/*  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es */
				var_copy = str_duplicate(env_get_key(kvnum, data));
				if (var_copy != NULL)
					env_set_key(kvnum, data->tokens[1] + i + 1, data);

				/*  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es */
				print_environ(data);
				if (env_get_key(kvnum, data) == NULL)
				{/*  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es */
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{/*  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es */
					env_set_key(kvnum, var_copy, data);
					free(var_copy);
				}
				return (0);
			}
			kvnum[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * builtin_set_env -  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * @data: s sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk esam's data
 * sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * Return: ze sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es n the arguments
 */
int builtin_set_env(data_of_program *data)
{
	/*  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es */
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	env_set_key(data->tokens[1], data->tokens[2], data);

	return (0);
}

/**
 * builtin_unset_env - sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * @data:  sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk esdata'
 * sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * Return:  sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 */
int builtin_unset_env(data_of_program *data)
{
	/* asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased */
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	env_remove_key(data->tokens[1], data);

	return (0);
}
