FLAGS=-std=c++11 -O2 -Wall -pedantic
PYDEPS=py/*.py py/lib/*.py
DATA=py/data/*.txt
ALL=validate_sse validate_avx2 validate_xop validate_x86 ternary_avx512.o ternary_neon.cpp
PYTHON?=python3

all: $(ALL)

validate_sse: validate_sse.cpp ternary_sse.cpp
	$(CXX) $(FLAGS) validate_sse.cpp -o $@

validate_avx2: validate_avx2.cpp ternary_avx2.cpp
	$(CXX) $(FLAGS) -mavx2 validate_avx2.cpp -o $@

validate_xop: validate_xop.cpp ternary_xop.cpp
	$(CXX) $(FLAGS) -mxop validate_xop.cpp -o $@

validate_x86: validate_x86.cpp ternary_x86_64.cpp ternary_x86_32.cpp
	$(CXX) $(FLAGS) validate_x86.cpp -o $@

validate_neon: validate_xop.cpp ternary_neon.cpp
	$(CXX) $(FLAGS) validate_neon.cpp -o $@

ternary_avx512.o: ternary_avx512.cpp
	$(CXX) $(FLAGS) -mavx512f $^ -c -o $@

ternary_sse.cpp: $(PYDEPS) py/cpp.function py/cpp.sse.main $(DATA)
	$(PYTHON) py/main.py --target=sse -o $@

ternary_avx2.cpp: $(PYDEPS) py/cpp.function py/cpp.avx2.main $(DATA)
	$(PYTHON) py/main.py --target=avx2 -o $@

ternary_avx512.cpp: $(PYDEPS) py/cpp.function py/cpp.avx512.main $(DATA)
	$(PYTHON) py/main.py --target=avx512 -o $@

ternary_xop.cpp: $(PYDEPS) py/cpp.function py/cpp.xop.main $(DATA)
	$(PYTHON) py/main.py --target=xop -o $@

ternary_x86_64.cpp: $(PYDEPS) py/cpp.function py/cpp.x86_64.main $(DATA)
	$(PYTHON) py/main.py --target=x86_64 -o $@

ternary_x86_32.cpp: $(PYDEPS) py/cpp.function py/cpp.x86_32.main $(DATA)
	$(PYTHON) py/main.py --target=x86_32 -o $@

ternary_neon.cpp: $(PYDEPS) py/cpp.function py/cpp.neon.main $(DATA)
	$(PYTHON) py/main.py --target=neon -o $@

test: validate_sse validate_x86
	./validate_sse
	./validate_x86

.PHONY: html
html: html/index.html

html/index.html: py/html.py
	$(PYTHON) py/html.py -o $@

.PHONY: clean
clean:
	$(RM) $(ALL)
