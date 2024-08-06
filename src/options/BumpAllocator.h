#pragma once

#include "logger.h"
#include <cstddef>
#include <cstring>
#include <malloc.h>
#include <stdio.h>
#include <sys/stat.h>

namespace Engine {
struct BumpAllocator {
  size_t capacity;
  size_t used;
  char *memory;
};
BumpAllocator make_bump_allocator(size_t size);
char *bump_alloc(BumpAllocator *bumpAllocator, size_t size);
long long get_timestamp(char *file);
bool file_exists(char *filePath);
long get_file_size(char *filePath);
char *read_file(char *filePath, int *fileSize, char *buffer);
char *read_file(char *filePath, int *fileSize, BumpAllocator *bumpAllocator);
void write_file(char *filePath, int size, char *buffer);
bool copy_file(char *fileName, char *outputName, char *buffer);
bool copy_file(char *fileName, char *outputName, BumpAllocator *bumpAllocator);

struct allocator {
  BumpAllocator allocator;
};
} // namespace Engine