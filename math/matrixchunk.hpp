#pragma once

#include <type_traits>
#include <cstring>

namespace Math {

   /*! Abstracts matrix memory access. Small matrices are allocated in 
    * stack and when the allocation size is greater than a threshold value, 
    * memory is allocated from heap.
    */
   template <size_t M, size_t N, class T, size_t MaxStackAllocSize = 32 * 32, class Enable = void>
   class MatrixChunk;

   enum ChunkLocation {
      Stack,
      Heap
   };

   template <size_t M, size_t N, class T, size_t MaxStackAllocSize>
   class MatrixChunk<M, N, T, MaxStackAllocSize, typename std::enable_if<M * N <= MaxStackAllocSize>::type> {
   public:

      static const ChunkLocation Location = Stack;

      T& operator [](const size_t& index) {
         return _data[index];
      }

      const T& operator [](const size_t& index) const {
         return _data[index];
      }

      operator T*() {
         return _data;
      }

      operator const T*() const {
         return _data;
      }

   private:
      T _data[M * N];
   };

   template <size_t M, size_t N, class T, size_t MaxStackAllocSize>
   class MatrixChunk<M, N, T, MaxStackAllocSize, typename std::enable_if<M * N >= MaxStackAllocSize + 1>::type> {
   public:

      static const ChunkLocation Location = Heap;

      MatrixChunk() : _data(new T[M * N]) {

      }

      MatrixChunk(MatrixChunk&& other) : _data(other._data) {
         other._data = nullptr;
      }

      MatrixChunk(const MatrixChunk& other) : _data(new T[M * N]) {
         memcpy(_data, other._data, sizeof(T) * M * N);
      }

      ~MatrixChunk() {
         delete[] _data;
      }

      T& operator [](const size_t& index) {
         return _data[index];
      }

      const T& operator [](const size_t& index) const {
         return _data[index];
      }

      operator T*() {
         return _data;
      }

      operator const T*() const {
         return _data;
      }

      MatrixChunk& operator =(const MatrixChunk& other) {
         if (this != &other)
            memcpy(_data, other._data, sizeof(T) * M * N);

         return *this;
      }

   private:
      T* _data;
   };
}
