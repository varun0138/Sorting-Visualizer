#pragma once

#include <vector>
#include <cmath>
#include <algorithm>

class ShellSort{
   int interval = size / 2;
   int a = interval;
   int b = a;
   int i = 0;
   std::vector<int> seq = sedgewick(size);
   
public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();

private:
    std::vector<int> donaldShell(int size);
    std::vector<int> knuth(int size);
    std::vector<int> ciura(int size);
    std::vector<int> sedgewick(int size);
    std::vector<int> tokuda(int size);
    std::vector<int> hibbard(int size);
    std::vector<int> papernov(int size);

};
