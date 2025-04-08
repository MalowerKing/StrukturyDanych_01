#ifndef TABLICA_HPP
#define TABLICA_HPP

#include <iostream>

template <typename T>
class Tablica {
private:
        int arraySize = 32; 
        int filled = 0;
        T* arr = new T[arraySize];

       void increaseSize() {
                T* temp = arr;
                arraySize *= 2;
                T* newArray = new T[arraySize];
                for(int i =0; i < (arraySize/2); i++) {
                newArray[i] = temp[i];
                }
                arr = newArray;
                delete [] temp;
        }
public:

        T firstElement() {return arr[0];}        
        T lastElement() {return arr[filled];}

        T chosenElement(int i) {
                if ( i < 0 || i > filled) {
                        std::cout << "Out of Scope" << std::endl;
                        return T();
                }
                return arr[i];
        }

        void addToTheFront(T value) {
                if(filled == arraySize) increaseSize();                
                filled++;
                T* newArray = new T[arraySize];
                T* temp = arr;
                newArray[0] = value;
                for(int i = 1; i <= filled; i++) {
                        newArray[i] = arr[i-1];
                }
                arr = newArray;
                delete [] temp;
        }

        void addToTheBack(T value) {
                if(filled == arraySize) increaseSize();
                filled++;
                arr[filled] = value;
                }

        void addToChosen(T value, int i) {
                if(i < 0 || i > filled+1) {
                        std::cout << "Out of Scope" << std::endl;
                        return;
                }
                if(filled == arraySize) increaseSize();
                filled++;
                T temp;
                for(int j = filled; j > i; j--){
                        arr[j] = arr[j-1];
                }
                arr[i] = value;
        }

        void removeFirst() {
                filled--;
                for(int i = 0; i <= filled; i++) {
                        arr[i] = arr[i+1];
                }
        };

        void removeLast() {
                filled--;
        };

        void removeChosen(int i) {
                filled--;
                for(int j = i; j <= filled; j++){
                        arr[j] = arr[j+1];
                }
        };

        int findSomething(T something) {
                for(int i = 0; i <= filled; i++){
                        if(arr[i] == something) return i;
                }
                std::cout << "Not found" << std::endl;
                return int();
        }
};

#endif // LISTA_JEDNOKIERUNKOWA_HPP


