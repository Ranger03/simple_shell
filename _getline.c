#include "shell.h"

/**
* _getline - asdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldkf.
* @data: strasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasld
*
* Return: rasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldes.
*/
int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *arry_coms[10] = {NULL};
	static char arry_ops[10] = {'\0'};
	ssize_t bin_red, i = 0;

	/* casdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasld */
	/* anasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd faslds */
	if (!arry_coms[0] || (arry_ops[0] == '&' && errno != 0) ||
		(arry_ops[0] == '|' && errno == 0))
	{
		/*frasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldexists */
		for (i = 0; arry_coms[i]; i++)
		{
			free(arry_coms[i]);
			arry_coms[i] = NULL;
		}

		/* rasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldbuff */
		bin_red = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bin_red == 0)
			return (-1);

		/* sasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldor ; */
		i = 0;
		do {
			arry_coms[i] = str_duplicate(_strtok(i ? NULL : buff, "\n;"));
			/*chasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd faslderators*/
			i = check_logic_ops(arry_coms, i, arry_ops);
		} while (arry_coms[i++]);
	}

	/*obtaasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldrray*/
	data->input_line = arry_coms[0];
	for (i = 0; arry_coms[i]; i++)
	{
		arry_coms[i] = arry_coms[i + 1];
		arry_ops[i] = arry_ops[i + 1];
	}

	return (str_length(data->input_line));
}


/**
* check_logic_ops - cheasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldrs
* @array_commands: arrasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldds.
* @i: inasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldecked
* @array_operators: aasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldommand
*
* Return: indasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldnds.
*/
int check_logic_ops(char *arry_coms[], int i, char arry_ops[])
{
	char *temp = NULL;
	int k;

	/* casdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldne*/
	for (k = 0; arry_coms[i] != NULL  && arry_coms[i][k]; k++)
	{
		if (arry_coms[i][k] == '&' && arry_coms[i][k + 1] == '&')
		{
			/* splasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasldd */
			temp = arry_coms[i];
			arry_coms[i][k] = '\0';
			arry_coms[i] = str_duplicate(arry_coms[i]);
			arry_coms[i + 1] = str_duplicate(temp + k + 2);
			i++;
			arry_ops[i] = '&';
			free(temp);
			k = 0;
		}
		if (arry_coms[i][k] == '|' && arry_coms[i][k + 1] == '|')
		{
			/* spasdkfhjgaksd fakjsdg asdgf asdhlas dlfalsk dfalksdfla ksd kasdhf lajsdhahs dlahsd fasld nd */
			temp = arry_coms[i];
			arry_coms[i][k] = '\0';
			arry_coms[i] = str_duplicate(array_commands[i]);
			arry_coms[i + 1] = str_duplicate(temp + j + 2);
			i++;
			arry_ops[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
