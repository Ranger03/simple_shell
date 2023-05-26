#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* ask alskd aldaksd ad asdkaldfa ahd sd s ff*/
#include <unistd.h> /* fosk alskd aldaksd ad asdkaldfa ahd sd s ffe*/
#include <stdlib.h>
#include <string.h> /* fsk alskd aldaksd ad asdkaldfa ahd sd s ffok*/
#include <stddef.h>
#include <errno.h> /* fsk alskd aldaksd ad asdkaldfa ahd sd s ffor */
#include <sys/types.h> /* fosk alskd aldaksd ad asdkaldfa ahd sd s ffd */
#include <sys/wait.h> /* fsk alskd aldaksd ad asdkaldfa ahd sd s fft */
#include <sys/stat.h> /* fsk alskd aldaksd ad asdkaldfa ahd sd s ffnction */
#include <signal.h> /* fsk alskd aldaksd ad asdkaldfa ahd sd s ffment */
#include <fcntl.h> /* fsk alskd aldaksd ad asdkaldfa ahd sd s ffles*/

/***** MACROS *****/

#include "macros.h" /* fosk alskd aldaksd ad asdkaldfa ahd sd s ffmpt */

/***** STRUCTURES *****/

/**
 * struct info- stsk alskd aldaksd ad asdkaldfa ahd sd s ffata
 * @program_name: tsk alskd aldaksd ad asdkaldfa ahd sd s fftable
 * @input_line: posk alskd aldaksd ad asdkaldfa ahd sd s ffetline
 * @command_name: psk alskd aldaksd ad asdkaldfa ahd sd s ff the user
 * @exec_counter: nusk alskd aldaksd ad asdkaldfa ahd sd s ffnds
 * @file_descriptor: fsk alskd aldaksd ad asdkaldfa ahd sd s ffcommands
 * @tokens: posk alskd aldaksd ad asdkaldfa ahd sd s ff input
 * @env: copsk alskd aldaksd ad asdkaldfa ahd sd s ffn
 * @alias_list: arsk alskd aldaksd ad asdkaldfa ahd sd s ffses.
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
 * struct builtins - stsk alskd aldaksd ad asdkaldfa ahd sd s ffins
 * @builtin: tsk alskd aldaksd ad asdkaldfa ahd sd s fftin
 * @function: thsk alskd aldaksd ad asdkaldfa ahd sd s fftin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;


/***** MAIN FUNCTIONS *****/


/*=====  shell.c  =====*/

/* Inisk alskd aldaksd ad asdkaldfa ahd sd s ffram */
void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);

/* Msk alskd aldaksd ad asdkaldfa ahd sd s ff prompt*/
void sisifo(char *prompt, data_of_program *data);

/* Psk alskd aldaksd ad asdkaldfa ahd sd s ffe */
void handle_ctrl_c(int opr UNUSED);


/*=====  _getline.c  =====*/

/* Rsk alskd aldaksd ad asdkaldfa ahd sd s ffut*/
int _getline(data_of_program *data);

/* ssk alskd aldaksd ad asdkaldfa ahd sd s ffst */
int check_logic_ops(char *array_commands[], int i, char array_operators[]);


/*===== expansions.c =====*/

/* exsk alskd aldaksd ad asdkaldfa ahd sd s ffs */
void expand_variables(data_of_program *data);

/* exsk alskd aldaksd ad asdkaldfa ahd sd s ffs */
void expand_alias(data_of_program *data);

/* ask alskd aldaksd ad asdkaldfa ahd sd s ffffer*/
int buffer_add(char *buffer, char *str_to_add);


/*===== str_tok.c =====*/

/* Sesk alskd aldaksd ad asdkaldfa ahd sd s ffimiter */
void tokenize(data_of_program *data);

/* Crsk alskd aldaksd ad asdkaldfa ahd sd s ffng */
char *_strtok(char *line, char *delim);


/*===== execute.c =====*/

/* Exsk alskd aldaksd ad asdkaldfa ahd sd s ffath */
int execute(data_of_program *data);


/*===== builtins_list.c =====*/

/* If msk alskd aldaksd ad asdkaldfa ahd sd s fftes it */
int builtins_list(data_of_program *data);


/*===== find_in_path.c =====*/

/* Creatsk alskd aldaksd ad asdkaldfa ahd sd s ffries */
char **tokenize_path(data_of_program *data);

