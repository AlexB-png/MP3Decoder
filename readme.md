Note to self

Build with:
g++ -Wall -Wextra -Wpedantic -g3 -O0 main.cpp -o ./build/Debug/outDebug -lsfml-audio -lsfml-system

Execute with:
./build/Debug/outDebug

For the UI

build with:
g++ main.cpp -o app `pkg-config gtkmm-3.0 --cflags --libs`

run with:
./app