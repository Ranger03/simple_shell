#include "shell.h"

/**
 * print_alias - add, sadf sdf asdes
 * @data: sasdf asdf asd fasd as ta
 * @alias: asdf asd fasd fasd fed
 * Return: zasd fasd fasdf asd fas gasdfgsdf asfuments
 */
int print_alias(data_of_program *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_compare(data->alias_list[i], alias, alias_length)
				&&	data->alias_list[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - add, a sdfasdf asdf asds
 * @data: sa sdfasdfasdg fdgsd fata
 * @name: na sdfgsdfg sdfgsdfg sdfs.
 * Return: zesdf gsdfgsdf gsdfhsdfhdfg dfg ments
 */
char *get_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	/* va sdfg sdfg sdfg sdfts */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{/* Itdf gsdfgsdfg sdghdfghf ghfdsg hsame */
		if (str_compare(name, data->alias_list[i], alias_length) &&
			data->alias_list[i][alias_length] == '=')
		{/* r sdfg sdfgshfdhgjtdrf gsfdg ggsdfg sdf it */
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	/* returns N dfgsd fhsfdg t */
	return (NULL);

}

/**
 * set_alias - add, o sdfg sdfhs
 * @alias_string: al sdfgsdfgsdhsdf dm (name='value')
 * @data: ssd fgsdfhsdfgh sdfdata
 * Return: zer gsdfg sghjsdf gsdf guments
 */
int set_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	/* va dsfhsgdhsdfgs ts */
	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	/* It sdfhsdf gsdf ar */
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{/* sea gsdf gsdgfhsdf gsas */
			temp = get_alias(data, alias_string + i + 1);
			break;
		}

	/* Iterd fhs sdfghsdfh sdf sdf name */
	for (j = 0; data->alias_list[j]; j++)
		if (str_compare(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{/* if the alias alredy exist */
			free(data->alias_list[j]);
			break;
		}

	/* adsd fhsgdf hsdf as */
	if (temp)
	{/* if  sdfg sdfg sdf t */
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[j] = str_duplicate(buffer);
	}
	else /* if  gsdfg sdfh sdf hxist */
		data->alias_list[j] = str_duplicate(alias_string);
	return (0);
}
