# Code files to tasks mapping
    Lib \ debounce \ debounce.h
    - BTN_PIN1 defines pin
    - #define MODULE_2_6_T1 - task 1 for 2.6 module
        Lib \ debounce \ debounce1.h
        Lib \ debounce \ debounce1.c
    - #define MODULE_2_6_T2 - task 2 for 2.6 module
        Lib \ debounce \ debounce2.h
        Lib \ debounce \ debounce2.c 
            task implementation
    - #define MODULE_2_6_T3 - task 3 for 2.6 module
        Lib \ debounce \ debounce3.h
        Lib \ debounce \ debounce3.c 
            task implementation
    - #define MODULE_2_6_T4 - task 4 for 2.6 module
        Lib \ debounce \ debounce4.h
        Lib \ debounce \ debounce4.c 
            task implementation
    Lib \ debounce \ debounce.c
        Setup() configs PINs and ISR