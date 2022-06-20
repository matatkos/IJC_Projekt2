FLAGS=-std=c99 -pedantic -Wall -Wextra
cc = gcc
library_files = htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o\
				htab_free.o htab_hash_func.o htab_init.o htab_lookup_add.o htab_resize.o htab_size.o

all: tail wordcount wordcount-dynamic

tail : tail.c
	$(cc) $(FLAGS) -o tail tail.c

wordcount:	wordcount.o io.o libhtab.a
	$(cc) $(FLAGS) -o wordcount -static io.o wordcount.o libhtab.a

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(cc) $(FLAGS) -L. -lhtab -Wl,-rpath="$(PWD)" -o wordcount-dynamic wordcount.o io.o libhtab.so

libhtab.a: $(library_files)
	ar crs libhtab.a $(library_files)

libhtab.so: $(library_files)
	$(cc) $(FLAGS) -shared -fPIC $^ -o $@

wordcount.o : wordcount.c
	$(cc) -c wordcount.c -o wordcount.o

htab_bucket_count.o : htab_bucket_count.c
	$(cc) -fPIC -c htab_bucket_count.c -o htab_bucket_count.o

htab_clear.o: htab_clear.c
	$(cc) -fPIC -c htab_clear.c -o htab_clear.o

htab_erase.o : htab_erase.c
	$(cc) -fPIC -c htab_erase.c -o htab_erase.o

htab_find.o : htab_find.c
	$(cc) -fPIC -c htab_find.c -o htab_find.o

htab_for_each.o : htab_for_each.c
	$(cc) -fPIC -c htab_for_each.c -o htab_for_each.o

htab_free.o : htab_free.c
	$(cc) -fPIC -c htab_free.c -o htab_free.o

htab_hash_func.o: htab_hash_func.c
	$(cc) -fPIC -c htab_hash_func.c -o htab_hash_func.o

htab_init.o : htab_init.c
	$(cc) -fPIC -c htab_init.c -o htab_init.o

htab_lookup_add.o : htab_lookup_add.c
	$(cc) -fPIC -c htab_lookup_add.c -o htab_lookup_add.o

htab_resize.o : htab_resize.c
	$(cc) -fPIC -c htab_resize.c -o htab_resize.o

htab_size.o : htab_size.c
	$(cc) -fPIC -c htab_size.c -o htab_size.o

io.o : io.c
	$(cc) -c io.c -o io.o

clean:
	rm wordcount wordcount-dynamic tail libhtab.a libhtab.so *.o