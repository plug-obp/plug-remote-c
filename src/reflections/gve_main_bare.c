#include "gve_adaptor.h"
#include "driver.h"

//dans le main
int status_function(status_t in_status, void *opaque) {
    int *data= (int*)opaque;
    if (in_status.is_done == 1) *data = 1;
    return 0;
}

char ini0[2] = {1, 2};
char ini1[2] = {3, 4};

//dans le binding vers le langage
int get_initial(void *opaque, char **out_target, int *io_target_size, char *out_has_next) {
    return 1;
}
int get_next(void *opaque, char **in_source, int in_source_size, char **out_target, int *io_target_size, char *out_has_next) {
    return 1;
}

int main() {
    int is_done = 0;
    driver_t drv = {
            .m_automaton = {
                .m_opaque = 0,
                .m_initial_handler = get_initial,
                .m_next_handler = get_next
            },
            .m_opaque = &is_done,
            .m_status =  status_function
    };

    run_analysis(&drv);

    //do not return, we do not have an OS to return to
    while (1) {}
    return 0;
}