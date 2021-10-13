SRC = $(shell find source -name "*.cpp")
CXX = g++-10
CXX_ARGS = -std=c++17
OUT = rsim.exe

all: 
	$(CXX) $(CXX_ARGS) -o $(OUT) $(SRC)

clean: $(OUT)
	rm $(OUT)
