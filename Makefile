main:
	g++ include/axisrectangle.h include/object.h include/constants.h include/program.h src/main.cpp src/program.cpp src/rectangle.cpp src/utilities.cpp -lSDL2 -lSDL2_image -o executable