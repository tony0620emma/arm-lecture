CFLAGS = -Wall -g -O0 --std=gnu99

benchmark: benchmark.c findGCD.h
	$(CC) $(CFLAGS) -o $@ $^

run-benchmark: benchmark
	./benchmark

phonebook_test: phonebook_testbench.c phonebook_v1.h phonebook_v2.h
	$(CC) $(CFLAGS) -o $@ $^
	./$@

cache-misses: phonebook_test
	perf stat -e cache-misses,cache-references ./$^

clean:
	rm -f *.o benchmark phonebook_test perf.data
