#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdlib.h>

enum status_t { EMPTY_MEMORY, ALLOCATED_MEMORY, INVALID_PTR };

status_t get_status();
void mm_init();
void *operator new(size_t size);
void *operator new[](size_t s);
void operator delete(void *) _NOEXCEPT;
void operator delete[](void *) _NOEXCEPT;

#endif