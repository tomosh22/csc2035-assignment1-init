/******** DO NOT EDIT THIS FILE ********/
/* 
 * test_ipc.h - structures and function declarations for unit tests
 * of ipc functions.
 * 
 */  
#ifndef _TEST_IPC_H
#define _TEST_IPC_H
#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"

static MunitResult test_ipc(const MunitParameter params[],
    void* fixture);
    
static MunitResult test_ipc_err(const MunitParameter params[],
    void* fixture);

static MunitTest tests[] = {
    { "/test_ipc", test_ipc, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_err", test_ipc_err, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
};

static const MunitSuite suite = {
    "/test_ipc", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE 
};    


#endif