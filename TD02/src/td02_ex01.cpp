#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"

// -----------------------------------------------------------------------------------------------------------------

// pour échanger deux valeurs
void swap_int(int * a, int * b){
    int temp {*a};
    *a = *b;
    *b = temp;
};
void swap_float(float * a, float * b){
    float temp {*a};
    *a = *b;
    *b = temp;
};

// pour vérifier si le tableau est trier
bool is_sorted_int(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}
bool is_sorted_float(std::vector<float> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

// EXO 1 trie itératif - bubble sort ----------------------------------------------------------------------------------------
void bubble_sort(std::vector<int> & vec){
    while(is_sorted_int(vec) == false){
        for( unsigned int i {0}; i<vec.size()-1; i++){
            if( vec[i] > vec[i+1]){
                swap_int(&vec[i],&vec[i+1]);
            }
        }    
    }
}

// EXO 2 tri récursif - trie rapide -------------------------------------------------------------------------------------------

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot){
    float const val_pivot = vec[pivot];
    size_t big_ele_index {left};
    swap_float(&vec[pivot],&vec[right]);

    for (size_t i {left}; i<right; i++){
        if ( vec[i] < val_pivot){
            swap_float(&vec[i],&vec[left]);
            big_ele_index += 1;
        }
    }
    swap_float(&vec[big_ele_index], &vec[right]);

    return big_ele_index;
};

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right){
    if (left>= right){
        return;
    }

    size_t pivot { left + (right-left)/2};
    pivot = quick_sort_partition (vec, left, right, pivot);
    if (pivot >0){
        quick_sort(vec, left, pivot-1);
    }
    quick_sort (vec, pivot+1, right);
};


void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

// EXO 3 - Comparaison des algorithmes de tri ---------------------------------------------------------------------------------

// fonction qui génére un tableau d'entiers aléatoires
std::vector<int> generate_random_vector_int(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
};

std::vector<float> generate_random_vector_float(size_t const size, int const max = 100) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
};

// EXO 4 - Dichotomie -------------------------------------------------------------------------------------------------------

int search (std::vector<int> & vec, int val){
    int left {0};
    int right {static_cast<int>(vec.size()) -1 };
    while (left <= right) {
        int middle = (left + right)/2;

        if( vec[middle] == val){
            return middle +1 ;
        }
        if ( vec[middle] < val){
            left = middle+1;
        }
        else {
            right = middle-1;
        }
    }
    return -1;
}



int main()
{
    std::vector<int> array_bubble = generate_random_vector_int(100);
    std::vector<float> array_quick = generate_random_vector_float(100);
    std::vector<int> array_std_sort = generate_random_vector_int(100);
    

    
    // ex3
    {ScopedTimer timer_bubble("Chrono Buble sort");
        bubble_sort(array_bubble);
    }
    {ScopedTimer timer_quick("Chrono quick sort");
        quick_sort(array_quick);
    }
    {ScopedTimer timer_std_sort("Chrono std::sort");
        std::sort(array_std_sort.begin(), array_std_sort.end());
    }

//  On peut remarquer que le quick sort est le plus rapide des tries devant le std::sort et le trie bulle.


    // ex1
    bubble_sort(array_bubble);

    // ex2
    quick_sort(array_quick);

    
    if (is_sorted_float(array_quick) ) {
        std::cout << "Le tableau est trie"<< std::endl;
    }
    else {
    std::cout << "Le tableau n'est pas trie" << std::endl;
    }
    // for( unsigned int i {0}; i<array_quick.size(); i++){
    //     std::cout <<" "<<array_quick[i];
    // }
    

    // ex4 
    std::vector<int> liste1 {1, 2, 2, 3, 4, 8, 12};
    std::vector<int> liste2 {1, 2, 3, 3, 6, 14, 12, 15};
    std::vector<int> liste3 {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::vector<int> liste4 {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> liste5 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout<<"la valeure 8 est le "<<search(liste1,8)<<" element de la liste "<< std::endl;
    std::cout<<"la valeure 15 est le "<<search(liste2,15)<<" element de la liste "<< std::endl;
    std::cout<<"la valeure 16 est le "<<search(liste3,16)<<" element de la liste "<< std::endl;
    std::cout<<"la valeure 6 est le "<<search(liste4,6)<<" element de la liste "<< std::endl;
    std::cout<<"la valeure 10 est le "<<search(liste5,10)<<" element de la liste "<< std::endl;

    return 0;
}