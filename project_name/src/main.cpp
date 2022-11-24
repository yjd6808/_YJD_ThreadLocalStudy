/*
 * 작성자: 윤정도
 * =====================
 *
 */

#pragma warning(push)
  #pragma warning(disable: 26495) // variable is uninitialized. Always initialize a member variable
  #include <benchmark/benchmark.h>
#pragma warning(pop)

static void test(benchmark::State& state)
{
  const int64_t max = state.range();

  for (auto _ : state)
  {
    for (int i = 0; i < max; i++)
      volatile int temp = rand();
  }
}

BENCHMARK(test)->RangeMultiplier(2)->Range(1, 1 << 10);
