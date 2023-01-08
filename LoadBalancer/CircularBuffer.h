#ifndef CIR_BUFF
#include "Data.h"

circular_buffer* create_buffer();
void cb_free(circular_buffer* cb);
void cb_push(circular_buffer* cb, DataClient data);
DataClient cb_pop(circular_buffer* cb);
void  printBuffer(circular_buffer* buffer);

#endif

