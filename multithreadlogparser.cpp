#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>

// Singleton LogParser class
class LogParser {
        private:
            static LogParser* instance;
            static std::mutex mtx;

            // Private constructor to prevent instantiation
            LogParser() {}

        public:
            // Method to get the single instance of the class
            static LogParser* getInstance(){
                std::lock_guard<std::mutex> lock(mtx); // Ensure thread-safe access to the instance
                if (!instance) {
                    instance = new LogParser();
     //               std::lock_guard
                }
                return instance;
            }

    // Method to parse the log file and write to output log file
    void parseLog(const std::string& inputFilename, const std::string& outputFilename) {
        std::ifstream logFile(inputFilename);
        std::ofstream outFile(outputFilename, std::ios_base::app);  // Append mode
        std::string line;

        if (logFile.is_open() && outFile.is_open()) {
            std::lock_guard<std::mutex> lock(mtx); // Ensure thread-safe access to the file
            std::cout << "Parsing log file: " << inputFilename << std::endl;

            while (getline(logFile, line)) {
                outFile << "Log from " << inputFilename << ": " << line << std::endl;  // Write each log line
            }

            logFile.close();
            outFile.close();
        } else {
            std::cerr << "Unable to open file: " << inputFilename << " or " << outputFilename << std::endl;
        }
    }
};

// Initialize the static instance pointer and mutex
LogParser* LogParser::instance = nullptr;
std::mutex LogParser::mtx;

// Function to be run by each thread
void threadTask(const std::string& inputFilename, const std::string& outputFilename) {
    LogParser* parser = LogParser::getInstance();  // Each thread gets the same instance
    parser->parseLog(inputFilename, outputFilename);
}

int main() {
    const std::string outputFilename = "output_logs.txt";

    // Create two threads, each parsing a different log file but writing to the same output file
    std::thread t1(threadTask, "logfile.txt", outputFilename);
    std::thread t2(threadTask, "logfile2.txt", outputFilename);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    std::cout << "Logs written to " << outputFilename << std::endl;

    return 0;
}
