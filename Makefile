FLAGS=-std=c++11 -O2 -Wall -pedantic
PYDEPS=py/*.py py/lib/*.py
DATA=py/data/*.txt
ALL=validate_sse validate_avx2 validate_xop

all: $(ALL)

validate_sse: validate_sse.cpp ternary_sse.cpp
	$(CXX) $(FLAGS) validate_sse.cpp -o $@

validate_avx2: validate_avx2.cpp ternary_avx2.cpp
	$(CXX) $(FLAGS) -mavx2 validate_avx2.cpp -o $@

validate_xop: validate_xop.cpp ternary_xop.cpp
	$(CXX) $(FLAGS) -mxop validate_xop.cpp -o $@

ternary_sse.cpp: $(PYDEPS) py/cpp.function py/cpp.sse.main $(DATA)
	python py/main.py --language=cpp --target=sse -o $@

ternary_avx2.cpp: $(PYDEPS) py/cpp.function py/cpp.avx2.main $(DATA)
	python py/main.py --language=cpp --target=avx2 -o $@

ternary_xop.cpp: $(PYDEPS) py/cpp.function py/cpp.xop.main $(DATA)
	python py/main.py --language=cpp --target=xop -o $@

clean:
	rm -f $(ALL)
