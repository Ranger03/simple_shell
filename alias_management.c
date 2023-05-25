#include "shell.h"

/**
 * print_alias - DJSF GAS SA D SDHFKAJSH DF ASDFASD FAdfg dsf gdsfgdsfgsd fgS DFASDFA SV
 * @data:  DJSF GAS SA D SDHFKAJSH DF ASDFASD FAS D dfg sdfg dfgFASDFA SV
 * @alias: na DJSF GAS SA D SDHFKAJSH DF ASDFASD FAS DFsdf dASDFA SVinted
 * Return: zero if DJSF GAS SA D SDHFKAJSH DF ASDFASD FAS DFASDFA SV FDG HJDFGhe arguments
 * GAS SA D SDHFKAJSH DF ASDFASD FAS D dfg sdfg dfgFASDFA SV
 * GAS SA D SDHFKAJSH DF ASDFASD FAS D dfg sdfg dfgFASDFA SV
 */
int print_alias(data_of_program *data, char *alias)
{
	int i, j, alis_leng;   *************************************alias_length
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alis_leng = str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_compare(data->alias_list[i], alias, alis_leng)
				&&	data->alias_list[i][alis_leng] == '='))
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
 * get_alias - ad DJSF GAS SA D SDHFKAJSH DF ASDFASD FAS DFASDFA SV DJSF GAS SA D SDHFKAJSH DF ASDFASD FAS DFASDFA SVses
 * @data: struct DJSF GAS SA D SDHFKAJSH DF ASDFASD FAS DFASDFA SV data
 * @name: name  DJSF GAS SA D SDHFKAJSH DF ASDFASD FAS DFASDFA SV alias.
 * GAS SA D SDHFKAJSH DF ASDFASD FAS D dfg sdfg dfgFASDFA SV
 * Return: zero  DJSF GAS SA D SDHFKAJSH DF ASDFASD FAS DFASDFA SV sxfdg sfdgg sduments
 */
char *get_alias(data_of_program *data, char *name)
{
	int i, alis_leng;

	/* v DJSF GAS SA D SDHFKAJSH DF ASDFASD FAS DFASDFA SV */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alis_leng = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{/* Isdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfg dfgdf e */
		if (str_compare(name, data->alias_list[i], alis_leng) &&
			data->alias_list[i][alis_leng] == '=')
		{/* returns tIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfgind it */
			return (data->alias_list[i] + alis_leng + 1);
		}
	}
	/* rIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfgit */
	return (NULL);

}

/**
 * set_alias - aIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfg
 * @alias_string: alIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfg
 * @data: struIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfgta
 * GAS SA D SDHFKAJSH DF ASDFASD FAS D dfg sdfg dfgFASDFA SV
 * GAS SA D SDHFKAJSH DF ASDFASD FAS D dfg sdfg dfgFASDFA SV
 * Return: zero Isdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfguments
 */
int set_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	/* vIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfgs */
	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	/* ItIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfgar */
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{/* searIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfglias */
			temp = get_alias(data, alias_string + i + 1);
			break;
		}

	/* IIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfgname */
	for (j = 0; data->alias_list[j]; j++)
		if (str_compare(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{/* Isdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfgst */
			free(data->alias_list[j]);
			break;
		}

	/* Isdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfg */
	if (temp)
	{/* ifIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfgst */
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[j] = str_duplicate(buffer);
	}
	else /* ifIsdf ghsldf dkfhg sfdg sdf gsdkfg sdkfg sdf gsdlf gsdf gsdf gdsf gdfgist */
		data->alias_list[j] = str_duplicate(alias_string);
	return (0);
}
