#include "shell.h"

/**
 * print_alias - add sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * @data: add sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * @alias: namadd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * Return: zero ifadd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es the arguments
 */
int print_alias(data_of_program *data, char *alias)
{
	int k, p, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (k = 0; data->alias_list[k]; k++)
		{
			if (!alias || (str_compare(data->alias_list[k], alias, alias_length)
				&&	data->alias_list[k][alias_length] == '='))
			{
				for (p = 0; data->alias_list[k][p]; p++)
				{
					buffer[p] = data->alias_list[k][p];
					if (data->alias_list[k][p] == '=')
						break;
				}
				buffer[p + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[k] + p + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - add,add sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * @data: stadd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es data
 * @name: naadd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk esalias.
 * Return: zeradd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es e arguments
 */
char *get_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	/* validate the arguments */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{/* add sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es varname */
		if (str_compare(name, data->alias_list[i], alias_length) &&
			data->alias_list[i][alias_length] == '=')
		{/* add sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk esit */
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	/* radd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es it */
	return (NULL);

}

/**
 * set_alias - aadd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * @alias_string: aadd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es
 * @data: stadd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es data
 * Return: zero iadd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es the arguments
 */
int set_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	/* add sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk ess */
	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	/* Iadd sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk eschar */
	/* Iadd sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk eschar */
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{/* sadd sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es alias */
			temp = get_alias(data, alias_string + i + 1);
			break;
		}

	/* add sdf asdlkjf asdfj asdkjf;l asjdf asdfj lasdjfased fjaseldk es varname */
	/* Iadd sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk eschar */
	for (j = 0; data->alias_list[j]; j++)
		if (str_compare(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{/* add sdf asdlkjf asdfj asdkjfl asjdf asdfj lasdjfased fjaseldk esist */
			free(data->alias_list[j]);
			break;
		}

	/* add sdf asdlkjf asdfj asdkjfl asjdf asdfj lasdjfased fjaseldk esist */
	/* Iadd sdf asdlkjf asdfj asdkjf l asjdf asdfj lasdjfased fjaseldk eschar */
	if (temp)
	{/* add sdf asdlkjf asdfj asdkjfl asjdf asdfj lasdjfased fjaseldk esist dv */
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[j] = str_duplicate(buffer);
	}
	else /* add sdf asdlkjf asdfj asdkjfl asjdf asdfj lasdjfased fjaseldk esist */
		data->alias_list[j] = str_duplicate(alias_string);
	return (0);
}
