#include "slidingwindowmax.h"
#include "priorityqueue.h"
#include <algorithm>
#include <string>
#include <fstream>
#include <map>
//13. Алгоритм Рабина-Карпа с алгоритмами STL и хранением скользящего хэша в векторе

//====================================================================================
void Task1()
{
    const std::vector<int> Test = {9, 7, 2, 4, 6, 8, 2, 1, 5}; //Output: 9 7 6 8 8 8 5
    SlidingWindowMax       Kitty(Test,3);                      //SlidingWindowMax(argFirst  = vector<int>,
                                                               //                 argSecond = int )
}
//====================================================================================
void Task2()
{
    PriorityQueue q;
    std::vector<int> Test = {9, 7, 2, 4, 6, 8, 2, 1, 5};
    for (std::size_t i = 0; i < Test.size(); ++i)
        q.Insert(Test[i],i);
    q.Show();
    q.Pop();
    q.Show();
}
//====================================================================================
void Task4(int N, std::vector<int> v)
{
    ///Ищем первый чётный эл-т после максимального
    /// выводим расстояние до него distance()
    /// выводим его значение
    /// свапаем с концом вектора и удаляем (про порядок вектора слова не было)
    for (auto it : v)
        std::cout << "\t" << it;

    std::cout << "\n";
    auto it = std::find_if(std::max_element(v.begin(),v.end()),
                           v.end(),
                           [](int n){return (n%2) == 0;});
    std::cout << "Distance to element = " << std::distance(v.begin(), it)
              << "\tElement = " << *it << "\n";

    std::swap(v[std::distance(v.begin(), it)], v[v.size()-1]); //O(1) remove
    v.resize(N-1);

    std::cout << "Array after delete elm: ";
    for (auto it : v)
        std::cout << "\t" << it;
}

//====================================================================================
void Task5(std::istream& FileName)
{
    std::map<std::string, int> words;
    std::string word;
    while (FileName >> word)
        ++words[word];

    for (auto it : words)
        std::cout << it.first << ": " << it.second << std::endl;
}
//====================================================================================
void Task6(std::vector<int> v)
{
    std::cout << "Count 0<Elem = " << std::count_if(v.begin(),v.end(), [](int n) {return n > 0;});

}
//====================================================================================
void Task7(std::string str)
{
    std::sort(str.begin(), str.end(), std::greater<>());

    do {
        std::cout << str << std::endl;
    } while (std::prev_permutation(str.begin(), str.end()));
}
//====================================================================================
struct Student
{
    std::string name;
    int age;
    int AverageMark;
};
bool comp (Student First, Student Second)
{
    return First.AverageMark > Second.AverageMark; //для убывания поменяйте знак
}
void Task8(std::vector<Student> v)
{
    std::cout <<'\n';
    for (auto it : v)
        std::cout << it.name << "\t" << it.age<<"\t"<<it.AverageMark <<'\n';
    std::sort(v.begin(),v.end(),comp);
    std::cout <<'\n';
    for (auto it : v)
        std::cout << it.name << "\t" << it.age<<"\t"<<it.AverageMark << '\n';
}

//====================================================================================
void Task9(std::vector<int> v)
{
    int focus = (rand()%100+0);
    std::cout << "\nFocus = " << focus << "\n";
    if (focus >= 50)
        std::rotate(v.rbegin(), v.rbegin() + (rand()%v.size() + 0), v.rend()); //направо
    else
        std::rotate(v.begin(), v.begin() + ((rand()%v.size() + 0)%v.size()), v.end()); //налево

    for (auto it : v)
        std::cout << "\nElement = " << it;
}
//====================================================================================
void Task10(std::vector<int>& arifm, std::vector<int>& geom)
{
    int step = rand()%10 - 10;
    int firstElem = rand()%10 - 10;
    int countOfElem = rand()%10 + 1; //от 1 до 10 элементов в векторах
    arifm.push_back(firstElem);
    geom.push_back( firstElem);
    for (std::size_t i = 0; i < countOfElem-1;++i)
    {
        arifm.push_back(arifm[i] + step);
        geom.push_back(geom[i] * step);
    }
    std::cout <<"\nАрифметическая прогрессия\n ";
    for (auto it : arifm)
    {
        std::cout << "\t " << it;
    }
    std::cout <<"\nГеометрическая прогрессия\n ";
    for (auto it : geom)
    {
        std::cout << "\t " << it;
    }
}
//====================================================================================
void Task11(std::vector<int>& x,std::vector<int>& h)
{
    srand(0);
    std::vector<int> y;
    int countOfElem = rand()%10 + 1;
    for (std::size_t i = 0; i < countOfElem;++i)
    {
        x.push_back((rand()%10 + 1));
        std::cout << "\nX[i] = " << x[i];
        h.push_back((rand()%10 + 1));
        std::cout << "\th[i] = " << h[i];
    }
    std::cout<<'\n';
    int tempSum = 0;
    for (std::size_t i = 0; i < x.size(); ++i)
    {
        for (std::size_t j = 0; j <= i;++j)
        {
            tempSum+= x[j]*h[i-j];
        }
        y.push_back(tempSum);
        tempSum = 0;
    }
    for (auto it : y)
        std::cout <<"\t" << it;
}
//====================================================================================

