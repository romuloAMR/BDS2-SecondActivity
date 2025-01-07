#ifndef LOGGER_H
#define LOGGER_H

#include <string>

/**
 * @class Logger
 * @brief Classe para gerenciar mensagens de log para saída padrão.
 */
class Logger {
public:
    /**
     * @brief Escreve uma mensagem no log.
     * @param message A mensagem a ser registrada.
     */
    static void log(const std::string& message);
};

#endif // LOGGER_H
