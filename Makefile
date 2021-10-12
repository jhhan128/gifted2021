#
# Makefile
# Created by jhhan128.
#
#
# Makefile of gifted2021 project.
#

gifted2021:
	gcc -o gifted2021 src/main.c src/first_exec.c src/make_data.c lib/data_structures/hash/hash.c
clean:
	rm gifted2021