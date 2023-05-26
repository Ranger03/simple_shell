#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* sadfl asd alsd asd fasdhf asdf asdf asd fasd */
#include <unistd.h> /* asdf asdh alsd falsd asd fasdf asdf alsdf alsdf as*/
#include <stdlib.h>
#include <string.h> /* adsa fasldasl dfas ldf asdf asdf asdf asdf a */
#include <stddef.h>
#include <errno.h> /* sadhf asdf asd fasd fas dfasd fasd fasd fasdf asdf a */
#include <sys/types.h> /* asd hflasd falsdf alsd flasd fasd falsdf asldfasd fas */
#include <sys/wait.h> /* askdfakls dfa sldf asd falsdfalsd fad asd fas dfasd  */
#include <sys/stat.h> /* asd fhasdflh asdf asd fasd fjasd falsdfa sdfalksdf alsd */
#include <signal.h> /* asdh fhasd fasd lfasd falsd fa sdf asd falskdfa sdfa lskdfasd */
#include <fcntl.h> /* sadlkhjf asd fasd fasl dfalsdkfha lsdf asldfasdf lasdf alsdf lasd*/

/*************************************************************** MACROS ******************************************************************/

#include "macros.h" /* hasdfhas dfa dfalsdk fasdk fas dlfas dfa lsdfha sd */

/************************************************************* STRUCTURES ***************************************************************/

/**
 * struct info- asdhfj as dfasd fas dfa sdfkasdf asd
 * @program_name: sda fhasd fas dfasdfa sdf asdflasdf asdfa asdf asdf 
 * @input_line: asdhfas dfasdf asdfasd fas dfas dfaksdfas dfakdf askd
 * @command_name: sahdkf sdf asdlf asd fas dfalsdf alsdf alsdf alsdf a
 * @exec_counter: sdjhkfak ksdfh asdf alsdfa sdf asdf asdf asd fasd f
 * @file_descriptor: ashdkf asd flasd flasdf lasdf lasdf alsdf asd asdfa
 * @tokens: ashdkkfk asd fas dflasdfashdf asdfhasd fas dflasd fasd flaksd 
 * @env: asdkjfh asdhfaskdhfkasd fas dfas dfas dfa sdf as daskdf asd fa dsf
 * @alias_list: ashdf asdfhl asd fasd flaskd flaksdf alsdf alsd fads lfasl
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
 * struct builtins - ashdl fhasdf alskdf alskdf alksdfh alsdf lasdf
 * @builtin: ashkdlf asdf lashdlf ajsdl fhaslkdf lasdhf alsdflaksd
 * @function: askdhf a sd falsdf alksdfla sdfa lsdfa lsdfals dfasd 
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;


/*************************************** MAIN FUNCTIONS ***************************************/


/*========================================  shell.c  ========================================*/

/* askdhjf asdhf la sdfalsk dfals df alsdfa */
void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);

/* ashdfl asdf asdflaskdf alksdf asdf aklsdf kasd */
void sisifo(char *prompt, data_of_program *data);

/* as dafsdfals dfhas dfalskd fasdfla sdfa lda kfasjdf a */
void handle_ctrl_c(int opr UNUSED);


/*=======================================  _getline.c  =======================================*/

/* aksdf asdf alsdfaslk dfaslkd falskdfasdl fa */
int _getline(data_of_program *data);

/* asjdf hfasdh asdfh ajkshdf aksjdalsdfalksdf as */
int check_logic_ops(char *arry_coms[], int i, char arry_ops[]);


/*======================================= expansions.c ======================================*/

/* sadhfak as dfkasdflas df asdf asdf alksdf asdf */
void expand_variables(data_of_program *data);

/* sadlkf asdfl aks dfalsdf lasdfasdfla sdfalsdfasd f */
void expand_alias(data_of_program *data);

/* asdsahf sdfalksd falsdf alsdf alsdf asdflasdf asd las */
int buffer_add(char *buffer, char *str_to_add);


/*======================================== str_tok.c ========================================*/

/* asd ashdfa sk asdfa sdfas dfalsdf asdfalsdfa alskdf */
void tokenize(data_of_program *data);

