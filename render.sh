cmake -B build      # sets up cmake using CMakeLists.txt; does not need to be re-run unless changes were made
cmake --build build # compiles the default target (all) and puts it in all in build/
build/row >render.ppm
feh render.ppm
