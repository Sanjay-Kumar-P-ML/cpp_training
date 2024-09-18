#include <iostream>
#include <regex> // Include the regex library

int main() {
    // Example 1: Matching a Pattern
    std::string text = "hello123";
    std::regex pattern("[a-z]+[0-9]+"); // Pattern: one or more lowercase letters followed by one or more digits

    if (std::regex_match(text, pattern)) {
        std::cout << "Text matches the pattern!" << std::endl;
    } else {
        std::cout << "Text does not match the pattern." << std::endl;
    }

    // Example 2: Searching within a String
    std::string paragraph = "The quick brown fox jumps over 123 lazy dogs.";
    std::regex number_pattern("[0-9]+"); // Pattern: one or more digits

    std::smatch match_result;
    if (std::regex_search(paragraph, match_result, number_pattern)) {
        std::cout << "Found a number: " << match_result.str() << std::endl;
    }

    // Example 3: Replacing text using regex
    std::string text_to_replace = "My email is example@domain.com";
    std::regex email_pattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    std::string result = std::regex_replace(text_to_replace, email_pattern, "[REDACTED]");

    std::cout << "Replaced text: " << result << std::endl;

    return 0;
}

