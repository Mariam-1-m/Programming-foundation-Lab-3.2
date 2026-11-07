// // int boxSize;
// // vector<vector<int>> magicBox(10, vector<int>(10, 0));
// //  void takeInput2();

// void generateAndPrint(int n, int startX, int startY);

#ifndef MAGIC_BOX_H
#define MAGIC_BOX_H

class MagicBox {
private:
    int n;         
    int startX;     
    int startY;     
    int delayMs;    

    void sleepFor(int milliseconds) const;

public:
    MagicBox(int size, int x, int y, int delay);

    void display() const;
};

#endif 