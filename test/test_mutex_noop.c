/******** DO NOT EDIT THIS FILE ********/
#include "../mutex_noop.h"
#include "test_mutex_noop.h"
#include "procs4tests.h"

int main(int argc, char** argv) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

static MunitResult test_mu_new(const MunitParameter params[], 
    void* fixture) {
    test_procs_t* tp = new_test_procs();

    mutex_t* min = mu_new(tp->pin);
    mutex_t* mni = mu_new(tp->pni);
    
    assert_not_null(mni);
    mu_delete(mni);
    
    assert_not_null(min);
    mu_delete(min);
    
    delete_test_procs(tp);

    return MUNIT_OK;
}

    
static MunitResult test_mu_enter(const MunitParameter params[], 
    void* fixture) {
    return MUNIT_OK;
}

static MunitResult test_mu_leave(const MunitParameter params[], 
    void* fixture) {
    return MUNIT_OK;
}
