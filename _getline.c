#include "shell.h"

/**
* _getline - sadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd.
* @data: stsadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasda
* adfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes
* adfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes
* adfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes
* adfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes
* Return: sadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes.
*/
int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	/* adfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytesy */
	/* anadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes */
	/* anadfh aklsdfsdfg sdfgsdfg sdf gdf gsdfg sdfdf gd d fasdhf asdas dfasd ytes */
	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		/*freadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytessts */
		/* anadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes */
		for (i = 0; array_commands[i]; i++)
		{
			free(array_commands[i]);
			array_commands[i] = NULL;
		}

		/* readadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytesto buff */
		/* anadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes */
		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		/* sadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes */
		/* anadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes */
		i = 0;
		do {
			array_commands[i] = str_duplicate(_strtok(i ? NULL : buff, "\n;"));
			/*checadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytesators*/
			i = check_logic_ops(array_commands, i, array_operators);
		} while (array_commands[i++]);
	}

	/*obtadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes array*/
	data->input_line = array_commands[0];
	for (i = 0; array_commands[i]; i++)
	{
		array_commands[i] = array_commands[i + 1];
		array_operators[i] = array_operators[i + 1];
	}

	return (str_length(data->input_line));
}


/**
* check_logic_ops - cadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytesrs
* @array_commands: aadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes
* @i: indadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes
* @array_operators: aradfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes command
*
* Return: inadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes_commands.
*/
int check_logic_ops(char *array_commands[], int i, char array_operators[])
{
	char *temp = NULL;
	int j;

	/* cadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytesine*/
	for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
	{
		if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
		{
			/* sadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytesd */
			/* anadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes */
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = str_duplicate(array_commands[i]);
			array_commands[i + 1] = str_duplicate(temp + j + 2);
			i++;
			array_operators[i] = '&';
			free(temp);
			j = 0;
		}
		if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
		{
			/* sadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytesund */
			/* anadfh aklsdfh askdhf kalsdhf lasdh flakshd laksd fasdhf asdas dfasd ytes */
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = str_duplicate(array_commands[i]);
			array_commands[i + 1] = str_duplicate(temp + j + 2);
			i++;
			array_operators[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
