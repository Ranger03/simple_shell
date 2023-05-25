#include "shell.h"

/**
* _getline - xczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxcv 
* @data: stxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxm's data
*
* Return: rxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxing bytes.
*/
int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_coms[10] = {NULL};
	static char arry_ops[10] = {'\0'};
	ssize_t byt_red, i = 0;

	/* checkxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxst more commands in the array */
	/* and checxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxrators */
	if (!array_coms[0] || (arry_ops[0] == '&' && errno != 0) ||
		(arry_ops[0] == '|' && errno == 0))
	{
		/*free xczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zx array if it exists */
		for (i = 0; array_coms[i]; i++)
		{
			free(array_coms[i]);
			array_coms[i] = NULL;
		}

		/* reaxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxiptor int to buff */
		byt_red = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (byt_red == 0)
			return (-1);

		/* sxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxor ; */
		i = 0;
		do {
			array_coms[i] = str_duplicate(_strtok(i ? NULL : buff, "\n;"));
			/*chexczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zx|| operators*/
			i = check_logic_ops(array_coms, i, arry_ops);
		} while (array_coms[i++]);
	}

	/*obtainsxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxt for the array*/
	data->input_line = array_coms[0];
	for (i = 0; array_coms[i]; i++)
	{
		array_coms[i] = array_coms[i + 1];
		arry_ops[i] = arry_ops[i + 1];
	}

	return (str_length(data->input_line));
}


/**
* check_logic_ops - cxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zx operators
* @array_coms: arrxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxands.
* @i: index in thxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxbe checked
* @arry_ops: arraxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxprevious command
*
* Return: index ofxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxrray_commands.
*/
int check_logic_ops(char *array_coms[], int i, char arry_ops[])
{
	char *temp = NULL;
	int j;

	/* checks fxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxd line*/
	for (j = 0; array_coms[i] != NULL  && array_coms[i][j]; j++)
	{
		if (array_coms[i][j] == '&' && array_coms[i][j + 1] == '&')
		{
			/* splxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zx found */
			temp = array_coms[i];
			array_coms[i][j] = '\0';
			array_coms[i] = str_duplicate(array_coms[i]);
			array_coms[i + 1] = str_duplicate(temp + j + 2);
			i++;
			arry_ops[i] = '&';
			free(temp);
			j = 0;
		}
		if (array_coms[i][j] == '|' && array_coms[i][j + 1] == '|')
		{
			/* splxczkjlhvszd z xcv zxcv zxclvzx cvzx cvzlxcvz xcv zxc vzxclv zxs found */
			temp = array_coms[i];
			array_coms[i][j] = '\0';
			array_coms[i] = str_duplicate(array_coms[i]);
			array_coms[i + 1] = str_duplicate(temp + j + 2);
			i++;
			arry_ops[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
