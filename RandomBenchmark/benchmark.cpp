#include <benchmark/benchmark.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <random>

const unsigned seed = static_cast<unsigned>(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());

// OLD RAND
void old_rand(benchmark::State& state) {
  std::srand(seed);

  while (state.KeepRunning()) {
    std::rand();
  }
}

void old_rand_int_range(benchmark::State& state) {
  std::srand(seed);

  unsigned min = state.range(0);
  unsigned max = state.range(1);

  while (state.KeepRunning()) {
    (std::rand() % (max - min + 1)) + min;
  }
}

void old_rand_real_range(benchmark::State& state) {
  std::srand(seed);

  double min = state.range(0);
  double max = state.range(1);

  while (state.KeepRunning()) {
    min +
        static_cast<double>(std::rand()) /
            static_cast<double>(RAND_MAX / (max - min));
  }
}

template <class Gen>
void random_uniform_int_dist(benchmark::State& state) {
  Gen engine(seed);

  unsigned min = state.range(0);
  unsigned max = state.range(1);

  std::uniform_int_distribution<unsigned> dist(min, max);
  while (state.KeepRunning()) {
    dist(engine);
  }
}

template <class Gen>
void random_uniform_real_dist(benchmark::State& state) {
  Gen engine(seed);

  double min = state.range(0);
  double max = state.range(1);

  std::uniform_real_distribution<double> dist(min, max);
  while (state.KeepRunning()) {
    dist(engine);
  }
}

BENCHMARK(old_rand);
BENCHMARK(old_rand_int_range)->Args({1234, 12345678});
BENCHMARK(old_rand_real_range)->Args({1234, 12345678});

BENCHMARK_TEMPLATE(random_uniform_int_dist, std::minstd_rand0)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_int_dist, std::minstd_rand)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_int_dist, std::mt19937)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_int_dist, std::mt19937_64)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_int_dist, std::ranlux24_base)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_int_dist, std::ranlux48_base)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_int_dist, std::ranlux24)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_int_dist, std::ranlux48)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_int_dist, std::knuth_b)
    ->Args({1234, 12345678});

BENCHMARK_TEMPLATE(random_uniform_real_dist, std::minstd_rand0)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_real_dist, std::minstd_rand)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_real_dist, std::mt19937)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_real_dist, std::mt19937_64)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_real_dist, std::ranlux24_base)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_real_dist, std::ranlux48_base)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_real_dist, std::ranlux24)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_real_dist, std::ranlux48)
    ->Args({1234, 12345678});
BENCHMARK_TEMPLATE(random_uniform_real_dist, std::knuth_b)
    ->Args({1234, 12345678});

BENCHMARK_MAIN()