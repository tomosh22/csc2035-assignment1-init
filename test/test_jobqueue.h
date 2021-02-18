/******** DO NOT EDIT THIS FILE ********/
/* 
 * test_jobqueue.h - structures and function declarations for unit tests
 * of jobqueue functions.
 */  
#ifndef _TEST_JOBQUEUE_H
#define _TEST_JOBQUEUE_H
#include "munit.h"

static MunitResult test_jq_new_delete(const MunitParameter params[],
    void* fixture);
static MunitResult test_jq_capacity(const MunitParameter params[], void* fixture);
static MunitResult test_jq_is_full(const MunitParameter params[], void* fixture);
static MunitResult test_jq_is_empty(const MunitParameter params[], void* fixture);
static MunitResult test_jq_enqueue_dequeue(const MunitParameter params[], 
    void* fixture);
static MunitResult test_jq_peekhead(const MunitParameter params[], 
    void* fixture);
static MunitResult test_jq_peektail(const MunitParameter params[], 
    void* fixture);
static void* test_setup(const MunitParameter params[], void* user_data);
static void test_tear_down(void* fixture);

static MunitTest tests[] = {
    { "/test_jq_new_delete", test_jq_new_delete, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_jq_capacity", test_jq_capacity, test_setup, test_tear_down,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_jq_is_full", test_jq_is_full, test_setup, test_tear_down,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_jq_is_empty", test_jq_is_empty, test_setup, test_tear_down, 
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_jq_enqueue_dequeue", test_jq_enqueue_dequeue, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_jq_peekhead", test_jq_peekhead, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_jq_peektail", test_jq_peektail, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
};

static const MunitSuite suite = {
    "/test_jobqueue", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE 
};    


#endif