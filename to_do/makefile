CXX = clang++ -std=c++20
SRC = list.cpp main.cpp 
OBJ = $(SRC:%.cpp=%.o)

demo: $(OBJ)
	$(CXX) $(OBJ) -o demo
	
%.o: %.cpp
	$(CXX) $< -c -o $@