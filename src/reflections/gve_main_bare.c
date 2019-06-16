#include "stddef.h"
#include "language_module/gve_adaptor.h"
#include "driver.h"

//dans le main
int status_function(status_t in_status, void *opaque) {
    int *data= (int*)opaque;
    if (in_status.is_done == 1) *data = 1;
    return 0;
}

char ini0[2] = {1, 2};
char ini1[2] = {3, 4};


int main() {
    int is_done = 0;
    
    obp2_language_runtime *runtime = obp2_create_runtime();

    driver_t drv = {
            .m_gve_context = gve_create_context(runtime),
            .m_opaque = &is_done,
            .m_status =  status_function
    };

    run_analysis(&drv);

    //do not return, we do not have an OS to return to
    return 0;
}