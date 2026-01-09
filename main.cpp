#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    sf::Music music; // keep it alive for the duration of the program

    if (!music.openFromFile("Songs/Mellohi.mp3")) {
        std::cout << "Fail!" << '\n';
        return -1;
    }

    music.setLooping(false);
    music.play(); // non-blocking, music plays in background

    std::cout << "Music is playing. Doing other things..." << std::endl;



    // Main loop can do other work
    while (static_cast<int>(music.getStatus()) == 2) {
        std::cout << static_cast<int>(music.getStatus()) << '\n';
        sf::sleep(sf::seconds(1));
    }

    music.stop(); // stop music if needed
    std::cout << "Music stopped.\n";

    return 0;
}
