/**
 * @file Logger.h
 * @brief Declaração da classe Logger para saída de mensagens de log no console.
 */
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

/**
 * @class Logger
 * @brief Classe utilitária para registrar mensagens de log no console.
 */
class Logger {
public:
    /**
     * @brief Exibe uma mensagem de log no console.
     * @param message Mensagem a ser exibida.
     */
    static void log(const std::string& message);
};

#endif