/* Crefgads fakdfaksdf asdf aksdf kasd ing */
char *_strtok(char *line, char *delim);


/*======================================== execute.c ================================*/

/* ExecCrefgads fakdfaksdf asdf aksdf kasd ing path */
int execute(data_of_program *data);


/*======================================== builtins_list.c ========================*/

/* IfCrefgads fakdfaksdf asdf aksdf kasd ings it */
int builtins_list(data_of_program *data);


/*======================================== find_in_path.c ================================*/

/* CrCref gads fakdfaksdf asdf aksdf kasd ing ctories */
char **tokenize_path(data_of_program *data);

/* SearCref gads fakdfaksdf asdf aksdf kasd ing ctori th */
int find_program(data_of_program *data);


/*************************** HELPERS FOR MEMORY MANAGEMENT ***************************/


/*================================ helpers_free.c ================================*/

/* FrCref gads fakdfaksdf asdf aksdf kasd ing ctori es */
void free_array_of_pointers(char **directories);

/* FreCref gads fakdfaksdf asdf aksdf kasd ing ctori oop */
void free_recurrent_data(data_of_program *data);

/* FreCref gads fakdfaksdf asdf aksdf kasd ing ctori ata */
void free_all_data(data_of_program *data);


/****************************************** BUILTINS **************************************************/


/*==================================== builtins_more.c ============================================*/

/* ClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll */
int builtin_exit(data_of_program *data);

/* CreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ory */
int builtin_cd(data_of_program *data);

/* sereCref gads fakdfaksdf asdf aksdf kasd ing ctori ary */
int set_work_directory(data_of_program *data, char *new_dir);

/* shreCref gads fakdfaksdf asdf aksdf kasd ing ctori a tion */
int builtin_help(data_of_program *data);

/* sereCref gads fakdfaksdf asdf aksdf kasd ing ctori a ias */
int builtin_alias(data_of_program *data);


/*======================================== builtins_env.c ================================================*/

/* ShoreCref gads fakdfaksdf asdf aksdf kasd ing ctori a runs */
int builtin_env(data_of_program *data);

/* creClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ronment */
int builtin_set_env(data_of_program *data);

/* deClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ment */
int builtin_unset_env(data_of_program *data);


/*********************************** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT **************************/


/*======================================== env_management.c ========================================*/

/* GetsClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll iable */
char *env_get_key(char *name, data_of_program *data);

/* OverClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll iable */
int env_set_key(char *key, char *value, data_of_program *data);

/* RemClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ment */
int env_remove_key(char *key, data_of_program *data);

/* prClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll viron */
void print_environ(data_of_program *data);


/************************************** HELPERS FOR PRINTING **************************************/


/*======================================== helpers_print.c ========================================*/

/* PriClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll r output */
int _print(char *string);

/* PrClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll error */
int _printe(char *string);

/* PriClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ror */
int _print_error(int errorcode, data_of_program *data);


/************************************** HELPERS FOR STRINGS MANAGEMENT ***************************/


/*======================================== helpers_string.c ================================*/

/* CoClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ring */
int str_length(char *string);

/* DupClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll g */
char *str_duplicate(char *string);

/* CClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll gs */
int str_compare(char *string1, char *string2, int number);

/* CClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ngs */
char *str_concat(char *string1, char *string2);

/* ReClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ng */
void str_reverse(char *string);


/*======================================== helpers_numbers.c =======================================*/

/* CClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ng */
void long_to_string(long number, char *string, int base);

/* conCClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ng mber */
int _atoi(char *s);

/* coCClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ng ring */
int count_characters(char *string, char *character);


/*======================================== alias_management.c =======================================*/

/* prCClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ng ias */
int print_alias(data_of_program *data, char *alias);

/* geCClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ng e */
char *get_alias(data_of_program *data, char *alias);

/* sCClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ngame */
int set_alias(char *alias_string, data_of_program *data);


#endif /* CClreCref gads fakdfaksdf asdf aksdf kasd ing ctori a ll ng */
