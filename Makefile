CPP_FILES = $(wildcard source/*.cpp)
OUTPUT_FILE = build/raytracer

compile:
	clang++ -std=c++11 -o $(OUTPUT_FILE) $(CPP_FILES) -Iinclude/ -Ilib/  -Llib/ -lpng -lpngwriter -DNO_FREETYPE
