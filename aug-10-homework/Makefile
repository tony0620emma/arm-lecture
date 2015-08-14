CFLAGS = -Wall -g -O0 --std=gnu99

benchmark: benchmark.c findGCD.h
	$(CC) $(CFLAGS) -o $@ $^

run-benchmark: benchmark
	./benchmark

phone_book: phone_book.c
	$(CC) $(CFLAGS) -o $@ $^
	./$@

clean:
	rm -f *.o benchmark phone_book
