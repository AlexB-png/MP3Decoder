#include <SFML/Audio/Music.hpp>
#include <chrono>
#include <iostream>
#include <filesystem>
#include <SFML/Audio.hpp>
#include <thread>
#include <list>

int main() {
    std::list<std::string> songs;
    const std::filesystem::path folder = "Songs";

    for (const auto& entry : std::filesystem::directory_iterator(folder)) {
        songs.push_back(entry.path());
    };

    for (const auto& song : songs) {
        std::cout << song << '\n';
    };
}
