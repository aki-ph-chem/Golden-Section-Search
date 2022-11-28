CXX = g++

f = bin_search

run: ${f}.out
	./${f}.out

${f}.out : ${f}.cpp
	${CXX} $< -o $@

clean:
	rm *.out

.PHONY: run clean
