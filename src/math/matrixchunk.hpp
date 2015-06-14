#pragma once

#include <type_traits>
#include <array>
#include <vector>
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
         return _data.at(index);
      }

      const T& operator [](const size_t& index) const {
         return _data.at(index);
      }

      operator T*() {
         return _data.data();
      }

      operator const T*() const {
         return _data.data();
      }

      auto begin() const -> decltype(std::declval<std::array<T, M * N>>().cbegin()) {
         return _data.cbegin();
      }

      auto end() const -> decltype(std::declval<std::array<T, M * N>>().cend()) {
         return _data.cend();
      }

   private:
      std::array<T, M * N> _data;
   };

   template <size_t M, size_t N, class T, size_t MaxStackAllocSize>
   class MatrixChunk<M, N, T, MaxStackAllocSize, typename std::enable_if<M * N >= MaxStackAllocSize + 1>::type> {
   public:

      static const ChunkLocation Location = Heap;

      MatrixChunk() : _data(M * N) {

      }

      T& operator [](const size_t& index) {
         return _data.at(index);
      }

      const T& operator [](const size_t& index) const {
         return _data.at(index);
      }

      operator T*() {
         return _data.data();
      }

      operator const T*() const {
         return _data.data();
      }

      auto begin() const -> decltype(std::declval<std::vector<T>>().cbegin()) {
         return _data.cbegin();
      }

      auto end() const -> decltype(std::declval<std::vector<T>>().cend()) {
         return _data.cend();
      }

   private:
      std::vector<T> _data;
   };
}
