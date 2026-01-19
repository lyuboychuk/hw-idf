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
# usabilty 
    platformio.ini
    example will set to compile  the task 3
        build_flags =     
        -D MODULE_2_6_T3  

#Результати

| Метод        | Кількість хибних спрацювань | Затримка | Складність | Коментар                                                 |
| ------------ | --------------------------- | -------- | ---------- | -------------------------------------------------------- |
| Без debounce | від 2-9 раз                 | 0 ms     | low        |                                                          |
| Time-based   | 0                           | 50ms     | mid        |                                                          |
| State-based  | 0                           | 50ms     | high       |                                                          |
| Polling      | 0                           | 10ms     | low        | деякі натиснення пропускаються коли дуже часто натискати |
| Hardware RC  | від 0-2 раз                 | 0 ms     | low        | Збірка "без debounce" і зовнішня мебранна кнопка         |