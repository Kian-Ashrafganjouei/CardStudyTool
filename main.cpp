#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp> // Include nlohmann json library. Make sure you have it in your project.
#include <random>
#include <algorithm>
#include <limits>

using json = nlohmann::json;

// Structure to hold a flashcard with a question, answer, and difficulty score
struct Flashcard {
    std::string question;
    std::string answer;
    int score; // Lower score items are prioritized
};

// Function to load flashcards from a JSON file
std::vector<Flashcard> loadFlashcards(const std::string& filename) {
    std::vector<Flashcard> flashcards;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return flashcards;
    }
    
    json j;
    file >> j;
    
    for (const auto& item : j["flashcards"]) {
        Flashcard card;
        card.question = item["question"].get<std::string>();
        card.answer = item["answer"].get<std::string>();
        card.score = item.contains("score") ? item["score"].get<int>() : 0; // Default score is 0 if not present
        flashcards.push_back(card);
    }
    
    return flashcards;
}

// Function to save flashcards back to the JSON file with updated scores
void saveFlashcards(const std::string& filename, const std::vector<Flashcard>& flashcards) {
    json j;
    for (const auto& card : flashcards) {
        j["flashcards"].push_back({
            {"question", card.question},
            {"answer", card.answer},
            {"score", card.score}
        });
    }
    
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not write to file " << filename << std::endl;
        return;
    }
    
    file << j.dump(4);
}

// Function to randomly select a flashcard with bias towards lower scored items
Flashcard& selectFlashcard(std::vector<Flashcard>& flashcards) {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Sort flashcards by score (lower scores have higher priority)
    std::sort(flashcards.begin(), flashcards.end(), [](const Flashcard& a, const Flashcard& b) {
        return a.score < b.score;
    });
    
    // Weighted random selection
    std::uniform_int_distribution<> dis(0, flashcards.size() - 1);
    return flashcards[dis(gen)];
}

int main() {
    std::string filename = "flashcards.json";
    
    // Load flashcards from file
    std::vector<Flashcard> flashcards = loadFlashcards(filename);
    if (flashcards.empty()) {
        std::cerr << "No flashcards available. Please check the file." << std::endl;
        return 1;
    }
    
    std::cout << "Welcome to the Study Tool! Press Enter to reveal the answer." << std::endl;
    
    char userInput;
    while (true) {
        // Select a flashcard
        Flashcard& card = selectFlashcard(flashcards);

        std::cout << "\n\033[1;34mQuestion: \033[0m" << card.question << std::endl;
        std::cout << "\033[1;33m(Press Enter to see the answer)\033[0m";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\033[1;32mAnswer: " << card.answer << "\033[0m" << std::endl;

        std::cout << "\033[1;33mHow did you do? (e = easy +3, h = hard +1, w = wrong 0, \033[1;31mq = quit\033[1;33m): \033[0m";
        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (userInput == 'q') {
            std::cout << "\033[1;31mThanks for studying! Your progress has been saved.\033[0m" << std::endl;
            break;
        } else if (userInput == 'e') {
            card.score += 3;
        } else if (userInput == 'h') {
            card.score += 1;
        } else if (userInput == 'w') {
            // No change to score for wrong answer
        } else {
            std::cout << "\033[1;33mInvalid input. Please enter 'e', 'h', 'w', or 'q'.\033[0m" << std::endl;
            continue;
        }

        saveFlashcards(filename, flashcards);
    }

    return 0;
}
