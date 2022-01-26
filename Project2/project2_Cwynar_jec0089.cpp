// Jack Cwynar
// jec0089
// File name: project2_Cwynar_jec0089.cpp
// My Compiler Version: Apple clang version 12.0.0 (clang-1200.0.32.28)
// To compile, use default g++ compiler on server.
// Used lectures and Dr. Li's template provided on Canvas to finish Project 2.
// Used learncpp.com to learn more about global variables.
// Used https://stackoverflow.com/questions/21257544/c-wait-for-user-input to get help with
// program expecting two presses of "Enter."

// Inclusions
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <iomanip>
using namespace std;

// Global Variables
int aWins = 0;
int bWins = 0;
int cWins = 0;

// Prototypes

// Input :
// A_alive is for Aaron, true for alive, false for dead
// B_alive for Bob
// C_alive for Charlie
// Return:
// True if at least 2 alive, false otherwise
bool atLeastTwoAlive(bool A_alive, bool B_alive, bool C_alive);

// Begin Strategy 1: everyone shoots highest accuracy player
// Input:
// B_alive indicates Bob is alive/dead
// C_alive indicates Charlie is alive/dead
// Return:
// Change B_alive to false if Bob is killed
// Change C_alive to flase if Charlie is killed
void AaronShoots1(bool& B_alive, bool& C_alive);

// Input:
// A_alive indicates Bob is alive/dead
// C_alive indicates Charlie is alive/dead
// Return:
// Change A_alive to false if Bob is killed
// Change C_alive to flase if Charlie is killed
void BobShoots(bool& A_alive, bool& C_alive);

// Input:
// A_alive indicates Bob is alive/dead
// B_alive indicates Charlie is alive/dead
// Return:
// Change A_alive to false if Bob is killed
// Change B_alive to flase if Charlie is killed
void CharlieShoots(bool& A_alive, bool& B_alive);

// Beging Strategy 2
// Input:
// B_alive indicates whether Bob alive or dead
// C_alive indicates whether Charlie is alive or dead
// Return:
// Change B_alive into false if Bob is killed
// Change C_alive into false if Charlie is killed
void AaronShoots2(bool& B_alive, bool& C_alive);

void strategy1(void);
void strategy2(void);

void pressAnyKey(void);

// Test Prototypes
void testAtLeastTwoAlive(void);
void testAaronShoots1(void);
void testBobShoots(void);
void testCharlieShoots(void);
void testAaronShoots2(void);

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    const int NUMBER_OF_DUELS = 10000;
    srand(time(0));
    cout << "*** Welcome to Jack's Duel Simulator ***\n";
    
    // Tests
    testAtLeastTwoAlive();
    pressAnyKey();
    
    testAaronShoots1();
    pressAnyKey();
    
    testBobShoots();
    pressAnyKey();
    
    testCharlieShoots();
    pressAnyKey();
    
    testAaronShoots2();
    pressAnyKey();
    
    // Strategy 1 (10000 duels)
    cout << "Ready to test Strategy 1 (run 10000 times):\n";
    pressAnyKey();
    
    int duels = 0;
    while (duels < NUMBER_OF_DUELS) {
        strategy1();
        duels++;
    }
    
    // Precentage Calculation
    double aPercent = (double) aWins / (double) NUMBER_OF_DUELS;
    double bPercent = (double) bWins / (double) NUMBER_OF_DUELS;
    double cPercent = (double) cWins / (double) NUMBER_OF_DUELS;
    
    // Code to compare strategies for final line of output
    int aWins1 = aWins;
    cout << "Aaron won " << aWins << "/" << NUMBER_OF_DUELS << " duels or " << setprecision(2) << (aPercent * 100) << "%\n";
    cout << "Bob won " << bWins << "/" << NUMBER_OF_DUELS << " duels or " << setprecision(2) << (bPercent * 100) << "%\n";
    cout << "Charlie won " << cWins << "/" << NUMBER_OF_DUELS << " duels or " << setprecision(2) << (cPercent * 100) << "%\n";
    
    // Strategy 2 (10000 duels)
    cout << "\nReady to test Strategy 2 (run 10000 times):\n";
    pressAnyKey();
    
    // Reinitialize our variables
    duels = 0;
    aWins = 0;
    bWins = 0;
    cWins = 0;
    
    while (duels < NUMBER_OF_DUELS) {
        strategy2();
        duels++;
    }
    
    // Precentage Calculation
    aPercent = (double) aWins / (double) NUMBER_OF_DUELS;
    bPercent = (double) bWins / (double) NUMBER_OF_DUELS;
    cPercent = (double) cWins / (double) NUMBER_OF_DUELS;
    
    // More output to compare strategies
    cout << "Aaron won " << aWins << "/" << NUMBER_OF_DUELS << " duels or " << setprecision(2) << (aPercent * 100) << "%\n";
    cout << "Bob won " << bWins << "/" << NUMBER_OF_DUELS << " duels or " << setprecision(2) << (bPercent * 100) << "%\n";
    cout << "Charlie won " << cWins << "/" << NUMBER_OF_DUELS << " duels or " << setprecision(2) << (cPercent * 100) << "%\n";
    
    if (aWins > aWins1) {
        cout << "\nStrategy 2 is better than Strategy 1.\n";
    }
    
    else if (aWins < aWins1)    {
        cout << "\nStrategy 1 is better than Strategy 2.\n";
    }
    
    else    {
        cout << "\nBoth strategies have the same outcome.\n";
    }
}
    
    // Implementations of functions
