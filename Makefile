#
# Makefile
# Created by jhhan128.
#
#
# Makefile of gifted2021 project.
#

gifted2021:
	g++ -std=c++20 -o gifted2021 src/main.cpp src/first_exec.cpp src/make_data.cpp lib/data_structures/hash/hash.cpp src/today.cpp lib/data_structures/graph/graph.cpp 
clean:
	rm gifted2021; rm config.txt