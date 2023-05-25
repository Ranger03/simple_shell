#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /*  dfasd f asdf f*/
#include <unistd.h> /* fs dfasdf asd f asd e*/
#include <stdlib.h>
#include <string.h> /* f asdf asd asdk*/
#include <stddef.h>
#include <errno.h> /*a sdfasdf asd asd asdf r */
#include <sys/types.h> /* sdf asd asdf d */
#include <sys/wait.h> /* wag s asdh a */
#include <sys/stat.h> /* stat fun... sdaf sdf a */
#include <signal.h> /* signal managenemt sdfga  */
#include <fcntl.h> /* files open dsa wae  */

/******************* MACROS *************************/

#include "macros.h" /* help message */

/******************** STRUCTURES ********************/

/**
 * struct info -  asdfa asdfashfa   sdasas fasd d
 * @program_name: name of executeable sdfasd asd 
 * @input_line: ptr to the input sadh adf a _getline
 * @command_name: ptr to first comend type
 * @exec_counter: num of exe
 * @file_descriptor: file descriptor f sadfa fa dsa;
 * @tokens: ptr ary of tojen
 * @env: fdsa fa fasdf adf 
 * @alias_list: fa sdfa sdf sf
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
 * struct builtins - sdsf agskdfal sdfa sldfg asd
 * @builtin: sdf asdf halshd fhawpefh awhef pawe fapwefapdhfwae faphdf ae
 * @function: thesdfase ahe apfepsof awehzd fasdo fa df as;df asdfhefselhfs ldhf sldfsoefs df sf
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;


/************************** MAIN FUNCTIONS ************************/


/*===========================  shell.c  ============================*/

/* sdf asdhfa;sdf; asdhfowsa,vh dsf asdf asd fha sdfhdashf ahsdf hasd fm */
void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);

/* Mfsdhasfasasdgfa gsfsyegsdhzfasd ga sdgfas dfasd f dfas df asgdt*/
void sisifo(char *prompt, data_of_program *data);

/* sdafgasd fa sgdf asdgfa sdgfa sdf asgdfasdfasdfaigsef  */
void handle_ctrl_c(int opr UNUSED);


/*=============================  _getline.c  ============================================*/

/* asdfha sdfap sdfape fesf as fa faf as afa sf as f*/
int _getline(data_of_program *data);

/* asdfahfas fhas dfa sdafsdf asdf asdf as df asdf asd f asdf asd fas df */
int check_logic_ops(char *array_commands[], int i, char array_operators[]);


/*================================== expansions.c ==========================================*/

/* asdgfa gdsgf agsdf asdfasdfasdkfasd fasd fasdf asdfkasdf asdkf asdf asdfk asd */
void expand_variables(data_of_program *data);

/* sdfasdfa sdhfasd fas df asdf asd fasd fasdf asl  dfas df asdfs */
void expand_alias(data_of_program *data);

/* sdfsafsdfg asdfa sgdf */
int buffer_add(char *buffer, char *str_to_add);


/*======================================= str_tok.c ===========================================*/

/* sdfg asdf agskdfgaksdfgkasdf kasdfjas dgfasd fk asdf askdf asdfas dfkasd */
void tokenize(data_of_program *data);

/* sdfasdfkasdafaksd fhaskdf kasdfkasdhfkas df askdfaksdf aksdf askf as */
char *_strtok(char *line, char *delim);


/*========================================= execute.c ==========================================*/

/* asdfgaksdfgaks asd faksd falsdf asldf alsd falsd fasld fas dfas dflas dfas f */
int execute(data_of_program *data);


/*======================================== builtins_list.c ====================================*/

/* dsfjg sdfgsdf gsj df gsd sdfgs dffgsdf gsdfg df  */
int builtins_list(data_of_program *data);


/*=========================================== find_in_path.c =======================================*/

/* asdfha sdf asldfalsd falskdf asdf asdf asldasd falsk dfad fsd */
char **tokenize_path(data_of_program *data);

