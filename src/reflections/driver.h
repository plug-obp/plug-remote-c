#ifndef GVE_DRIVER
#define GVE_DRIVER

#include "gve_adaptor.h"

struct status_s {
    char is_done;
    char is_verified;
};
typedef struct status_s status_t;
typedef int (*status_handler_t)(status_t in_status, void *opaque);

struct driver_s {
    mc_automaton_t m_automaton;
    void *m_opaque;
    status_handler_t m_status;
};
typedef struct  driver_s driver_t;

int run_analysis(driver_t *in_driver_params);

#endif //GVE_DRIVER