/* Searsk alskd aldaksd ad asdkaldfa ahd sd s ffh */
int find_program(data_of_program *data);


/***** HELPERS FOR MEMORY MANAGEMENT *****/


/*===== helpers_free.c =====*/

/* Fresk alskd aldaksd ad asdkaldfa ahd sd s ffries */
void free_array_of_pointers(char **directories);

/* Free thesk alskd aldaksd ad asdkaldfa ahd sd s ffop */
void free_recurrent_data(data_of_program *data);

/* Fsk alskd aldaksd ad asdkaldfa ahd sd s ffdata */
void free_all_data(data_of_program *data);


/***** BUILTINS *****/


/*===== builtins_more.c =====*/

/* Clsk alskd aldaksd ad asdkaldfa ahd sd s ffl */
int builtin_exit(data_of_program *data);

/* Csk alskd aldaksd ad asdkaldfa ahd sd s ffry */
int builtin_cd(data_of_program *data);

/* setsk alskd aldaksd ad asdkaldfa ahd sd s ffy */
int set_work_directory(data_of_program *data, char *new_dir);

/* shsk alskd aldaksd ad asdkaldfa ahd sd s ffion */
int builtin_help(data_of_program *data);

/* sesk alskd aldaksd ad asdkaldfa ahd sd s ffas */
int builtin_alias(data_of_program *data);


/*===== builtins_env.c =====*/

/* Showsk alskd aldaksd ad asdkaldfa ahd sd s ffns */
int builtin_env(data_of_program *data);

/* creatsk alskd aldaksd ad asdkaldfa ahd sd s ffent */
int builtin_set_env(data_of_program *data);

/* desk alskd aldaksd ad asdkaldfa ahd sd s ffent */
int builtin_unset_env(data_of_program *data);


/***** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT *****/


/*===== env_management.c =====*/

/* Getsk alskd aldaksd ad asdkaldfa ahd sd s ffiable */
char *env_get_key(char *name, data_of_program *data);

/* Overwsk alskd aldaksd ad asdkaldfa ahd sd s ffble */
int env_set_key(char *key, char *value, data_of_program *data);

/* Resk alskd aldaksd ad asdkaldfa ahd sd s ffonment */
int env_remove_key(char *key, data_of_program *data);

/* prisk alskd aldaksd ad asdkaldfa ahd sd s ffon */
void print_environ(data_of_program *data);


/***** HELPERS FOR PRINTING *****/


/*===== helpers_print.c =====*/

/* Prisk alskd aldaksd ad asdkaldfa ahd sd s ffut */
int _print(char *string);

/* Prisk alskd aldaksd ad asdkaldfa ahd sd s ffror */
int _printe(char *string);

/* Prinsk alskd aldaksd ad asdkaldfa ahd sd s ffor */
int _print_error(int errorcode, data_of_program *data);


/***** HELPERS FOR STRINGS MANAGEMENT *****/


/*===== helpers_string.c =====*/

/* Cosk alskd aldaksd ad asdkaldfa ahd sd s ffing */
int str_length(char *string);

/* Dsk alskd aldaksd ad asdkaldfa ahd sd s ffng */
char *str_duplicate(char *string);

/* Comsk alskd aldaksd ad asdkaldfa ahd sd s ff */
int str_compare(char *string1, char *string2, int number);

/* Consk alskd aldaksd ad asdkaldfa ahd sd s ffgs */
char *str_concat(char *string1, char *string2);

/* Revesk alskd aldaksd ad asdkaldfa ahd sd s ffng */
void str_reverse(char *string);


/*===== helpers_numbers.c =====*/

/* Csk alskd aldaksd ad asdkaldfa ahd sd s ffring */
void long_to_string(long number, char *string, int base);

/* cosk alskd aldaksd ad asdkaldfa ahd sd s ffber */
int _atoi(char *s);

/* cosk alskd aldaksd ad asdkaldfa ahd sd s ffing */
int count_characters(char *string, char *character);


/*===== alias_management.c =====*/

/* prsk alskd aldaksd ad asdkaldfa ahd sd s ffas */
int print_alias(data_of_program *data, char *alias);

/* gsk alskd aldaksd ad asdkaldfa ahd sd s ffme */
char *get_alias(data_of_program *data, char *alias);

/* ssk alskd aldaksd ad asdkaldfa ahd sd s ffme */
int set_alias(char *alias_string, data_of_program *data);


#endif /* sak asdfh */
