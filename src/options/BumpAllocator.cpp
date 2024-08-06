#include "BumpAllocator.h"

namespace Engine {

BumpAllocator make_bump_allocator(size_t size) {
  BumpAllocator ba = {};
  ba.memory = (char *)malloc(size);
  if (ba.memory) {
    ba.capacity = size;
    memset(ba.memory, 0, size);
  } else {
    EN_ERROR("Bump allocation failed");
  }
  ba.capacity = size;
  return ba;
}

char *bump_alloc(BumpAllocator *bumpAllocator, size_t size) {
  char *result = nullptr;

  size_t allignedSize =
      (size + 7) & ~7; // this makes sure the first 4 bits are 0
  if (bumpAllocator->used + allignedSize <= bumpAllocator->capacity) {
    result = bumpAllocator->memory + bumpAllocator->used;
    bumpAllocator->used += allignedSize;
  }
  return result;
}

// #########################################

// File IO

// #########################################

long long get_timestamp(char *file) {
  struct stat file_stat = {};
  stat(file, &file_stat);

  return file_stat.st_mtime;
}

bool file_exists(char *filePath) {
  auto file = fopen(filePath, "r");
  if (!file) {
    return false;
  }
  fclose(file);
  return true;
}

long get_file_size(char *filePath) {
  EN_ASSERT(filePath, "No filePath supplied");
  long fileSize = 0;
  auto file = fopen(filePath, "r");
  if (!file) {
    EN_ERROR("error in opening file", filePath);
    return 0;
  }
  fseek(file, 0, SEEK_END);
  fileSize = ftell(file);
  fseek(file, 0,
        SEEK_SET); // sets the file streams position back to the beginning
  fclose(file);
  return fileSize;
}

char *read_file(char *filePath, int *fileSize, char *buffer) {
  EN_ASSERT(filePath, "file Path is empty");
  EN_ASSERT(fileSize, "file Size is empty");
  EN_ASSERT(buffer, "buffer not initialized");

  *fileSize = 0;
  FILE *file = fopen(filePath, "rb");
  if (!file) {
    EN_ERROR("failed to open the file", filePath);
    return nullptr;
  }
  // file size
  fseek(file, 0, SEEK_END);
  *fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  memset(buffer, 0, *filePath + 1);
  fread(buffer, sizeof(char), *fileSize, file);
  fclose(file);
  return buffer;
}

char *read_file(char *filePath, int *fileSize, BumpAllocator *bumpAllocator) {
  char *file = nullptr;
  long fileSize2 = get_file_size(filePath);

  if (fileSize2) {
    char *buffer = bump_alloc(bumpAllocator, fileSize2 + 1);

    file = read_file(filePath, fileSize, buffer);
  }

  return file;
}

void write_file(char *filePath, int size, char *buffer) {
  EN_ASSERT(filePath, "file Path for writing is not given");
  EN_ASSERT(size, "size not provided for reading the file");
  EN_ASSERT(buffer, "buffer not provided");

  FILE *file = fopen(filePath, "w");

  if (!file) {
    EN_ERROR("error in opening the file");
  }

  fwrite(buffer, sizeof(char), size, file);
  fclose(file);
}

bool copy_file(char *fileName, char *outputName, char *buffer) {
  int fileSize = 0;
  char *data = read_file(fileName, &fileSize, buffer);

  FILE *outputFile = fopen(outputName, "wb");
  if (!outputFile) {
    EN_ERROR("error in opening the file to write the copy to");
    return false;
  }
  int result = fwrite(data, sizeof(char), fileSize, outputFile);
  if (!result) {
    EN_ERROR("error in writing the copy to the output file");
    return false;
  }
  fclose(outputFile);
  return true;
}

bool copy_file(char *fileName, char *outputName, BumpAllocator *bumpAllocator) {
  char *file = nullptr;
  long fileSize2 = get_file_size(fileName);

  if (fileSize2) {
    char *buffer = bump_alloc(
        bumpAllocator,
        fileSize2 +
            1); // 1 extra byte for the terminating character (null character)
    return copy_file(fileName, outputName, buffer);
  }
  return true;
}
} // namespace Engine