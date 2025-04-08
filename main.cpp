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
        MEASURE_SOMETHING(Lista.findSomething(7)); \
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
        MEASURE_SOMETHING(Lista.addToChosen(2137, 35)); \
        MEASURE_SOMETHING(Lista.removeChosen(35)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(35)); \
        MEASURE_SOMETHING(Lista.findSomething(35)); \
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
        MEASURE_SOMETHING(Lista.addToChosen(2137, 70)); \
        MEASURE_SOMETHING(Lista.removeChosen(70)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(45)); \
        MEASURE_SOMETHING(Lista.findSomething(45)); \
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
        MEASURE_SOMETHING(Lista.addToChosen(2137, 350)); \
        MEASURE_SOMETHING(Lista.removeChosen(350)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(350)); \
        MEASURE_SOMETHING(Lista.findSomething(350)); \
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
        MEASURE_SOMETHING(Lista.addToChosen(2137, 700)); \
        MEASURE_SOMETHING(Lista.removeChosen(700)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(700)); \
        MEASURE_SOMETHING(Lista.findSomething(450)); \
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
        MEASURE_SOMETHING(Lista.addToChosen(2137, 3500)); \
        MEASURE_SOMETHING(Lista.removeChosen(3500)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(3500)); \
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
        MEASURE_SOMETHING(Lista.addToChosen(2137, 7000)); \
        MEASURE_SOMETHING(Lista.removeChosen(7000)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(7000)); \
        MEASURE_SOMETHING(Lista.findSomething(4500)); \
        myfile << "\n"; \
        } \
 \
        for(int i = 0; i < 40000; i++) { \
                Lista.addToTheFront(i); \
        } \
        for(int i = 0; i < 100; i++) { \
        myfile << "50000,"; \
 \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 35000)); \
        MEASURE_SOMETHING(Lista.removeChosen(35000)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(35000)); \
        MEASURE_SOMETHING(Lista.findSomething(35000)); \
        myfile << "\n"; \
        } \
  \
        for(int i = 0; i < 50000; i++) { \
                Lista.addToTheFront(i); \
        } \
        for(int i = 0; i < 100; i++) { \
        myfile << "100000,"; \
 \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 70000)); \
        MEASURE_SOMETHING(Lista.removeChosen(70000)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(70000)); \
        MEASURE_SOMETHING(Lista.findSomething(45000)); \
        myfile << "\n"; \
        } \
  \
        for(int i = 0; i < 400000; i++) { \
                Lista.addToTheFront(i); \
        } \
        for(int i = 0; i < 100; i++) { \
        myfile << "500000,"; \
 \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 140000)); \
        MEASURE_SOMETHING(Lista.removeChosen(140000)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(140000)); \
        MEASURE_SOMETHING(Lista.findSomething(350000)); \
        myfile << "\n"; \
        } \
        for(int i = 0; i < 500000; i++) { \
                Lista.addToTheFront(i); \
        } \
        for(int i = 0; i < 100; i++) { \
        myfile << "1000000,"; \
 \
        MEASURE_SOMETHING(Lista.addToTheFront(2137)); \
        MEASURE_SOMETHING(Lista.removeFirst()); \
        MEASURE_SOMETHING(Lista.addToTheBack(2137)); \
        MEASURE_SOMETHING(Lista.removeLast()); \
        MEASURE_SOMETHING(Lista.addToChosen(2137, 280000)); \
        MEASURE_SOMETHING(Lista.removeChosen(280000)); \
        MEASURE_SOMETHING(Lista.firstElement()); \
        MEASURE_SOMETHING(Lista.lastElement()); \
        MEASURE_SOMETHING(Lista.chosenElement(280000)); \
        MEASURE_SOMETHING(Lista.findSomething(450000)); \
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