/* asdhf asldfalsdf as dfas dfalsdf asdfa lsdf asdf alsdf as */
int find_program(data_of_program *data);


/********************************* HELPERS FOR MEMORY MANAGEMENT *****************************************/


/*====================================== helpers_free.c ================================================*/

/* sdkjaf sadf kd faskdl flasd falsdflasdf asd fas daaldas a f */
void free_array_of_pointers(char **directories);

/* asdfasd a  afas dfasd f sdadfasdf asdf asdfasdf aas d fa */
void free_recurrent_data(data_of_program *data);

/* sadf as ds fsal fasd fasl dfasd fasd as dfas sdaa */
void free_all_data(data_of_program *data);


/******************************************** BUILTINS ***********************************************/


/*======================================== builtins_more.c =================================*/

/* sadf as al sdf asd fasd fasdf asdf asdf asdf asd fasd fasd */
int builtin_exit(data_of_program *data);

/* asd fasdfas df asdfh ad fasdfasdfasdfasdfasd */
int builtin_cd(data_of_program *data);

/* sdf as fas dfasdfasd fas fda sdf asdfa sdfasd  */
int set_work_directory(data_of_program *data, char *new_dir);

/*  sdf asdfasd as df asdfa;sdfasdf;adfas df sd af asdasd a */
int builtin_help(data_of_program *data);

/* a sdf asdf asd fas df asdf asdf asd fas fasd fasd fd */
int builtin_alias(data_of_program *data);


/*======================================== builtins_env.c ========================================*/

/* asdf s */
int builtin_env(data_of_program *data);

/* sadf  */
int builtin_set_env(data_of_program *data);

/* sdf asdt */
int builtin_unset_env(data_of_program *data);


/****************************** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT ****************************/


/*======================================== env_management.c ========================================*/

/* dfsg sdf gsd f gs */
char *env_get_key(char *name, data_of_program *data);

/* sd fgsdf gsd f */
int env_set_key(char *key, char *value, data_of_program *data);

/*  sdfg sdf sdf gsdfg */
int env_remove_key(char *key, data_of_program *data);

/* s dfgsdf gsdf gdf */
void print_environ(data_of_program *data);


/************** HELPERS FOR PRINTING **************/


/*======================================================== helpers_print.c ================*/

/* sdfg sdf gsdf gsdfgsddfg sd gsdfg dsfg gsdf gsdfgfgsdfgsdfgsdfgsd */
int _print(char *string);

/*  fgsdfg sdfg sdfg sdfgdf gsdfgs dfg sdfg sdf gdsf gsg sdf g sdfr */
int _printe(char *string);

/* df g sdfg sdfg sdfg sdfsgdsgsdg sdf gsd fgsdfg sdf gsdfg sdfgr */
int _print_error(int errorcode, data_of_program *data);


/********************************** HELPERS FOR STRINGS MANAGEMENT **********************************/


/*=========================================== helpers_string.c =============================*/

/* sdf gd gsdfg */
int str_length(char *string);

/*  gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdfsdf df gsd fgsd fgg */
char *str_duplicate(char *string);

/* gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdf gsd fgsd fgg */
int str_compare(char *string1, char *string2, int number);

/* gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdf gsd fgsd fgg */
char *str_concat(char *string1, char *string2);

/* gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdf gsd fgsd fgg */
void str_reverse(char *string);


/*======== helpers_numbers.c ========*/

/* gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdf gsd fgsd fgg */
void long_to_string(long number, char *string, int base);

/* gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdf gsd fgsd fgg */
int _atoi(char *s);

/* gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdf gsd fgsd fgg */
int count_characters(char *string, char *character);


/*======== alias_management.c ========*/

/* gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdf gsd fgsd fgg */
int print_alias(data_of_program *data, char *alias);

/* gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdf gsd fgsd fgg */
char *get_alias(data_of_program *data, char *alias);

/* gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdf gsd fgsd fgge */
int set_alias(char *alias_string, data_of_program *data);


#endif /* SHELL_H gdfsgsdfgsdf gsdfg f gs df gsdfg sdfg sdfg dsdf gsd fgsd fgg */
