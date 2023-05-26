#include "shell.h"

/**
 * builtin_env - sdf sgsdf sdgh dfg sfghsd sdf ns
 * @data: s dahsrtj sg hsdf gadfta
 * Return: zero sjfg hsdf garfdhj satuj fafhants
 */
int builtin_env(data_of_program *data)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	/* if not arguments */
	if (data->tokens[1] == NULL)
		print_environ(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{/* chf dhfghsjs fsar = */
			if (data->tokens[1][i] == '=')
			{/* ch sdfhfgjs dfgsadfh sdft guwsgdg dfge*/
			/* ts dfgjly */
				var_copy = str_duplicate(env_get_key(cpname, data));
				if (var_copy != NULL)
					env_set_key(cpname, data->tokens[1] + i + 1, data);

				/* p sdfgjfdg hsdn */
				print_environ(data);
				if (env_get_key(cpname, data) == NULL)
				{/* p sghjshsd hdfghs ron */
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{/* returns ts dfghgfh sdf fgr*/
					env_set_key(cpname, var_copy, data);
					free(var_copy);
				}
				return (0);
			}
			cpname[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * builtin_set_env - ..
 * @data: s sdghs dfghs gata
 * Return: zer sdfghjsfgj fsdg hdfhgjs gs g hjsg uments
 */
int builtin_set_env(data_of_program *data)
{
	/* v dfgjsf gjgs */
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
 * @data: st sgd jfgj sdfg jstga'
 * Return: ..
 */
int builtin_unset_env(data_of_program *data)
{
	/* v sdgfj dfgjsggs */
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
