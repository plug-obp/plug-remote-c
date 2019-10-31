//
// Created by fourniem on 17/10/19.
//

#include "set.h"
#include "buffer.h"

int main(){

    set_t *set =NULL;
    new_set(&set, 6);

    int a = 12;
    buffer_t buf = {
    	.data  = (char*) &a,
		.size = sizeof(int)
    };

    set->m_addItem(&buf, set);

    set->m_contains(&buf, set);

    

}
