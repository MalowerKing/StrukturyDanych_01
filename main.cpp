#include <iostream>
#include "lista_jednokierunkowa.hpp"
#include <fstream>
#include <chrono>
using namespace std;

ofstream myfile;

#define START_TIMER  begin = chrono::steady_clock::now();

#define STOP_TIMER   end = chrono::steady_clock::now();\
        myfile << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl; 

#define MEASURE_SOMETHING(function, desc) myfile << #desc " ";\
        START_TIMER;\
        function;\
        STOP_TIMER;

void measureListaJednokierunkowa() {
        myfile.open("ListaJednokierunkowaWyniki.txt", ios::app);
        ListaJednokierunkowa<int> Lista;
        
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        chrono::steady_clock::time_point end = chrono::steady_clock::now();

        for(int i = 0; i < 10; i++) {
                Lista.addToTheFront(i);
        }

        myfile << "10\n";

        MEASURE_SOMETHING(Lista.addToTheFront(2137), ADD_START);
        MEASURE_SOMETHING(Lista.removeFirst(), REMOVE_START);

        MEASURE_SOMETHING(Lista.addToTheBack(2137), ADD_BACK);
        MEASURE_SOMETHING(Lista.removeLast(), REMOVE_BACK);

        MEASURE_SOMETHING(Lista.addToChosen(2137, 7), ADD_CHOSEN);
        MEASURE_SOMETHING(Lista.removeChosen(7), REMOVE_CHOSEN);


        MEASURE_SOMETHING(Lista.firstElement(), RETURN_START);
        MEASURE_SOMETHING(Lista.lastElement(), RETURN_BACK);
        MEASURE_SOMETHING(Lista.chosenElement(7), RETURN_CHOSEN);

        for(int i = 0; i < 40; i++) {
                Lista.addToTheFront(i);
        }

        myfile << "50\n";

        MEASURE_SOMETHING(Lista.addToTheFront(2137), ADD_START);
        MEASURE_SOMETHING(Lista.removeFirst(), REMOVE_START);

        MEASURE_SOMETHING(Lista.addToTheBack(2137), ADD_BACK);
        MEASURE_SOMETHING(Lista.removeLast(), REMOVE_BACK);

        MEASURE_SOMETHING(Lista.addToChosen(2137, 37), ADD_CHOSEN);
        MEASURE_SOMETHING(Lista.removeChosen(37), REMOVE_CHOSEN);


        MEASURE_SOMETHING(Lista.firstElement(), RETURN_START);
        MEASURE_SOMETHING(Lista.lastElement(), RETURN_BACK);
        MEASURE_SOMETHING(Lista.chosenElement(37), RETURN_CHOSEN);

        for(int i = 0; i < 50; i++) {
                Lista.addToTheFront(i);
        }

        myfile << "100\n";

        MEASURE_SOMETHING(Lista.addToTheFront(2137), ADD_START);
        MEASURE_SOMETHING(Lista.removeFirst(), REMOVE_START);

        MEASURE_SOMETHING(Lista.addToTheBack(2137), ADD_BACK);
        MEASURE_SOMETHING(Lista.removeLast(), REMOVE_BACK);

        MEASURE_SOMETHING(Lista.addToChosen(2137, 67), ADD_CHOSEN);
        MEASURE_SOMETHING(Lista.removeChosen(67), REMOVE_CHOSEN);


        MEASURE_SOMETHING(Lista.firstElement(), RETURN_START);
        MEASURE_SOMETHING(Lista.lastElement(), RETURN_BACK);
        MEASURE_SOMETHING(Lista.chosenElement(67), RETURN_CHOSEN);

        for(int i = 0; i < 400; i++) {
                Lista.addToTheFront(i);
        }

        myfile << "500\n";

        MEASURE_SOMETHING(Lista.addToTheFront(2137), ADD_START);
        MEASURE_SOMETHING(Lista.removeFirst(), REMOVE_START);

        MEASURE_SOMETHING(Lista.addToTheBack(2137), ADD_BACK);
        MEASURE_SOMETHING(Lista.removeLast(), REMOVE_BACK);

        MEASURE_SOMETHING(Lista.addToChosen(2137, 377), ADD_CHOSEN);
        MEASURE_SOMETHING(Lista.removeChosen(377), REMOVE_CHOSEN);


        MEASURE_SOMETHING(Lista.firstElement(), RETURN_START);
        MEASURE_SOMETHING(Lista.lastElement(), RETURN_BACK);
        MEASURE_SOMETHING(Lista.chosenElement(377), RETURN_CHOSEN);

        for(int i = 0; i < 500; i++) {
                Lista.addToTheFront(i);
        }

        myfile << "1000\n";

        MEASURE_SOMETHING(Lista.addToTheFront(2137), ADD_START);
        MEASURE_SOMETHING(Lista.removeFirst(), REMOVE_START);

        MEASURE_SOMETHING(Lista.addToTheBack(2137), ADD_BACK);
        MEASURE_SOMETHING(Lista.removeLast(), REMOVE_BACK);

        MEASURE_SOMETHING(Lista.addToChosen(2137, 577), ADD_CHOSEN);
        MEASURE_SOMETHING(Lista.removeChosen(577), REMOVE_CHOSEN);


        MEASURE_SOMETHING(Lista.firstElement(), RETURN_START);
        MEASURE_SOMETHING(Lista.lastElement(), RETURN_BACK);
        MEASURE_SOMETHING(Lista.chosenElement(577), RETURN_CHOSEN);

        for(int i = 0; i < 4000; i++) {
                Lista.addToTheFront(i);
        }

        myfile << "5000\n";

        MEASURE_SOMETHING(Lista.addToTheFront(2137), ADD_START);
        MEASURE_SOMETHING(Lista.removeFirst(), REMOVE_START);

        MEASURE_SOMETHING(Lista.addToTheBack(2137), ADD_BACK);
        MEASURE_SOMETHING(Lista.removeLast(), REMOVE_BACK);

        MEASURE_SOMETHING(Lista.addToChosen(2137, 3777), ADD_CHOSEN);
        MEASURE_SOMETHING(Lista.removeChosen(3777), REMOVE_CHOSEN);


        MEASURE_SOMETHING(Lista.firstElement(), RETURN_START);
        MEASURE_SOMETHING(Lista.lastElement(), RETURN_BACK);
        MEASURE_SOMETHING(Lista.chosenElement(3777), RETURN_CHOSEN);

        for(int i = 0; i < 5000; i++) {
                Lista.addToTheFront(i);
        }

        myfile << "10000\n";

        MEASURE_SOMETHING(Lista.addToTheFront(2137), ADD_START);
        MEASURE_SOMETHING(Lista.removeFirst(), REMOVE_START);

        MEASURE_SOMETHING(Lista.addToTheBack(2137), ADD_BACK);
        MEASURE_SOMETHING(Lista.removeLast(), REMOVE_BACK);

        MEASURE_SOMETHING(Lista.addToChosen(2137, 7777), ADD_CHOSEN);
        MEASURE_SOMETHING(Lista.removeChosen(7777), REMOVE_CHOSEN);


        MEASURE_SOMETHING(Lista.firstElement(), RETURN_START);
        MEASURE_SOMETHING(Lista.lastElement(), RETURN_BACK);
        MEASURE_SOMETHING(Lista.chosenElement(7777), RETURN_CHOSEN);
}


int main() {
        measureListaJednokierunkowa();

};
