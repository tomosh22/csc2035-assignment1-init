/******** DO NOT EDIT THIS FILE ********/
/* 
 * test_mutex_lockvar.h - structures and function declarations for unit tests
 * of mutex_lockvar functions.
 * 
 */  
#ifndef _TEST_MUTEX_LOCKVAR_H
#define _TEST_MUTEX_LOCKVAR_H
#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"

static void* test_setup(const MunitParameter params[], void* user_data);
static void test_tear_down(void* fixture);

static MunitResult test_mu_new(const MunitParameter params[],
    void* fixture);
static MunitResult test_mu_enter(const MunitParameter params[],
    void* fixture);
static MunitResult test_mu_leave(const MunitParameter params[],
    void* fixture);

    
static MunitTest tests[] = {
    { "/test_mu_new", test_mu_new, test_setup, test_tear_down,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_mu_enter", test_mu_enter, test_setup, test_tear_down,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_mu_leave", test_mu_leave, test_setup, test_tear_down,
        MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
};

static const MunitSuite suite = {
    "/test_mutex_lockvar", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE 
};    


#endif