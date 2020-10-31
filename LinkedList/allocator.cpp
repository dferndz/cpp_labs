#include "allocator.hpp"
#include <assert.h>

#define MAGIC_HEADER 0xABABABAB

struct header_t {
  size_t magic;
};

static status_t status;
static size_t allocated;

void mm_init() {
  allocated = 0;
  status = EMPTY_MEMORY;
}

status_t get_status() {
  return status;
}

void *get_payload(header_t* h) {
  return (void*)((size_t)h + sizeof(header_t));
}

header_t *get_header(void* ptr) {
  return (header_t*)(size_t(ptr) - sizeof(header_t));
}

static void* allocate(size_t size) {
  header_t* header = (header_t*) malloc(size + sizeof(header_t));
  header->magic = MAGIC_HEADER;
  ++allocated;
  if (status != INVALID_PTR)
    status = ALLOCATED_MEMORY;
  return get_payload(header);
}

static void deallocate(void* ptr) {
  if (ptr) {
    if (get_header(ptr)->magic == MAGIC_HEADER) {
      free(get_header(ptr));
      if (--allocated == 0) {
        if (status != INVALID_PTR)
          status = EMPTY_MEMORY;
      }
      return;
    }
  }
  status = INVALID_PTR;
}

void *operator new(size_t size) {
  return allocate(size);
}
void *operator new[](size_t size) {
  return allocate(size);
}
void operator delete(void *ptr) _NOEXCEPT {
  deallocate(ptr);
}
void operator delete[](void *ptr) _NOEXCEPT {
  deallocate(ptr);
}