#include <iostream>
#include <fstream>
#include <string>

// Singleton LogParser class
class LogParser {
private:
    static LogParser* instance;  // Static instance pointer
    std::string combinedLogs;

    // Private constructor to prevent instantiation
    LogParser() {}

public:
    // Method to get the single instance of the class
    static LogParser* getInstance() {
        if (!instance) {
            instance = new LogParser();
        }
        return instance;
    }

    // Method to parse the log file
void parseLog(const std::string& filename) {
        std::ifstream logFile(filename);
        std::string line;

        if (logFile.is_open()) {
            std::cout << "Parsing log file: " << filename << std::endl;
            while (getline(logFile, line)) {
                combinedLogs += line + "\n";  // Append to combined logs
            }

            logFile.close();
        }
        else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }

   }

    // Method to show combined logs from both files
    void showLogs() const {
        std::cout << "Combined Logs:\n" << combinedLogs << std::endl;
    }
};
// Initialize the static instance pointer to nullptr
LogParser* LogParser::instance = nullptr;

int main() {
            // Get the first Singleton instance
            LogParser* parser1 = LogParser::getInstance();
            LogParser* parser2 = LogParser::getInstance();

            // Check if both instances are pointing to the same object
            if (parser1 == parser2) {
                std::cout << "Both parser1 and parser2 point to the same LogParser instance!" << std::endl;
            }

            parser1->parseLog("logfile.txt");
            parser2->parseLog("logfile2.txt");

            // Show the combined logs
            parser1->showLogs();

            return 0;
}
