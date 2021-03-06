/******** DO NOT EDIT THIS FILE ********/
#ifndef _SHOBJECT_NAME_H
#define _SHOBJECT_NAME_H

#define MAX_SHOBJ_NAME_SIZE 64
#define SHOBJ_NAME_FORMAT "/csc2035.%s.%s"  // "/csc2035.<user>.<label>"

/*
 * shobject_name(char* name_buf, const char* label)
 * 
 * Generates a name for a shared memory object in the format specified by 
 * SHOBJ_NAME_FORMAT using the given label for the label component. The user
 * component is the current user obtained from the program environment. 
 * If the user name cannot be obtained from the environment, then the name 
 * anon is used.
 * The name is written to the user-provided buffer of size MAX_SHOBJ_NAME_SIZE. 
 *
 * This is a utility function for consistent naming of shared memory
 * objects. Shared objects are created by ipc_new and sem_new, for example.
 *
 * Usage:
 *      char name_buf[MAX_SHOBJ_NAME_SIZE];
 *      shobject_name(name_buf, "app_label");   
 *                  // replace app_label with an application specific label 
 *                  // for your shared object. After execution of 
 *                  // shobject_name in this example, name_buf will be the
 *                  // string: "/csc2035.<user>.app_label" 
 *                  // where <user> is replaced by the current user
 *                  // see: SHOBJ_NAME_FORMAT
 *
 * See ipc_new in ipc.c and sem_new in sem_ipc_jobqueue.c for further examples
 * of how shobject_name is used.
 * 
 * Parameters:
 * name_buf - a non-null buffer of size MAX_SHOBJ_NAME_SIZE to write the name 
 *      to
 * label - the  application specific label for the shared object. If label is 
 *      NULL or empty string, the label "none" is used. The label is 
 *      truncated in the resulting string if it would result in a name string 
 *      longer than MAX_SHOBJ_NAME_SIZE - 1.
 *
 * Return:
 * There is no return value. If the function returns and name_buf is at 
 *      least size MAX_SHOBJ_NAME_SIZE, name_buf will contain a well-formed 
 *      string with terminating '\0' in the format specified by
 *      SHOBJ_NAME_FORMAT. The string will never be greater than length 
 *      MAX_SHOBJ_NAME_SIZE - 1. If the label parameter would result in a 
 *      string longer than length MAX_SHOBJ_NAME_SIZE - 1, then the 
 *      string is truncated to length MAX_SHOBJ_NAME_SIZE - 1 and the 
 *      characters of label that would exceed that length are discarded.
 * If user cannot be obtained from the environment <user> in the format is 
 *      replaced by "anon". If label is NULL or the empty string (""), "none" 
 *      is used for the label in the name string. For example, if the user 
 *      cannot be obtained from the environment and the label is NULL, the 
 *      name generated will be: "/csc2035.anon.none"
 * 
 *
 * Errors:
 * If name_buf is NULL, a memory error will occur and the calling process
 *      will terminate. It is the responsibility of the user of the function to 
 *      provide a non-null name_buf of size MAX_SHOBJ_NAME_SIZE. 
 *      If name_buf size is less than MAX_SHOBJ_NAME_SIZE, behaviour is
 *      undefined and the calling process may terminate. If name_buf size is 
 *      greater than MAX_SHOBJ_NAME_SIZE, no more than MAX_SHOBJ_NAME_SIZE
 *      bytes are written to name_buf including a terminating '\0' character.
 */
void shobject_name(char* name_buf, const char* label);

#endif