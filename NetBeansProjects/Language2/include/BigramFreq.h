/*
 * Metodología de la Programación: Language2
 * Curso 2022/2023
 */

/* 
 * @file   BigramFreq.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 29 January 2023, 11:00
 */

#ifndef BIGRAM_FREQ_H
#define BIGRAM_FREQ_H

#include <string>

#include "Bigram.h"

/**
 * @class BigramFreq
 * @brief A pair of a Bigram object and a frequency (an int), that gives the 
 * frequency of a Bigram (times it appears) in a text.
 */
class BigramFreq {
public:
    /**
     * @brief Base constructor. It builds a BigramFreq object with "__" as 
     * the text of the bigram and 0 as the frequency
     */
    BigramFreq();

    /**
     * @brief Gets a const reference to the Bigram of this BigramFreq object.
     * Query method
     * @return A const reference to the Bigram of this BigramFreq object
     */
    Bigram getBigram();

    /**
     * @brief Gets the frequency of this BigramFreq object
     * Query method
     * @return The frequency of this BigramFreq object
     */
    int getFrequency();

    /**
     * @brief Sets the Bigram of this BigramFreq object
     * Modifier method
     * @param bigram The new Bigram value for this object. Input parameter
     */
    void setBigram(Bigram bigram);

    /**
     * @brief Sets the frequency of this BigramFreq object. Modifier method.
     * @throw std::out_of_range if @p frequency is negative
     * @param frequency the new frequency value for this BigramFreq object. 
     * Input parameter
     */
    void setFrequency(int frequency);
    
    /**
     * @brief Obtains a string with the string and frecuency of the bigram
     * in this object (separated by a whitespace). Query method
     * @return A string with the string and frecuency of the bigram
     * in this object. 
     */
    std::string toString();

private:
    Bigram _bigram; ///< the Bigram object
    int _frequency; ///< the frequency
};


#endif /* BIGRAM_FREQ_H */

