#ifndef LISTA_DWUKIERUNKOWA_HPP
#define LISTA_DWUKIERUNKOWA_HPP

#include <iostream>

template <typename T>
class ListaDwukierunkowa {
private:
        struct Node {
                T data;
                Node* next;
                Node* prev;
        };
public:
        Node* start = nullptr;

        T firstElement() {
                if(start == nullptr){
                        std::cout << "Lista jest pusta";
                        return T(); // Return default-constructed value
                }
                return start->data;
        }

        T lastElement() {
                if(start==nullptr) {
                        std::cout << "Lista jest pusta";
                        return T(); // Return default-constructed value
                }
                Node* temp = start;
                while(temp->next){
                        temp = temp->next;
                }
                return temp->data;
        }

        T chosenElement(int i) {
                if(i < 1) {
                        std::cout << "Nie moze byc mniejsze niz 1";
                        return T(); // Return default-constructed value
                }
                else if(i == 1) {
                        return firstElement();
                }
                Node* temp = start;
                for (int j = 1; j < i-1 && temp; j++) {
                        temp = temp->next;
                }
                if (!temp) {
                        std::cout << "Poza zakresem";
                        return T(); // Return default-constructed value
                }
                return temp->data;
        }

        void addToTheFront(T value) {
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = start;
                newNode->prev = nullptr;
                start = newNode;
        }

        void addToTheBack(T value) {
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = nullptr;
                if(!start) {
                        start = newNode;
                        return;
                }
                Node* temp = start;
                while(temp->next) {
                        temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
        }

        void addToChosen(T value, int i) {
                if(i < 1) {
                        std::cout << "Nie moze byc mniejsze niz 1";
                        return;
                }
                else if(i == 1) {
                        addToTheFront(value);
                        return;
                }
                Node* newNode = new Node();
                newNode->data = value;
                Node* temp = start;
                for (int j = 1; j < i-1 && temp; j++) {
                        temp = temp->next;
                }
                if (!temp) {
                        std::cout << "Poza zakresem";
                        return;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
        }

        void removeFirst() {
                if (!start) {
                        std::cout << "Lista jest pusta" << std::endl;
                        return;
                }

                Node* temp = start;
                start = start->next;
                start->prev = nullptr;
                delete temp;
        };

        void removeLast() {
                if (!start) {
                        std::cout << "Lista jest pusta" << std::endl;
                        return;
                }

                if (!start->next) {
                        delete start;
                        start = nullptr;
                        return;
                }

                Node* temp = start;
                while(temp->next) {
                        temp = temp->next;
                }

                temp->prev->next = nullptr;
                delete temp;
        };

        void removeChosen(int i) {
        if (i < 1) {
                std::cout << "Indeks musi byc >= 1" << std::endl;
                return;
        }

        if (i == 1) {
                removeFirst();
                return;
        }

        Node* temp = start;
        for (int j = 1; j < i && temp; ++j) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
                std::cout << "Poza Lista." << std::endl;
                return;
        }
        Node* nodeToDelete = temp; 
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete nodeToDelete;            
        };
        int findSomething(T something) {
                Node* temp = start;
                int position = 0;
                while(temp->data != something && temp -> next) {
                        temp = temp->next;
                }
                if (temp->data == something) return position; 
                else {
                std::cout << "Not found" << std::endl;
                return 0;
                }
        }
};

#endif // LISTA_JEDNOKIERUNKOWA_HPP

