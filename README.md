After having compiled the library using `make` (monke-engine repo), compile and run demo using:
`export LD_LIBRARY_PATH=/usr/local/lib && g++ src/main.cpp -lmonke -lGL -lglfw -o app.o && ./app.o`