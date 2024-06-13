CXX = clang++ -std=c++17
SRC = table.cpp main.cpp
OBJ = $(SRC:%.cpp=%.o)

table: $(OBJ)
	$(CXX) $(OBJ) -o table
	
%.o: %.cpp
	$(CXX) $< -c -o $@