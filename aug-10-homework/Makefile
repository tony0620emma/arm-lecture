CFLAGS = -Wall -g -O0

benchmark: benchmark.c findGCD.h
	$(CC) $(CFLAGS) -o $@ $^

run-benchmark: benchmark
	./benchmark

clean:
	rm -f *.o benchmark
