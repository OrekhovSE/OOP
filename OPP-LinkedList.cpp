#include <iostream>
#include <string>

#include "FireShalter.h"
#include "IceShalter.h"
#include "Master.h"
#include "Disciple.h"

using namespace std;

int main() {
    // pattern - фабричный в классах Shalter, Culrist

 /*   Предметная область – аналитика жертвоприношений.Чтобы быть культистом не обязательно быть умным, 
        достаточно иметь сильную веру, поэтому многие не могут считать и поэтому постоянно вовремя жертвоприношений совершаются ошибки
        из - за которых приходиться начинать все сначала.Эта программа позволит избежать этих ошибок.
        Во время жертвоприношений культисты встают в круг и передают эстафету через конкретное кол - во шагов,
        в разных “Убежищах” разные условия передачи эстафеты,
        также у разных культистов разный метод жертвоприношений.
        Жертвоприношение заканчивается пока не выполняться определенные условия или не останется культистов.*/

   Cultist* c1 = new Master("vo ima matana", "master1");
    Cultist* c2 = new Master("vo ima matana", "master2");
    Cultist* c3 = new Master("vo ima matana", "master3");
    Cultist* c4 = new Disciple("vo ima matana", "master4");
    Cultist* c5 = new Disciple("vo ima matana", "master5");
    Cultist* c6 = new Disciple("vo ima matana", "master6");

    FireShalter fire;
    fire.addCultist(c1);
    fire.addCultist(c3);
    fire.addCultist(c5);



    IceShalter ice;
    ice.addCultist(c2);
    fire.addCultist(c4);
    fire.addCultist(c6);
    
    ice.sacrificing(10);

    fire.sacrificing(3);

    

    return 0;
}



























/*

int main() {
    LinkedList<char> list{};
    LinkedList<char> list2{};
    list.insertNode('a');
    list.insertNode('b');
    list.insertNode('c');


    list2 = list;
    list.deleteNode(3);
    list.insertNode('a');


    std::cout << "list = ";
    list.printList();
    std::cout << "list2 = ";
    list2.printList();


    std::cout << "1) (list != list2) = " + to_string((list != list2)) + " \n";

    std::cout << "2) (list == list2) = " + to_string((list == list2)) + " \n";

    std::cout << "3) list.swap(list2): \n";
    list.swap(list2);
    std::cout << "list = ";
    list.printList();
    std::cout << "list2 = ";
    list2.printList();

    std::cout << "4) list.size() = " + to_string(list.size()) + "\n";

    std::cout << "5) list.max_size() = " + to_string(list.max_size()) + "\n";

    std::cout << "6) list.empty() = " + to_string(list.empty()) + "\n";

    std::cout << "7) list = list 2 \n";
    list = list2;
    std::cout << "list = ";
    list.printList();
    std::cout << "list2 = ";
    list2.printList();



    LinkedList<int> listforiterator{};
    listforiterator.insertNode(1);
    listforiterator.insertNode(2);
    listforiterator.insertNode(2);
    listforiterator.insertNode(4);
    listforiterator.insertNode(2);
    listforiterator.insertNode(32);
    listforiterator.insertNode(-1);
    listforiterator.insertNode(-1024);
    listforiterator.insertNode(1);
    listforiterator.insertNode(1024 * 1024);


    LinkedList<int>::Iterator iterator = listforiterator.createIterator();

    cout << "cheak iterator" << endl;
    cout << "list : ";
    listforiterator.printList();
    cout << "*iterator : ";
    cout << *iterator << endl;

    iterator++;
    cout << "iterator++: ";
    cout << *iterator << endl;

    cout << "iterator++: ";
    iterator++;
    cout << *iterator << endl;

    cout << "iterator++: ";
    iterator++;
    cout << *iterator << endl;

    cout << "iterator++: ";
    iterator++;
    cout << *iterator << endl;

    cout << "iterator++: ";
    iterator++;
    cout << *iterator << endl;

    cout << iterator. << endl;
    cout << "cheak iterator " << endl;

    return 0;
}*/