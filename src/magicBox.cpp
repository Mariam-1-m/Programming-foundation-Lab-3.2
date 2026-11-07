
	
// #include "../include/magicBox.h"
// #include "../include/menu.h" 
// #include <iostream>
// #include <vector>

// void generateAndPrint(int n, int startX, int startY) {
//     if (n % 2 == 0) {
//         goToXY(startX, startY);
//         std::cout << "Error: N must be an odd number!";
//         return;
//     }

//     std::vector<int> magicBox(n * n, 0);

//     int row = 0;
//     int col = n / 2;
//     magicBox[row * n + col] = 1;

//     for (int num = 2; num <= n * n; num++) {
//         int prevRow = row;
//         int prevCol = col;

//         row--;
//         col++;

//         if (row < 0) row = n - 1;
//         if (col >= n) col = 0;

//         if (magicBox[row * n + col] != 0) {
//             row = prevRow + 1;
//             col = prevCol;
//         }

//         magicBox[row * n + col] = num;
//     }

//     for (int r = 0; r < n; r++) {
//         goToXY(startX, startY + r);
        
//         for (int c = 0; c < n; c++) {
//             std::cout << magicBox[r * n + c] << "\t";
//         }
//     }
// }

#include "../include/magicBox.h"
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

MagicBox::MagicBox(int size, int x, int y, int delay) 
    : n(size), startX(x), startY(y), delayMs(delay) {

    if (n % 2 == 0) {
        n += 1;
    }
}

void MagicBox::sleepFor(int milliseconds) const {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void MagicBox::display() const {
    std::cout << "\033[2J\033[1;1H"; 
    
    std::cout << "\033[" << (startY - 2) << ";" << startX << "H"
              << "=== MAGIC BOX (Order " << n << " x " << n << ") ===\n";

    int totalCells = n * n;

    for (int k = 1; k <= totalCells; ++k) {
        int term1 = (n + 2 * k - 3) / 2;
        int term2 = (k - 1) / n;
        int a = ((term1 + term2) % n + n) % n + 1; 

        int term3 = n - k - 2;
        int term4 = 2 * ((k - 1) / n);
        int b = ((term3 + term4) % n + n) % n + 1; 

        int row = a - 1;
        int col = b - 1;

     
        int cellWidth = 4;
        int currentX = startX + (col * cellWidth);
        int currentY = startY + row;

        std::cout << "\033[" << currentY << ";" << currentX << "H";

        std::cout  << std::setw(2) << k << " ";

        std::cout << std::flush;
        sleepFor(delayMs);
    }

    std::cout << "\033[" << (startY + n + 2) << ";" << startX << "H";
    std::cout << "Magic Box Generation Complete!\n\n";
}