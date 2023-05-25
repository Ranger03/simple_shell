#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* asd  askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd */
#include <unistd.h> /* asd  askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd */
#include <stdlib.h>
#include <string.h> /* asd  askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd */
#include <stddef.h>
#include <errno.h> /* asd  askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj sdf gsdfhaskd askdr */
#include <sys/types.h> /* asd  askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkdf gsdfj haskd askd */
#include <sys/wait.h> /* asd  askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkjsdf g haskd askd */
#include <sys/stat.h> /*asd  askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj sd gsd fgsdhaskd askd */
#include <signal.h> /*asd  askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkjsdfg sdfg  haskd askdt */
#include <fcntl.h> /*asd  askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd fgsdf gsdfs*/

/***************************************** MACROS ********************************************/

#include "macros.h" /*asd  askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdf*/

/*************************************** STRUCTURES *****************************************/

/**
 * struct info- ssd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfgta
 * asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdf
 * asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdf
 * asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdf
 * @program_name: tsd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfgble
 * @input_line: poisd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfgne
 * @command_name: posd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfghe user
 * @exec_counter: nusd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfgmands
 * @file_descriptor: filsd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfgcommands
 * @tokens: psd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfginput
 * @env: csd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfgn
 * @alias_list: arsd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfgases.
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
 * struct builtins - stasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfns
 * asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdf
 * asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdf
 * asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdf
 * @builtin: tasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfltin
 * @function: theasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdf builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;


/******************************************** MAIN FUNCTIONS ****************************************************/


/*==============================================  shell.c  ==================================================*/

/* asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm */
void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);

/* Make asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfpt*/
void sisifo(char *prompt, data_of_program *data);

/* Prin asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdf */
void handle_ctrl_c(int opr UNUSED);


/*===============================================  _getline.c  ===========================================*/

/* Readasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm ut*/
int _getline(data_of_program *data);

/* split asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmist */
int check_logic_ops(char *array_commands[], int i, char array_operators[]);


/*================================================== expansions.c ==========================================*/

/* exasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfms */
void expand_variables(data_of_program *data);

/* exasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmses */
void expand_alias(data_of_program *data);

/* appasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmthe buffer*/
int buffer_add(char *buffer, char *str_to_add);


/*=================================================== str_tok.c ================================================*/

/* Seasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm delimiter */
void tokenize(data_of_program *data);

/* Createsasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm of a string */
char *_strtok(char *line, char *delim);


/*================================================== execute.c ==================================================*/

/* Execute asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmire path */
int execute(data_of_program *data);


/*================================================ builtins_list.c ===========================================*/

/* asd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm executes it */
int builtins_list(data_of_program *data);


/*================================================== find_in_path.c ===========================================*/

/* Createasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmrectories */
char **tokenize_path(data_of_program *data);

/* Seasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmpath */
int find_program(data_of_program *data);


/************************************************* HELPERS FOR MEMORY MANAGEMENT ************************************************/


/*================================================== helpers_free.c ==================================================*/

/* Freasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmtories */
void free_array_of_pointers(char **directories);

/* Frasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmh loop */
void free_recurrent_data(data_of_program *data);

/* Fasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmf the data */
void free_all_data(data_of_program *data);


/******************************************************** BUILTINS ********************************************************/


/*===================================================== builtins_more.c ================================================*/

/* Closeasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmll */
int builtin_exit(data_of_program *data);

/* Chanasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmtory */
int builtin_cd(data_of_program *data);

/* setasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmory */
int set_work_directory(data_of_program *data, char *new_dir);

/* shasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmation */
int builtin_help(data_of_program *data);

/* sasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmow alias */
int builtin_alias(data_of_program *data);


/*======================================================== builtins_env.c ================================================*/

/* Shoasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmshell runs */
int builtin_env(data_of_program *data);

/* creaasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmenvironment */
int builtin_set_env(data_of_program *data);

/* delasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmnment */
int builtin_unset_env(data_of_program *data);


/****************************************** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT ******************************************/


/*======================================================= env_management.c =======================================================*/

/* Getasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmable */
char *env_get_key(char *name, data_of_program *data);

/* Overwrasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmnment variable */
int env_set_key(char *key, char *value, data_of_program *data);

/* Rasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmnment */
int env_remove_key(char *key, data_of_program *data);

/* priasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmron */
void print_environ(data_of_program *data);


/******************************************************** HELPERS FOR PRINTING ********************************************************/


/*======================================================== helpers_print.c ========================================================*/

/* Pasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmutput */
int _print(char *string);

/* Prinasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm error */
int _printe(char *string);

/* Pasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmrror */
int _print_error(int errorcode, data_of_program *data);


/****************************************************************** HELPERS FOR STRINGS MANAGEMENT *****************************************************/


/*=============================================================== helpers_string.c ========================================================*/

/* Counasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmtring */
int str_length(char *string);

/* Dasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfming */
char *str_duplicate(char *string);

/* Compasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm */
int str_compare(char *string1, char *string2, int number);

/* Coasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmings */
char *str_concat(char *string1, char *string2);

/* Reveasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm */
void str_reverse(char *string);


/*=========================================== helpers_numbers.c ===============================================================*/

/* Casasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmg */
void long_to_string(long number, char *string, int base);

/* casd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm number */
int _atoi(char *s);

/* coasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmin string */
int count_characters(char *string, char *character);


/*========================================================= alias_management.c ==================================================*/

/* pasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmas */
int print_alias(data_of_program *data, char *alias);

/* getasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm */
char *get_alias(data_of_program *data, char *alias);

/* set tasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfmme */
int set_alias(char *alias_string, data_of_program *data);


#endif /* Sasd askd fkjsadkjas dkfhkasdh kasdh fkajsdkjhasdfasdkj haskd askd sdfg sdfm */
