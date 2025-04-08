#include <iostream>
#include "lista_jednokierunkowa.hpp"
#include "lista_dwubiegunowa.hpp"
#include "lista_rotujaca.hpp"
#include "lista_dwubiegunowa_tail.hpp"
#include "Tablica_Dynamiczna.hpp"
#include <fstream>
#include <chrono>
using namespace std;

ofstream myfile;

#define START_TIMER  begin = chrono::steady_clock::now();

#define STOP_TIMER   end = chrono::steady_clock::now();\
        myfile << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << ","; 

#define MEASURE_SOMETHING(function) START_TIMER;\
        function;\
        STOP_TIMER;

#define MEASURE_EVERYTHING(klasa) myfile.open(#klasa ".csv", ios::app); \
        klasa<int> Lista; \
        myfile << "SIZE,ADD_FRONT,REMOVE_FRONT,ADD_BACK,REMOVE_BACK,ADD_CHOOSEN,REMOVE_CHOOSEN,RETURN_FRONT,RETURN_BACK,RETURN_CHOOSEN,FIND\n"; \
        chrono::steady_clock::time_point begin = chrono::steady_clock::now(); \
        chrono::steady_clock::time_point end = chrono::steady_clock::now(); \
        for(int i = 0; i < 10; i++) { \
                Lista.addToTheFront(i); \
        } \
\
        for(int i = 0; i < 100; i++) { \
        myfile << "10," ; \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 7)); \
        MEASURE_SOMETHING(Lista.removeChosen(7)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(7)); \
        MEASURE_SOMETHING(Lista.findSomething(8)); \
        myfile << "\n"; \
        } \
        for(int i = 0; i < 40; i++) { \
                Lista.addToTheFront(i); \
        } \
\
        for(int i = 0; i < 100; i++) { \
        myfile << "50,"; \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 37)); \
        MEASURE_SOMETHING(Lista.removeChosen(37)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(37)); \
        MEASURE_SOMETHING(Lista.findSomething(38)); \
        myfile << "\n"; \
        } \
        for(int i = 0; i < 50; i++) { \
                Lista.addToTheFront(i); \
        } \
 \
        for(int i = 0; i < 100; i++) { \
        myfile << "100,"; \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 67)); \
        MEASURE_SOMETHING(Lista.removeChosen(67)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(67)); \
        MEASURE_SOMETHING(Lista.findSomething(50)); \
        myfile << "\n"; \
        } \
        \
        for(int i = 0; i < 400; i++) { \
                Lista.addToTheFront(i); \
        } \
 \
        for(int i = 0; i < 100; i++) { \
        myfile << "500,"; \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 377)); \
        MEASURE_SOMETHING(Lista.removeChosen(377)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(377)); \
        MEASURE_SOMETHING(Lista.findSomething(100)); \
        myfile << "\n"; \
        } \
        for(int i = 0; i < 500; i++) { \
                Lista.addToTheFront(i); \
        } \
 \
        for(int i = 0; i < 100; i++) { \
        myfile << "1000,"; \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 577)); \
        MEASURE_SOMETHING(Lista.removeChosen(577)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(300)); \
        myfile << "\n"; \
        }        \
 \
        for(int i = 0; i < 4000; i++) { \
                Lista.addToTheFront(i); \
        } \
 \
        for(int i = 0; i < 100; i++) { \
        myfile << "5000,"; \
 \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 3777)); \
        MEASURE_SOMETHING(Lista.removeChosen(3777)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(3777)); \
        MEASURE_SOMETHING(Lista.findSomething(3500)); \
        myfile << "\n"; \
        } \
 \
        for(int i = 0; i < 5000; i++) { \
                Lista.addToTheFront(i); \
        } \
 \
        for(int i = 0; i < 100; i++) { \
        myfile << "10000,"; \
 \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 7777)); \
        MEASURE_SOMETHING(Lista.removeChosen(7777)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(7777)); \
        MEASURE_SOMETHING(Lista.findSomething(4000)); \
        myfile << "\n"; \
        } \
        myfile.close();

void measureListaJednokierunkowa() {
        cout << "ListaJednokierunkowa" << endl;
        MEASURE_EVERYTHING(ListaJednokierunkowa); 
        }

void measureListaDwukierunkowa() {
        cout << "ListaDwukierunkowa" << endl;
        MEASURE_EVERYTHING(ListaDwukierunkowa); 
}
void measureListaJednokierunkowaTail() {
        cout << "ListaJednokierunkowaTail" << endl;
        MEASURE_EVERYTHING(ListaJednokierunkowaTail); 
}
void measureListaDwukierunkowaTail() {
        cout << "ListaDwukierunkowaTail" << endl;
        MEASURE_EVERYTHING(ListaDwukierunkowaTail); 
}
void measureTablica() {
        cout << "Tablica" << endl;
        MEASURE_EVERYTHING(Tablica);
}
int main() {
        measureListaJednokierunkowa();
        measureListaDwukierunkowa();
        measureListaJednokierunkowaTail();
        measureListaDwukierunkowaTail();
        measureTablica();
};
