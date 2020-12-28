CXX=g++
CXXFLAGS=-g

asoc_bin : asoc.o compiler.o
	$(CXX) $^ -o $@

asoc.o : asoc.cpp proc.h
	$(CXX) $(CXXFLAGS) -c $<

compil.o : compiler.cpp compiler.h proc.h
	$(CXX) $(CXXFLAGS) -c $<

clean : 
	rm -rf *.o compil