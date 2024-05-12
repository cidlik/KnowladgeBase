# Этот файл является некоторым дополнением к основному. Основная идея - прора-
# ботать материал из главы, но инфомарция и задания берутся извне.

import numpy


CHR_A = 65
TOWNS_NUM = 6


def main():
    towns = {}
    for i in range(TOWNS_NUM):
        towns[i] = chr(CHR_A + i)
    print(towns)
    matrix = numpy.array(
        [
            [0  ,9  ,12 ,9  ,3  ,0  ],
            [9  ,0  ,2  ,0  ,6  ,3  ],
            [12 ,2  ,0  ,2  ,0  ,7  ],
            [9  ,0  ,2  ,0  ,6  ,2  ],
            [3  ,6  ,0  ,6  ,0  ,2  ],
            [0  ,3  ,7  ,2  ,2  ,0  ],
        ]
    )
    print(matrix)


if __name__ == "__main__":
    main()