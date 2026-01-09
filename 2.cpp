#include <SFML/Audio/Music.hpp>
#include <chrono>
#include <iostream>
#include <filesystem>
#include <SFML/Audio.hpp>
#include <thread>

int main() {
    const std::filesystem::path folder = "Songs";
    for (const auto& entry : std::filesystem::directory_iterator(folder)) {
        std::cout << entry.path() << '\n';

        sf::Music music;

        if (!music.openFromFile(entry.path())) {
            continue;
        }

        music.play();

        music.setVolume(100.f);

        while (music.getStatus() == sf::Music::Status::Playing) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}
