// Jack Cwynar
// jec0089
// 03/08/2021
// File name: project4_Cwynar_jec0089.cpp
// My Compiler Version: Apple clang version 12.0.0 (clang-1200.0.32.28)
// To compile, use default g++ compiler on server.
// Used lectures, notes, and Dr. Li's template provided on Canvas to finish Project 4.
// Use cplusplus.com to learn more about linked lists and structures.

#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>
using namespace std;

//Creating linked list that holds a trivia question, answer, and point amount.
struct trivia_node {
    string question;
    string answer;
    int point;
    trivia_node *next;
};

// Initializes quiz to have 3 questions inputted into list
void question_list(trivia_node &n1, trivia_node &n2, trivia_node &n3) {
    n1.question = "How long was the longest war on record? (Hint: how many minutes)";
    n1.answer = "38";
    n1.point = 100;
    n1.next = &n2;

    n2.question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    n2.answer = "Bank of Italy";
    n2.point = 50;
    n2.next = &n3;

    n3.question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
    n3.answer = "Wii Sports";
    n3.point = 20;
    n3.next = NULL;
}

void add_user_question(trivia_node *head) {
        string cont;
        do {
            trivia_node *next = new trivia_node;
            while (next->question == "") {
                cout << "Enter a question: ";
                getline(cin, next->question);
            }
            while (next->answer == "") {
                cout << "Enter an answer: ";
                getline(cin, next->answer);
            }
            cout << "Enter award points: ";
            cin >> next->point;
            while (cin.fail()) {
                // clear input
                cin.clear();
                cin.ignore();
                cout << "Please enter an integer value." << endl;
                cin >> next->point;
            }
            cin.ignore();
            // new last node
            next->next = NULL;

            if (head->question == "") {
                *head = *next;
            }
            else {
                // Temporary pointer
                trivia_node *temp = head;
                while (temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = next;
            }
            cout << "Continue? (Yes/No): ";
            getline(cin, cont);
            transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
            while (cont != "yes" && cont != "no") {
                cout << "Please enter \"Yes\" or \"No\"" << endl;
                getline(cin, cont);
                transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
            }
        } while (cont == "yes");
}

//check num of questions - friend helped me with this one
int number_of_questions(trivia_node *head) {
    int length = 0;
    trivia_node *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

int ask_question(trivia_node *head, int num_ask) {

    int player_points = 0;

    if (head == NULL)
        return 0;
    if (num_ask < 1) {
        cout << "Warning - the number of trivia questions to be asked must be equal to or be larger than 1.";
    }
    else if (number_of_questions(head) < num_ask) {
        cout << "Warning - There is only " << number_of_questions(head) << " trivia questions in the list.";
    }
    else {
        string user_answer;

        trivia_node *cur_ptr = head;
        for (int i = 0; i < num_ask; i++) {
            cout << "Question: " << cur_ptr->question << endl;
            cout << "Type Your Answer: ";
            getline(cin, user_answer);
            if (user_answer.compare(cur_ptr->answer) == 0) {
                cout << "Correct! You are awarded " << cur_ptr->point << " points." << endl;
                player_points += cur_ptr->point;
            }
            else {
                cout << "Your answer is wrong. The correct answer is: " << cur_ptr->answer << endl;
            }
            cur_ptr = cur_ptr->next;
            cout << "\nYour total points: " << player_points << endl;
        }
    }
    return player_points;
}

//Test cases.
void Unit_Test() {
    cout << "*** This is a debugging version ***\n";

    int total_points = 0;
    trivia_node n1, n2, n3;
    question_list(n1, n2, n3);

    cout << "Unit Test Case 1; Ask no question. The program should give a warning message." << endl;
    ask_question(&n1, 0);
    cout << "\nCase 1 Passed\n\n";

    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
    total_points = ask_question(&n1, 1);
    assert(total_points == 0);
    cout << "\nCase 2.1 Passed\n\n";

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
    total_points = ask_question(&n1, 1);
    assert(total_points != 0);
    cout << "\nCase 2.2 Passed\n\n";

    cout << "Unit Test Case 3: Ask all the questions in the linked list." << endl;
    total_points = ask_question(&n1, 3);
    assert(total_points != 0);
    cout << "\nCase 3 Passed\n\n";

    cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    total_points = ask_question(&n1, 5);
    assert(total_points == 0);
    cout << "\nCase 4 Passed\n\n";

    cout << "\n\n*** End of the Debugging Version ***" << endl;
}

#define trivia_quiz

int main() {
    Unit_Test();

#ifdef trivia_quiz
    string input;
    int numberQuestions;
    trivia_node n1, n2, n3;
    question_list(n1, n2, n3);

    cout << "*** Welcome to Jack's trivia quiz game ***\n";

    cout << "Would you like to add a question? (Yes/No)" << endl;
    getline(cin,input);

    if(input == "Yes" || "yes"){
         add_user_question(&n1);
    }

    //This is the start of the Trivia quiz game.
    cout << "How many questions would you like to answer? " << endl;
    cin >> numberQuestions;
    cin.ignore();
    ask_question(&n1, numberQuestions);
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
    return 0;
#endif
    
#ifdef UNIT_TESTING
    Unit_Test();
    return 0;
#endif
}
