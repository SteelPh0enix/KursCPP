# Benchmark silników generowania liczb losowych

Wymaga [CMake](https://cmake.org) w wersji >=3.0 oraz zbudowanej [biblioteki do mikrobenchmarków od Google](https://github.com/google/benchmark).

Żeby zbudować i uruchomić benchmark, należy wykonać następujące polecenia (``cmake`` można zastąpić ``cmake-gui`` bez argumentów)

Windows (MinGW):

```ps
cmake -G"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DGOOGLE_BENCHMARK_INCLUDE_DIR="Ścieżka do folderu /include biblioteki" -DGOOGLE_BENCHMARK_LIB_DIR="Ścieżka do folderu ze skompilowaną biblioteką" .
mingw32-make
./RandomGenBenchmark.exe
```

Linux (nietestowane):

```bash
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release .
make
./RandomGenBenchmark
```