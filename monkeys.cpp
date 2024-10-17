/*
** Filename: monkeys.cpp
** Created on: September 17, 2024
** Author: Lucas Da Cruz Silva
 */

#include <iostream>
#include <random>
#include <vector>
#include <tuple>
#include <chrono>

std::string generate_string(std::string& str_typed, const int size) {
    std::random_device rd;
    for (int i = 0; i < size; i++) {
        std::uniform_int_distribution<> dist(0,27);
        const int random = dist(rd);
        (random < 26) ? str_typed += static_cast<char>('a' + random) : str_typed += ' ';
    }
    return str_typed;
}

std::string mutation(const std::string& phrase, const double mutation_rate) {
    if ( mutation_rate == static_cast<double>(0) ) {
        return phrase;
    }
    std::random_device rd;
    std::uniform_real_distribution<> mutation_dist(0.0, 1.0);
    std::uniform_int_distribution<> char_dist(0, 27);

    std::string mutated_phrase = phrase;
    // For a given sentence, there is a chance that the character will be modified.
    // It means that, for a given chromosome, there is a chance that the gene will be modified.
    for (size_t i = 0; i < mutated_phrase.size(); i++) {
        // If mutation rate is reached, so we change character
        if (mutation_dist(rd) < mutation_rate) {
            const int random = char_dist(rd);
            mutated_phrase[i] = (random < 26) ? static_cast<char>('a' + random) : ' ';
        }
    }
    return mutated_phrase;
}

int fitness(const std::string& target, const std::string& candidate) {
    int score = 0;
    for (size_t i = 0; i < target.size(); ++i) {
        if (target[i] == candidate[i]) {
            score++;
        }
    }
    return score;  // Quanto maior o score, melhor a frase
}

std::tuple<int, int, std::string> model_generations(const std::string& target, const std::string& init_phrase, const int n_generations, const double mutation_rate) {

    const int n_copies = n_generations;
    long long int attempts = 0;
    long long int generations_processed = 0;

    // In each generation a "typed phrase" is selected at random to continue the cycle.
    // Then, we must select the generated phrases.. It is like a selection.
    std::vector<std::string> selected_phrases;
    std::string phrase = init_phrase;

    while (generations_processed != n_generations) {
        // DNA Polimerase
        // Now we are going to generate N copies with mutation from the initial phrase.
        // Every copy with mutation will be saved on "selected_phrases"
        for (int i = 0; i < n_copies; i++) {
            std::string mutated_phrase = mutation(phrase, mutation_rate);
            selected_phrases.push_back(mutated_phrase);
        }

        // So, now that each copy has been subjected to a mutation process (which may or may not have been carried out).
        // Let's check if there is any mutation that is the same as the target phrase.
        // THIS CAN BE CHANGED LATER...
        for (const auto& p : selected_phrases) {
            attempts++;
            if (p == target) {
                generations_processed++;

                std::cout << "[+] generation: " << generations_processed << std::endl;
                std::cout << " └─ attempts  : " << attempts << std::endl;
                std::cout << " └─ sentence  : " << phrase << std::endl;

                return {generations_processed, attempts, p};
            }
        }

        // If the processing is not successful, we will randomly choose one of the sentences from the current generation,
        // to continue processing the next generation.
        std::random_device rd;
        std::uniform_int_distribution<> selection_dist(0, n_generations - 1);
        phrase = selected_phrases[selection_dist(rd)];

        // Let's clean the structure so as not to overload memory
        selected_phrases.clear();

        generations_processed++;
        std::cout << "[+] generation: " << generations_processed << std::endl;
        std::cout << " └─ attempts  : " << attempts << std::endl;
        std::cout << " └─ sentence  : " << phrase << std::endl;
    }

    return {generations_processed, attempts, phrase};
}


int main(){

    std::string target;
    std::cout << "Write a sentence: ";
    std::getline(std::cin, target);

    const int L = target.size(); // target string size of length L

    long long int N; // generations (N)
    std::cout << "Enter the number of generations: ";
    std::cin >> N;

    double u; // mutation rate (u)
    std::cout << "Enter the mutation rate: ";
    std::cin >> u;

    const auto start_time = std::chrono::high_resolution_clock::now();

    // generate the random phrase of length L
    std::string random_phrase;
    generate_string(random_phrase, L);

    // generations
    auto [gen, att, str] = model_generations(target, random_phrase, N, u);

    const auto end_time = std::chrono::high_resolution_clock::now();

    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << "Target sentence: \"" << target << "\"" << std::endl;
    std::cout << "Number of attempts: " << att << std::endl;
    std::cout << "Number of generations processed: " << gen << std::endl;
    std::cout << "Typed sentence: " << str << std::endl;
    std::cout << "Time elapsed: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
