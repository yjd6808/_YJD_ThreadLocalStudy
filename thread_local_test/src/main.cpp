/*
 * 작성자: 윤정도
 * =====================
 *
 */

#pragma warning(push)
  #pragma warning(disable: 26495) // variable is uninitialized. Always initialize a member variable
  #include <benchmark/benchmark.h>
#pragma warning(pop)

#include <iostream>
#include <thread>

constexpr int cache_line_size = 64;   // 내 컴퓨터 캐쉬 라인 크기
constexpr int min_thread_count = 2;   // 테스트 최소 쓰레드 수
constexpr int max_thread_count = 16;  // 테스트 최대 쓰레드 수
constexpr int max_loop = 500'000'000;

alignas(cache_line_size) thread_local char val1;                          // 쓰레드 로컬
alignas(cache_line_size) char val2[max_thread_count];                     // 모두 동일한 캐쉬라인
alignas(cache_line_size) char val3[max_thread_count * cache_line_size];   // 모두 다른 캐쉬라인

static void BM_thread_local(benchmark::State& state)
{
  const int thread_idx = state.thread_index();

  for (auto _ : state)
    for (uint64_t i = 0; i < max_loop; i++)
      benchmark::DoNotOptimize(++val1);
}

static void BM_same_cache_line(benchmark::State& state)
{
  const int thread_idx = state.thread_index();

  for (auto _ : state)
    for (uint64_t i = 0; i < max_loop; i++)
      benchmark::DoNotOptimize(++val2[thread_idx]);
}

static void BM_different_cache_line(benchmark::State& state)
{
  const int thread_idx = state.thread_index();

  for (auto _ : state)
    for (uint64_t i = 0; i < max_loop; i++)
      benchmark::DoNotOptimize(++val3[thread_idx * cache_line_size]);
}


BENCHMARK(BM_thread_local)
->Iterations(1)
->Unit(benchmark::kMillisecond)
->ThreadRange(min_thread_count, max_thread_count);

BENCHMARK(BM_same_cache_line)
->Iterations(1)
->Unit(benchmark::kMillisecond)
->ThreadRange(min_thread_count, max_thread_count);

BENCHMARK(BM_different_cache_line)
->Iterations(1)
->Unit(benchmark::kMillisecond)
->ThreadRange(min_thread_count, max_thread_count);
