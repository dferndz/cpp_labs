#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdlib.h>

size_t get_allocated();
void mm_init();
void *operator new(size_t size);
void *operator new[](size_t s);
void operator delete(void *) _NOEXCEPT;
void operator delete[](void *) _NOEXCEPT;

#endif