#include<iostream>

int main(){
    int zahl = 10;
    int* p = &zahl; // p zeigt auf die Adresse von zahl

    std::cout << "Wert von zahl: " << zahl << std::endl;
    std::cout << "Adresse von zahl: " << p << std::endl;
    std::cout << "Wert über Pointer: " << *p << std::endl;
}
