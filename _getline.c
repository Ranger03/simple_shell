#include "shell.h"

/**
* _getline - sadfh asdhf asdhf asd asl.
* @data: asdfa sdlf aaer asd
*
* Return: asdf asd aioeaq nt.
*/
int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	/* cdsakfhl sdfhal da t */
	/* asdf asd asdf as */
	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		/*asd fasdfas df asdf r */
		for (i = 0; array_commands[i]; i++)
		{
			free(array_commands[i]);
			array_commands[i] = NULL;
		}

		/* rfak a hdfa skdf askdf asdf alsdf */
		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		/* sfha haksdf ha fhadhk fasdj asdkf ; */
		i = 0;
		do {
			array_commands[i] = str_duplicate(_strtok(i ? NULL : buff, "\n;"));
			/*fasjkldf askdfakl df ad fald fa dfak sdf*/
			i = check_logic_ops(array_commands, i, array_operators);
		} while (array_commands[i++]);
	}

	/*ahsdljkf aldh fald ahdf akjdh faldh*/
	data->input_line = array_commands[0];
	for (i = 0; array_commands[i]; i++)
	{
		array_commands[i] = array_commands[i + 1];
		array_operators[i] = array_operators[i + 1];
	}

	return (str_length(data->input_line));
}


/**
* check_logic_ops - asdkgf aksdg && and || adsgfaag
* @array_commands: askdf alkdsfa ksdaf.
* @i: askhdjfkalskd fakd kfahdkfahdkj fajd fa df
* @array_operators: asgdkg adg akdhgfakjhdfjakd fa dfkjahd sa sdk akd faksdf
*
* Return: kahsd fakdl kadfkahsd kah kdsfhak dfakld fkadfd.
*/
int check_logic_ops(char *array_commands[], int i, char array_operators[])
{
	char *temp = NULL;
	int j;

	/* asdjflkad fa dfja skdfkasdf klasdfk asdfk*/
	for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
	{
		if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
		{
			/* afhlksjdhfkajhsd fahlksdhfkashdf asdfd */
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
			/* hfaskdjh fasdhkf asdhf akdlfkahsdjf ak */
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
