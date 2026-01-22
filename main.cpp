#include <SFML/Audio.hpp>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path pathToShow = "Songs";
    sf::Music music;

    for (const auto& entry : fs::directory_iterator(pathToShow)) {
        std::cout << entry.path().string() << std::endl;

        if (!music.openFromFile(entry.path().string())) {
            std::cout << "Fail!" << '\n';
            return -1;
        }

        music.setLooping(false);
        music.play();

        std::cout << "Music is playing. Doing other things..." << std::endl;

        // Main loop can do other work
        while (static_cast<int>(music.getStatus()) == 2) {
            std::cout << static_cast<int>(music.getStatus()) << '\n';
            sf::sleep(sf::seconds(0.1));
        }

        music.stop(); // stop music if needed
        std::cout << "Music stopped.\n";

        return 0;
}
}
