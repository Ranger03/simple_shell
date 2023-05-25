#include "shell.h"

/**
 * builtin_env - dsad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf l
 * @data: sad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf l data
 * sad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf l
 * sad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf l
 * sad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf l
 * Return: zersad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf lrguments
 */
int builtin_env(data_of_program *data)
{
	int i;
	char kvnamu[50] = {'\0'}; **************************************cpname
	char *rav_cpi = NULL;     **************************************var_copy

	/* if not arguments */
	if (data->tokens[1] == NULL)
		print_environ(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{/* checks if exists a char = */
			if (data->tokens[1][i] == '=')
			{/* csad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf le*/
			/* tesad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf ly */
				rav_cpi = str_duplicate(env_get_key(kvnamu, data));
				if (rav_cpi != NULL)
					env_set_key(kvnamu, data->tokens[1] + i + 1, data);

				/* psad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf lon */
				print_environ(data);
				if (env_get_key(kvnamu, data) == NULL)
				{/* prisad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf lon */
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{/* resad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf lr*/
					env_set_key(kvnamu, rav_cpi, data);
					free(rav_cpi);
				}
				return (0);
			}
			kvnamu[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * builtin_set_env - ..
 * @data: ssad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf lta
 * sad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf l
 * sad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf l
 * Return: zsad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf lsad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf le arguments
 */
int builtin_set_env(data_of_program *data)
{
	/* vsad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf l */
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
 * builtin_unset_env - ..
 * @data: sad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf lta'
 * sad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf l
 * Return: sad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf l
 */
int builtin_unset_env(data_of_program *data)
{
	/* vasad gfskjdf skdf fsdkfosacnahlhjdlkfsl s  sdjkfjlsdfs sd dkflsdl sdf lgs */
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
