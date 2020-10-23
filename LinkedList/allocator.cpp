#include "allocator.hpp"
#include <assert.h>

#define MAGIC_HEADER 0xABABABAB

struct header_t {
  size_t magic;
};

static size_t allocated;

void mm_init() {
  allocated = 0;
}

size_t get_allocated() {
  return allocated;
}

void *get_payload(header_t* h) {
  return (void*)((size_t)h + sizeof(header_t));
}

header_t *get_header(void* ptr) {
  return (header_t*)(size_t(ptr) - sizeof(header_t));
}

void *operator new(size_t size) {
  header_t* header = (header_t*) malloc(size + sizeof(header_t));
  header->magic = MAGIC_HEADER;
  allocated++;
  return get_payload(header);
}
void *operator new[](size_t size) {
  header_t* header = (header_t*) malloc(size + sizeof(header_t));
  header->magic = MAGIC_HEADER;
  allocated++;
  return get_payload(header);
  
}
void operator delete(void *ptr) _NOEXCEPT {
  assert(ptr);
  if (ptr) {
    assert(get_header(ptr)->magic == MAGIC_HEADER);
    free(get_header(ptr));
    allocated--;
  }
}
void operator delete[](void *ptr) _NOEXCEPT {
  assert(ptr);
  if (ptr) {
    assert(get_header(ptr)->magic == MAGIC_HEADER);
    free(get_header(ptr));
    allocated--;
  }
}