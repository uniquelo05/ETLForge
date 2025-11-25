#include "cpp-taskflow/taskflow.hpp"
#include "extractor.hpp"
#include "loader.hpp"
#include "transformer.hpp"
#include "logger.hpp"
#include "metrics.hpp"
#include <iostream>

int main() {
    // Initialize Taskflow and Executor
    tf::Taskflow tf;
    tf::Executor executor;

    // Initialize ETL components
    etlforge::Extractor extractor;
    etlforge::Loader loader;
    etlforge::Transformer transformer;
    etlforge::Metrics metrics;

    // Define file paths
    std::string inputFilePath = "data/input/raw/sample_data.txt";
    std::string outputFilePath = "data/output/processed/output_data.txt";

    // Start ETL process
    metrics.startTimer();

    auto extractTask = tf.emplace([&]() {
        etlforge::Logger::logInfo("Starting data extraction...");
        auto data = extractor.extractFromFile(inputFilePath);
        etlforge::Logger::logInfo("Data extraction completed.");
        return data;
    });

    auto transformTask = tf.emplace([&](std::vector<std::string> data) {
        etlforge::Logger::logInfo("Starting data transformation...");
        auto transformedData = transformer.transformData(data);
        etlforge::Logger::logInfo("Data transformation completed.");
        return transformedData;
    });

    auto loadTask = tf.emplace([&](std::vector<std::string> transformedData) {
        etlforge::Logger::logInfo("Starting data loading...");
        loader.loadToFile(transformedData, outputFilePath);
        etlforge::Logger::logInfo("Data loading completed.");
    });

    // Define task dependencies
    extractTask.precede(transformTask);
    transformTask.precede(loadTask);

    // Execute the taskflow
    executor.run(tf).wait();

    // End ETL process
    metrics.stopTimer();
    etlforge::Logger::logInfo("ETL process completed successfully!");
    std::cout << "Total execution time: " << metrics.getElapsedTime() << " seconds." << std::endl;

    return 0;
}