PYDEPS=py/*.py py/lib/*.py

ternary_sse.cpp: $(PYDEPS) py/intel.txt
	python py/generate.py --language=cpp --target=sse > tmp
	mv tmp $@

validate_sse.cpp: ternary_sse.cpp
	$(CXX) -O2 validate_sse.cpp -o $@
