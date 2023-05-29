#pragma once
#include "figure1/figure1.h"
#include <iostream>
#include <conio.h>

namespace menu {
    void text_menu();
    int get_key();

    Figures::FigurePtr create_figure();
}