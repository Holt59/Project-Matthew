#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>

namespace GPIO {

    namespace Pin {

        namespace IRQ {

            const uint16_t Input = 176 ;
            const uint16_t FlipFlop = 175 ;

        }

        namespace Motor {

            const uint16_t Motor1 = 171 ;
            const uint16_t Motor2 = 172 ;
            const uint16_t Motor3 = 173 ;
            const uint16_t Motor4 = 174 ;

        }

	}

    bool init () ;

    void stop () ;

    void setupInput (uint16_t pin) ;
	void setupOutput (uint16_t pin) ;

    void set (uint16_t pin) ;

    uint16_t get (uint16_t pin) ;

    void clear (uint16_t pin) ;

}

#endif
