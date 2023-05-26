#include "shell.h"

/**
 * builtins_list - s sgjd sgh sfdg dfghjdsf htin
 * @data: s shgfj sghsf ghjsg ha
 * Return: Reg hsgfjs fgjsfgj sfdg gtch,
 * otherwise returns -1.
 **/
int builtins_list(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};

/*was gj jsfgjsdf gjdfgre*/
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
/*i sghj sdfghsg fdhdfg hjfgh dfg fghin,*/
		if (str_compare(options[iterator].builtin, data->command_name, 0))
		{
/*exe dfgjsfghs gfg hsdf ghsdfghstion*/
			return (options[iterator].function(data));
		}
/*is ghdfg jsfgdh sdfgrn -1 */
	}
	return (-1);
}
