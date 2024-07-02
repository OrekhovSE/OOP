#include <iostream>
#include <string>

#include "ClassicSlotMachine.h"
#include "Gladiator.h"
#include "Failure.h"
#include "Success.h"

using namespace std;

int main() {
    // pattern - фабричный

 /*   Предметная область – игровые автоматы. Gladiator - игровая автомат наследуемый от SlotMachine с увеличивающимся джекпотом, 
        ClassicSlotMachine - игровая автомат наследуемый от SlotMachine в классическом варианте*/
    srand(time(0));
    Choice* choiceForGladiaror1 = new Failure("lost1, consolation prize = ");
    Choice* choiceForGladiaror2 = new Failure("lost2, consolation prize = ");
    Choice* choiceForGladiaror3 = new Failure("lost3, consolation prize = ");
    Choice* choiceForGladiaror4 = new Failure("lost4, consolation prize = ");
    Choice* choiceForGladiaror5 = new Success();

    int bet = 100;
    Gladiator gladiator{ 10000 };
    gladiator.addChoice(choiceForGladiaror1);
    gladiator.addChoice(choiceForGladiaror2);
    gladiator.addChoice(choiceForGladiaror3);
    gladiator.addChoice(choiceForGladiaror4);
    gladiator.addChoice(choiceForGladiaror5);

    gladiator.play(bet);
    gladiator.play(bet);
    gladiator.play(bet);
    gladiator.play(bet);
    gladiator.play(bet);
    gladiator.play(bet);


    cout << "-----------------------------------" << endl;

    ClassicSlotMachine classic{ 3 };
    Choice* choiceForClassic1 = new Failure("lost1, consolation prize = ");
    Choice* choiceForClassic2 = new Failure("lost2, consolation prize = ");
    Choice* choiceForClassic3 = new Failure("lost3, consolation prize = ");
    Choice* choiceForClassic4 = new Success();
    classic.addChoice(choiceForClassic1);
    classic.addChoice(choiceForClassic2);
    classic.addChoice(choiceForClassic3);
    classic.addChoice(choiceForClassic4);

    classic.play(bet);
    classic.play(bet);
    classic.play(bet);
    classic.play(bet);
    classic.play(bet);








    /*cout << "-----------------------------------" << endl;
    LinkedList<int> list;

    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.printList();
    cout << "-----------------------------------" << endl;
    LinkedList<int> list2{ list };
    list2.printList();

    LinkedList<int>::Iterator iter = list.begin();
    cout << *iter << endl;
    cout << *++iter << endl;
    cout << *++iter << endl;
    cout << *++iter << endl;
    cout << *++iter << endl;*/

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