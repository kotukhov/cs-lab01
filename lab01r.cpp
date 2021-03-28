// lab01r.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
using namespace std;
const size_t SCREENWIDTH = 80;
const size_t MAX_ASTERISK = SCREENWIDTH - 3 - 1;
int main()
{
    size_t number_count, bin_count, i, j, height;
    cout << "Enter number count: ";
    cin >> number_count;
    cout << "Enter bin count: ";
    cin >> bin_count;
    vector<size_t> bins(bin_count);
    vector<double> numbers(number_count);
    cout << "Enter numbers" << endl;
    for (i = 0; i < number_count; i++)
    {
        cin >> numbers[i];
    }
    cout << endl;
    double min = numbers[0];
    double max = numbers[0];
    for (double x : numbers)
    {
        if (x < min)
            min = x;
        else if (x > max)
            max = x;
    }
    cout << "min=" << min << " ";
    cout << "max=" << max << endl;
    double bin_size = (max - min) / bin_count;
    for (i = 0; i < number_count; i++)
    {
        bool found = false;
        for (j = 0; (j < bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
            bins[bin_count - 1]++;
    }
    double max_count = 0;
    cout << bin_size << endl;
    for (j = 0; j < bin_count; j++)
    {
        if (max_count < bins[j])

            max_count = bins[j];
    }
    size_t prev, sled;
    for (j = 0; j < bin_count; j++)
    {
        double koef = 1;
        if (max_count > MAX_ASTERISK)
            koef = (static_cast<double>(MAX_ASTERISK / max_count));
        height = static_cast<size_t>(bins[j] * koef);
        if (j != 0 && j != bin_count - 1)
        {
            prev = (bins[j - 1] * koef);

            sled = (bins[j + 1] * koef);
        }
        else
        {
            prev = (bins[bin_count - 2] * koef);
            sled = (bins[1] * koef);
        }
        if (bins[j] >= 100)
            cout << bins[j] << "|";
        if (bins[j] >= 10 && bins[j] < 100)
            cout << " " << bins[j] << "|";
        if (bins[j] < 10)
            cout << "  " << bins[j] << "|";
        for (int c = 0; c < height; c++)
        {
            bool height_prev = false;
            bool height_sled = false;
            if (c == prev - 1 && j != 0 && prev != height)
                height_prev = true;
            else
                height_prev = false;
            if (c == sled - 1 && j != bin_count - 1 && sled != height)
                height_sled = true;
            else
                height_sled = false;
            if (height_sled == true && height_prev == true)
                cout << "N";
            if (height_sled == false && height_prev == false)
                cout << "*";
            if (height_sled == false && height_prev == true)
                cout << "^";
            if (height_sled == true && height_prev == false)
                cout << "v";
        }
        cout << endl;
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
