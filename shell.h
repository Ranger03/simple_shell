#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* asdfj asdf kalsdfhal hea dfkhasdfh iaudf*/
#include <unistd.h> /* ffj asdf kalsdfhal hea dfkhasdfh iaudfve*/
#include <stdlib.h>
#include <string.h> /* ffj asdf kalsdfhal hea dfkhasdfh iaudfk*/
#include <stddef.h>
#include <errno.h> /* forfj asdf kalsdfhal hea dfkhasdfh iaudferror */
#include <sys/types.h> /* ffj asdf kalsdfhal hea dfkhasdfh iaudfd */
#include <sys/wait.h> /* fofj asdf kalsdfhal hea dfkhasdfh iaudfait */
#include <sys/stat.h> /* ffj asdf kalsdfhal hea dfkhasdfh iaudftion */
#include <signal.h> /* fofj asdf kalsdfhal hea dfkhasdfh iaudfent */
#include <fcntl.h> /* fofj asdf kalsdfhal hea dfkhasdfh iaudfles*/

/**************************************************** MACROS ******************************************************************/

#include "macros.h" /* fofj asdf kalsdfhal hea dfkhasdfh iaudfpt */

/******************************************************* STRUCTURES *****************************************************/

/**
 * struct info- strfj asdf kalsdfhal hea dfkhasdfh iaudf ogram's data
 * @program_name: thefj asdf kalsdfhal hea dfkhasdfh iaudf ecutable
 * @input_line: poifj asdf kalsdfhal hea dfkhasdfh iaudf tline
 * @command_name: poinfj asdf kalsdfhal hea dfkhasdfh iaudf user
 * @exec_counter: numfj asdf kalsdfhal hea dfkhasdfh iaudfands
 * @file_descriptor: ffj asdf kalsdfhal hea dfkhasdfh iaudfmmands
 * @tokens: pointer tofj asdf kalsdfhal hea dfkhasdfh iaudf ut
 * @env: cfj asdf kalsdfhal hea dfkhasdfh iaudf ron
 * @alias_list: arrfj asdf kalsdfhal hea dfkhasdfh iaudf es.
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

/**
 * struct builtins - stfj asdf kalsdfhal hea dfkhasdfh iaudf ns
 * @builtin: the fj asdf kalsdfhal hea dfkhasdfh iaudf n
 * @function: the fj asdf kalsdfhal hea dfkhasdfh iaudf ltin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;


/**************************************************** MAIN FUNCTIONS *********************************************/


/*================================================  shell.c  ================================================*/

/* Inicifj asdf kalsdfhal hea dfkhasdfh iaudf ogram */
void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);

/* Makfj asdf kalsdfhal hea dfkhasdfh iaudf mpt*/
void sisifo(char *prompt, data_of_program *data);

/* Print the prompt in a new line */
void handle_ctrl_c(int opr UNUSED);


/*================================================  _getline.c  ========================================*/

/* Raskj fsljd fka sdflkadf lak dfkasdh fput*/
int _getline(data_of_program *data);

/* spla heoaphvaasdhf aalsd  la ad aldflast */
int check_logic_ops(char *array_commands[], int i, char array_operators[]);


/*================================================ expansions.c ========================================*/

/* e alksdfkhaliksdhfa hdlfhasld halskd ka dkas dfkasdlk f ad s */
void expand_variables(data_of_program *data);

/* e klasdk faklsdh flkasd flkahsd lkasd fas d lkf haklsdf a */
void expand_alias(data_of_program *data);

/* ap aksdhfj asdkf aks df aksd faksdf lasd flas dfla sdflas dfklasdr*/
int buffer_add(char *buffer, char *str_to_add);


/*================================================ str_tok.c ========================================*/

/* Sep askdgfag sdfa sdgkfasdj fjas dkfa kfhgas kdfhg asjhdgfg asjd ter */
void tokenize(data_of_program *data);

/* Cra glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajksdfng */
char *_strtok(char *line, char *delim);


/*================================================ execute.c ========================================*/

/* Execute a command with its entire path */
int execute(data_of_program *data);


/*================================================ builtins_list.c ================================*/

/* If glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkit */
int builtins_list(data_of_program *data);


/*================================================ find_in_path.c ========================================*/

/* Crfj asdf kalsdfhal hea dfkhasdfh iaudf es */
char **tokenize_path(data_of_program *data);

/* S glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkth */
int find_program(data_of_program *data);


/***************************************************** HELPERS FOR MEMORY MANAGEMENT ***************************/


/*================================================ helpers_free.c ========================================*/

/* Fr glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkes */
void free_array_of_pointers(char **directories);

/* Fr glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk loop */
void free_recurrent_data(data_of_program *data);

/* Fr glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkta */
void free_all_data(data_of_program *data);


/************************************************* BUILTINS ***************************************/


/*======================================== builtins_more.c ================================================*/

/*  glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkl */
int builtin_exit(data_of_program *data);

/* Ch glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajktory */
int builtin_cd(data_of_program *data);

/* se glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkory */
int set_work_directory(data_of_program *data, char *new_dir);

/* sho glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajktion */
int builtin_help(data_of_program *data);

/* s glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkias */
int builtin_alias(data_of_program *data);


/*================================================ builtins_env.c ========================================*/

/* Show glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk runs */
int builtin_env(data_of_program *data);

/* cr glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkonment */
int builtin_set_env(data_of_program *data);

/* d glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkment */
int builtin_unset_env(data_of_program *data);


/************************************** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT ***************************/


/*======================================== env_management.c ================================*/

/* Get glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkble */
char *env_get_key(char *name, data_of_program *data);

/* Over glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajkriable */
int env_set_key(char *key, char *value, data_of_program *data);

/* Re glksgefiagewada df asdjkf kjadfads fs dkas das kasdfaj konment */
int env_remove_key(char *key, data_of_program *data);

/* pr glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk ron */
void print_environ(data_of_program *data);


/**************************************** HELPERS FOR PRINTING ****************************************/


/*======================================== helpers_print.c ================================*/

/* Pr glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk tput */
int _print(char *string);

/* Pr glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk ror */
int _printe(char *string);

/* Pri glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk ror */
int _print_error(int errorcode, data_of_program *data);


/**************************************** HELPERS FOR STRINGS MANAGEMENT ***************************/


/*======================================== helpers_string.c =====================================*/

/* Co glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk ring */
int str_length(char *string);

/* Du glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk ng */
char *str_duplicate(char *string);

/* Co glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk ngs */
int str_compare(char *string1, char *string2, int number);

/* Co glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk ngs */
char *str_concat(char *string1, char *string2);

/*  glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk ng */
void str_reverse(char *string);


/*======================== helpers_numbers.c ================================*/

/* C glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk ing */
void long_to_string(long number, char *string, int base);

/* c glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk mber */
int _atoi(char *s);

/* co glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk ring */
int count_characters(char *string, char *character);


/*================================ alias_management.c ================================*/

/* p glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk as */
int print_alias(data_of_program *data, char *alias);

/* ge glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk me */
char *get_alias(data_of_program *data, char *alias);

/* s glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajke */
int set_alias(char *alias_string, data_of_program *data);


#endif /* S glksgefiagewada df asdjkf kjadfads fs dkas das kasdfajk */
