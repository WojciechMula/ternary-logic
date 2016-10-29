FLAGS=-std=c++11 -O2 -Wall -pedantic
PYDEPS=py/*.py py/lib/*.py
ALL=validate_sse validate_avx2

all: $(ALL)

validate_sse: validate_sse.cpp ternary_sse.cpp
	$(CXX) $(FLAGS) validate_sse.cpp -o $@

validate_avx2: validate_avx2.cpp ternary_avx2.cpp
	$(CXX) $(FLAGS) -mavx2 validate_avx2.cpp -o $@

ternary_sse.cpp: $(PYDEPS) py/cpp.* py/intel.txt
	python py/main.py --language=cpp --target=sse -o $@

ternary_avx2.cpp: $(PYDEPS) py/cpp.* py/intel.txt
	python py/main.py --language=cpp --target=avx2 -o $@

clean:
	rm -f $(ALL)