void pressAnyKey(void)  {
    cout << "Press enter to continue...\n";
    cin.get();
}

    bool atLeastTwoAlive(bool A_alive, bool B_alive, bool C_alive)  {
        if (A_alive)    {
            if (B_alive || C_alive) {
                return true;
            }
        }
        
        else if (B_alive)   {
            if (C_alive)    {
                return true;
            }
        }
        
        else    {
            return false;
        }
        return 0;
    }
    
    void AaronShoots1(bool& B_alive, bool& C_alive) {
        const int A_HITS = 33;
        int result;
        result = rand()%100;
        
        if (result < A_HITS)   {
            if (C_alive)    {
                C_alive = false;
            }
            else    {
                B_alive = false;
            }
        }
    }

void BobShoots(bool& A_alive, bool& C_alive)    {
    const int B_HITS = 50;
    int result;
    result = rand()%100;
    
    if (result < B_HITS)   {
        if (C_alive)    {
            C_alive = false;
        }
        else    {
            A_alive = false;
        }
    }
}

void CharlieShoots(bool& A_alive, bool& B_alive)    {
    
    if (B_alive)    {
        B_alive = false;
    }
    else    {
        A_alive = false;
    }
}

void AaronShoots2(bool& B_alive, bool& C_alive) {
    const int A_HITS = 33;
    int result;
    
    if (!B_alive || !C_alive)   {
        result = rand()%100;
        
        if (result < A_HITS)   {
            if (C_alive)    {
                C_alive = false;
            }
            else    {
                B_alive = false;
            }
        }
    }
}

// Strategy 1
void strategy1(void)    {
    bool aAlive = true;
    bool bAlive = true;
    bool cAlive = true;
    
    while (atLeastTwoAlive(aAlive, bAlive, cAlive)) {
        
        if (aAlive) {
            AaronShoots1(bAlive, cAlive);
        }
        if (bAlive) {
            BobShoots(aAlive, cAlive);
        }
        if (cAlive) {
            CharlieShoots(aAlive, bAlive);
        }
    }
    
    // Only one is alive now, so that one wins and we add the win to the counter.
    if (aAlive) {
        aWins++;
    }
    else if (bAlive)    {
        bWins++;
    }
    else    {
        cWins++;
    }
}

