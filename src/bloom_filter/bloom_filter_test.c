//
// Created by fourniem on 17/10/19.
//

#include "set.h"
#include "buffer.h"
#include <assert.h>


int main(){

    set_t *set =NULL;
    new_set(&set, 6);

    int a = 12;
    buffer_t buf = {
    	.data  = (char*) &a,
		.size = sizeof(int)
    };

    assert(set->m_contains(&buf, set)==0);
    assert(set->m_addItem(&buf, set) != 0);
    assert(set->m_contains(&buf, set) != 0);
    assert(set->m_addItem(&buf, set) == 0);
    

}
