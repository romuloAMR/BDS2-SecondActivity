#include "../headers/Logger.h"
#include <iostream>

/**
 * @brief Implementa a função de log para saída padrão.
 */
void Logger::log(const std::string& message) {
    std::cout << message << std::endl;
}