// Strategy 2
void strategy2(void)    {
    bool aaronAlive = true;
    bool bobAlive = true;
    bool charlieAlive = true;
    
    while (atLeastTwoAlive(aaronAlive, bobAlive, charlieAlive)) {
        
        if (aaronAlive) {
            AaronShoots2(bobAlive, charlieAlive);
        }
        if (bobAlive)  {
            BobShoots(aaronAlive, charlieAlive);
        }
        if (charlieAlive)   {
            CharlieShoots(aaronAlive, bobAlive);
        }
    }
    
    // Only one is alive now, so that one wins and we add the win to the counter.
    if (aaronAlive) {
        aWins++;
    }
    else if (bobAlive)  {
        bWins++;
    }
    else    {
        cWins++;
    }
}

// Test for atLeastTwoAlive()
void testAtLeastTwoAlive(void)  {
    cout << "Unit Testing 1: Function atLeastTwoAlive()\n";
    
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == atLeastTwoAlive(true, true, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == atLeastTwoAlive(false, true, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == atLeastTwoAlive(true, false, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == atLeastTwoAlive(true, true, false));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == atLeastTwoAlive(false, false, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == atLeastTwoAlive(false, true, false));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == atLeastTwoAlive(true, false, false));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == atLeastTwoAlive(false, false, false));
    cout << "\tCase passed ...\n";
}

// Test for AaronShoots1
void testAaronShoots1(void) {
    cout << "Unit Testing 2: Function AaronShoots1(B_alive, C_alive)\n";
    bool bob;
    bool charlie;
    
    cout << "\tCase 1: Bob alive, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    bob = true;
    charlie = true;

    AaronShoots1(bob, charlie);
    assert(true == bob);
    
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    bob = false;
    charlie = true;

    AaronShoots1(bob, charlie);
    assert(false == bob);
    
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    cout << "\t\tAaron is shooting at Bob\n";
    bob = true;
    charlie = false;

    AaronShoots1(bob, charlie);
    assert(false == charlie);
}

// Test for BobShoots
void testBobShoots(void)    {
    cout << "Unit Testing 3: Function BobShoots(A_alive, C_alive)\n";
    bool aaron;
    bool charlie;
    
    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    aaron = true;
    charlie = true;
    
    BobShoots(aaron, charlie);
    assert(true == aaron);
    
    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    aaron = false;
    charlie = true;
    
    BobShoots(aaron, charlie);
    assert(false == aaron);
    
    cout << "\tCase 3: Aaron alive, Charlie dead\n";
    cout << "\t\tBob is shooting at Aaron\n";
    aaron = true;
    charlie = false;
    
    BobShoots(aaron, charlie);
    assert(false == charlie);
}

// Test for CharlieShoots
void testCharlieShoots(void)    {
    cout << "Unit Testing 4: Function CharlieShoots(A_alive, B_alive)\n";
    bool aaron;
    bool bob;
    
    cout << "\tCase 1: Aaron alive, Bob alive\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    aaron = true;
    bob = true;
    
    CharlieShoots(aaron, bob);
    assert(true == aaron);
    assert(false == bob);
    
    cout << "\tCase 2: Aaron dead, Bob alive\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    aaron = false;
    bob = true;
    
    CharlieShoots(aaron, bob);
    assert(false == aaron);
    assert(false == bob);
    
    cout << "\tCase 3: Aaron alive, Bob dead\n";
    cout << "\t\tCharlie is shooting at Aaron\n";
    aaron = false;
    bob = true;
    
    CharlieShoots(aaron, bob);
    assert(false == aaron);
    assert(false == bob);
}

// Test for AaronShoots2
void testAaronShoots2(void) {
    cout << "Unit Testing 5: Function AaronShoots2(B_alive, C_alive)\n";
    bool bob;
    bool charlie;
    
    cout << "\tCase 1: Bob alive, Charlie alive\n";
    cout << "\t\tAaron intentionally misses his first shot\n";
    bob = true;
    charlie = true;
    
    AaronShoots2(bob, charlie);
    assert(true == bob);
    assert(true == charlie);
    cout << "\t\tBoth Bob and Charlie are alive\n";
    
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    bob = false;
    charlie = true;
    
    AaronShoots2(bob, charlie);
    
    assert(false == bob);
    
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    cout << "\t\tAaron is shooting at Bob\n";
    bob = true;
    charlie = false;
    
    AaronShoots2(bob, charlie);
    
    assert(false == charlie);
}
