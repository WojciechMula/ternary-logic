PYDEPS=py/*.py py/lib/*.py

all: validate_sse

ternary_sse.cpp: $(PYDEPS) py/cpp.* py/intel.txt
	python py/main.py --language=cpp --target=sse > tmp
	mv tmp $@

validate_sse: validate_sse.cpp ternary_sse.cpp
	$(CXX) -std=c++11 -O2 validate_sse.cpp -o $@
