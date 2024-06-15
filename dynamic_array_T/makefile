CXX = clang++ -std=c++20
SRC = dynamic_array.cpp main.cpp temptemp.cpp
OBJ = $(SRC:%.cpp=%.o)

demo: $(OBJ)
	$(CXX) $(OBJ) -o demo
	
%.o: %.cpp
	$(CXX) $< -c -o $@