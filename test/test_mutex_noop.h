/******** DO NOT EDIT THIS FILE ********/
/* 
 * test_mutex_noop.h - structures and function declarations for unit tests
 * of mutex_noop functions.
 * 
 */  
#ifndef _TEST_MUTEX_NOOP_H
#define _TEST_MUTEX_NOOP_H
#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"

static MunitResult test_mu_new(const MunitParameter params[],
    void* fixture);
static MunitResult test_mu_enter(const MunitParameter params[],
    void* fixture);
static MunitResult test_mu_leave(const MunitParameter params[],
    void* fixture);

    
static MunitTest tests[] = {
    { "/test_mu_new", test_mu_new, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_mu_enter", test_mu_enter, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_mu_leave", test_mu_leave, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
};

static const MunitSuite suite = {
    "/test_mutex_noop", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE 
};    


#endif