int main(int argc, char *argv[])
{
    srand(time(0));
    //    Task1(); //Задача: Поиск максимума в скользящем окне (за линейное время в лучшем случае) (для О(n) - stack, deque;)
    //    Task2(); // Собственная реализация std::priority_que

    //    ======================================================================================
    //    int N = 0;
    //    std::cout <<"\nВведите кол-во элементов: ";
    //    std::cin >> N;
    //    std::vector<int> v(N);
    //    std::cout <<"\nВводите элементы: \n";
    //    for (std::size_t i = 0; i < N; ++i)
    //    {
    //        std::cin >> v[i];
    //        std::cout <<"\n";
    //    }
    //    Task4(9,{9, 7, 2, 4, 6, 8, 2, 1, 5}); //4. Исключить из массива первый четный элемент, следующий за максимальным.
    //    ======================================================================================
    //    std::ifstream in("Text.txt");
    //    Task5(in); //5. Напишите функцию, принимающую имя файла с текстом и подсчитывающую частоту встречающихся в нём слов. Каждая линия вывода имеет формат:
    //    <Слово>: <Сколько раз встречается это слово>
    //    Task6({1,2,3,4,5,6,7,8,9,-1,-2,-3,-4});//6. Напишите функцию для подсчета положительных значений в векторе численных значений
    //    Task7("help"); //7.	Написать функцию, принимающую произвольную строку и выводящую все её перестановки
    //    std::vector<Student> v(5);
    //    for (int i = 0; i < v.size(); ++i)
    //    {
    //        v[i].name = char(rand()%26+0x61);
    //        v[i].age = rand()%10 + 100;
    //        v[i].AverageMark = rand()+5;
    //    }
    //    Task8(v);//8.	Студент имеет имя, возраст и средний балл. Напишите функцию, сортирующую студентов в порядке возрастания среднего балла.
    //    Напишите функцию, сортирующую студентов в порядке убывания среднего балла.
    //    Task9({1,2,3,4,5,6,7,8,9}); //9.	Напишите функцию, принимающую последовательность,
    //      выполняющую её циклический сдвиг в произвольном направлении на произвольное число элементов, и выводящую результат.
    //    std::vector<int> arifm,geom;
    //    Task10(arifm, geom);    //10. Используя алгоритмы stl сгенерировать арифметическцую прогрессию и геометрическую прогрессию
    //    std::vector<int> x,h;
    //    Task11(x,h); //11. Реализовать дискретную свёртку на stl и две сгенерировать последовательности
    
    //Задача 3 победила и я не смог её в фуннкцию засунуть
    //    std::vector<int> nums;
    //    std::ifstream iFile(argv[1]);
    //    int temp = 0;
    //    while (!iFile.eof()) {
    //        iFile >> temp;
    //        nums.push_back(temp);
    //    }

    //    auto it = std::unique(nums.begin(), nums.end());
    //    nums.resize(std::distance(nums.begin(), it)); //вообще по хорошему надо еще shrink_to_fit использовать

    //    int countOne = count(nums.begin(), nums.end(), 1);
    //    int countZero = count(nums.begin(), nums.end(), 0);

    //    std::ofstream oFile;
    //    oFile.open(argv[2]);
    //    oFile << countOne << " " << countZero;
}
