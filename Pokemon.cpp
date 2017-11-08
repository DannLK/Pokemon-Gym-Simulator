/*
 * File:   ISP.cpp
 * Author: DannL
 * STATUS: DONE
 *
 * Title : Pokemon Gym Battle Simulator
 *
 * Description: This program simulates a battle between the user and 5 opponents. The goal for the
 * user is to try to defeat the 5 pokemon that the opponent's have with the 3 that he is given before they defeat him.
 * Additional features similar to the actual pokemon game include switching pokemon, and using items.
 *
 * Created on May 10, 2016, 9:12 AM
 *
 */

/* NOTE:
 * When referring to 'opponent's pokemon' (not plural) in comments, assume that it means the current 'defender' pokemon.
 * When referring to the 'user's pokemon' (not plural) in comments , assume that it means the current 'attacker' pokemon out.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <limits>

using namespace std;

/*
 *
 */


/*
 * Purpose: To represent a general attack of any entity, and the INTERFACE
 * (i.e behavior or ACTION that we can do on our objects)
 */

class Attack {
private:
    int pp;
    int accuracy;
    string categoryAttack;
    string name;
    int power;

  /*
   * Purpose: A set method that is used so that the value could be set for the power of an attack
   *
   * Parameters: The value that you are setting the power to.
   *
   * Return Value: None
   *
   * Side Effects: The power is changed based on whatever value is set for it.
   */

    void setPower(int power) {
        this->power = power;
    }

  /*
   * Purpose: A set method that is used so that the value could be set for the 'pp' of an attack
   *
   * Parameters: The value that you are setting the 'pp' to.
   *
   * Return Value: None
   *
   * Side Effects: The 'pp' is changed based on whatever value is set for it.
   */
    void setPP(int pp) {
        this->pp = pp;
    }

  /*
   * Purpose: A set method that is used so that the value could be set for the accuracy of an attack
   *
   * Parameters: The value that you are setting the accuracy to.
   *
   * Return Value: None
   *
   * Side Effects: The accuracy is changed based on whatever value is set for it.
   */
    void setAccuracy(int accuracy) {
        this->accuracy = accuracy;
    }

  /*
   * Purpose: A set method that is used so that the string could be set for the name of an attack
   *
   * Parameters: The string that you are setting the name to.
   *
   * Return Value: None
   *
   * Side Effects: The name is changed based on whatever string is set for it.
   */

    void setName(string name) {
        this->name = name;
    }

public:

    // Constructor for the Attack class, every attack will have a power, a 'pp', a accuracy, and a name.
    Attack(int power, int pp, int accuracy, string name) {
        setPower(power);
        setPP(pp);
        setAccuracy(accuracy);
        setName(name);
    }

    // Get methods to allow a class to return multiple variables from attack
    // that can be used in other classes/functions.
    virtual string getName() {return name;}
    virtual int getAccuracy() {return accuracy;}
    virtual int getPower(){return power;}
    virtual int getPP(){return pp;}


  /*
   * Purpose: Decreases the 'pp' of an attack.
   *
   * Parameters: None
   *
   * Return Value: None
   *
   * Side Effects: 'pp' of an attack is decreased by 1 everytime this function is called.
   */

    virtual void decreasePP() {
        pp--;
    }



};


/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know exactly what attack it is specifically),
 * in this class, we now know specifically all the values that are needed to create these attacks.
 *
 * (Applies to all of the children classes of attack.)
 */

class StoneEdge : public Attack {
public:

    StoneEdge() :

    Attack(100, 5, 80, "Stone Edge") { // set known values in ctor.
    }
};

class HeadSmash : public Attack{
public:
    HeadSmash():

    Attack(150, 5, 80, "Head Smash"){ // set known values in ctor.
    }
};

class RockTomb : public Attack{
    public:
    RockTomb():

    Attack(60, 15, 95, "Rock Tomb"){
    }
};

class PowerGem : public Attack{
    public:
    PowerGem():

    Attack(80, 20, 100, "Power Gem"){
    }
};

class Hydropump : public Attack {
public:

    Hydropump() :

    Attack(110, 5, 80, "Hydropump") {

    }
};

class Surf : public Attack {
public:

    Surf() :

    Attack(90, 15, 100, "Surf") {
    }
};

class Bubble : public Attack {
public:

    Bubble() :

    Attack(40, 30, 100, "Bubble") {
    }
};

class AquaJet : public Attack{
public:

    AquaJet ():

    Attack(40, 20, 100, "Aqua Jet"){
    }
};

class RazorLeaf : public Attack{
public:
    RazorLeaf():

    Attack(55, 25, 95, "Razor Leaf"){
    }
};

class LeafBlade : public Attack{
public:
    LeafBlade():

    Attack(90, 15, 100, "Leaf Blade"){
    }

};

class LeafTornado : public Attack{
public:
    LeafTornado():

    Attack(65, 10, 95, "Leaf Tornado"){
    }

};

class SolarBeam: public Attack{
public:
    SolarBeam():

    Attack(120, 10, 50, "Solar Beam"){
    }
};

class Ember: public Attack{
public:
    Ember():

    Attack(40, 25, 100, "Ember"){
    }
};

class FirePunch: public Attack{
public:
    FirePunch():

    Attack(75, 15, 100, "Fire Punch"){
    }

};

class FlameWheel: public Attack{
public:
    FlameWheel():

    Attack(60, 25, 100, "Flame Wheel"){
    }
};

class VCreate: public Attack{
public:
    VCreate():

    Attack(120, 5, 95, "V-Create"){
    }
};

class Thunder: public Attack{
public:
    Thunder():

    Attack(110, 10, 70, "Thunder"){
    }
};

class ThunderFang: public Attack{
public:
    ThunderFang():

    Attack(65, 15, 95, "Thunder Fang"){
    }
};

class ZapCannon: public Attack{
public:
    ZapCannon():

    Attack(120, 5, 50, "Zap Cannon"){
    }
};

class Spark: public Attack{
public:
    Spark():

    Attack(65, 20, 100, "Spark"){
    }
};


/*
 * Purpose: To represent a general Pokemon of any entity, and the INTERFACE
 * (i.e behavior or ACTION that we can do on our objects)
 */

class Pokemon {
public:
    int health;
private:
    string category;
    string type;
    string categorySuperEffective;
    string categoryNotEffective;

  /*
   * Purpose: A set method that is used so that the string could be set for the category of a pokemon
   *
   * Parameters: The string that you are setting the category to.
   *
   * Return Value: None
   *
   * Side Effects: The category is changed based on whatever string is set for it.
   */
    virtual void setCategory(string category) {
        this->category = category;
    }

  /*
   * Purpose: A set method that is used so that the string could be set for the type of a pokemon
   *
   * Parameters: The string that you are setting the type to.
   *
   * Return Value: None
   *
   * Side Effects: The type is changed based on whatever string is set for it.
   */
    virtual void setType(string type) {
        this->type = type;
    }

  /*
   * Purpose: A set method that is used so that the value could be set for the health of a pokemon
   *
   * Parameters: The value that you are setting the health to.
   *
   * Return Value: None
   *
   * Side Effects: The health is changed based on whatever value is set for it.
   */

    virtual void setHealth(int health) {
        this->health = health;
    }

protected: // Only allow the children of this class to modify these set methods
// The second hierarchy down will know what category its super effective agaisnt and not
// effective against, so these set methods allow the child class of pokemon to set
// these values. It is protected because only the child class of pokemon is setting this value.


  /*
   * Purpose: A set method that is used so that the 'super effective' category and 'not effective'
   * category can be set for the pokemon, used in later calculations.
   *
   * Parameters: The strings you are setting the effective category to be and the
   * not effective category to be.
   *
   * Return Value: None.
   *
   * Side Effects: The 'super effective' and 'not effective' category is changed
   * based on whatever value is set for it.
   */


    virtual void setCategorySuperEffective(string categorySuperEffective) {
        this->categorySuperEffective = categorySuperEffective;
    }

    virtual void setCategoryNotEffective(string categoryNotEffective) {
        this->categoryNotEffective = categoryNotEffective;
    }

private:
// Create 4 pointers to attack.
    Attack * Attack1;
    Attack * Attack2;
    Attack * Attack3;
    Attack * Attack4;

public:
    // Constructor for a pokemon. Every pokemon will always have 4 attacks, a specific category they are in,
    // a type of pokemon they are a part of, and a amount of health.
    Pokemon(Attack *one, Attack *two, Attack *three, Attack *four, string category, string type, int health) {
        this->Attack1 = one;
        this->Attack2 = two;
        this->Attack3 = three;
        this->Attack4 = four;
        setCategory(category);
        setType(type);
        setHealth(health);
    }

    // get methods to return multiple variables from this class pokemon
    // OR to temporarily change a value without permanently changing the value.
    virtual string getCategory() {return category;}
    virtual string getType() {return type;}
    virtual int getAttack1() {return Attack1->getPower();}
    virtual int getAttack2() {return Attack2->getPower();}
    virtual int getAttack3() {return Attack3->getPower();}
    virtual int getAttack4() {return Attack4->getPower();}
    virtual int getAccuracy1() {return Attack1->getAccuracy();}
    virtual int getAccuracy2() {return Attack2->getAccuracy();}
    virtual int getAccuracy3() {return Attack3->getAccuracy();}
    virtual int getAccuracy4() {return Attack4->getAccuracy();}


  /*
   * Purpose: A method that prints the possible choices and gets the attack choice from the user.
   *
   * Parameters: None.
   *
   * Return Value: The attack choice of the user.
   *
   * Side Effects: The attack choice of the user 'AttackChoice' is being modified based on user input.
   */


    virtual double getAttackChoice() {
        double AttackChoice = 0;


        string Attack1Name = Attack1->getName(); //
        string Attack2Name = Attack2->getName(); // Get the names of the pokemon attacks.
        string Attack3Name = Attack3->getName(); //
        string Attack4Name = Attack4->getName(); //


        while(AttackChoice != 1 && AttackChoice != 2 && AttackChoice != 3 && AttackChoice != 4 && AttackChoice != 5){
        cout << "What move would you like to use?" << endl;
        cout << "(1) " << Attack1Name << " (" << Attack1->getPP() << " PP, " << Attack1->getPower() << " Power, " << Attack1->getAccuracy() << " Accuracy )" << endl;
        cout << "(2) " << Attack2Name << " (" << Attack2->getPP() << " PP, " << Attack2->getPower() << " Power, " << Attack2->getAccuracy() << " Accuracy )" << endl;
        cout << "(3) " << Attack3Name << " (" << Attack3->getPP() << " PP, " << Attack3->getPower() << " Power, " << Attack3->getAccuracy() << " Accuracy )" << endl;
        cout << "(4) " << Attack4Name << " (" << Attack4->getPP() << " PP, " << Attack4->getPower() << " Power, " << Attack4->getAccuracy() << " Accuracy )" << endl;
        cout << "(5) Back" << endl;
        cin >> AttackChoice;

            if (cin.fail()){ // If cin is in failed state (Letter is inputted)
            cin.clear(); // Clear the cin
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Throw away the bad input
        }

        }

        return AttackChoice;
    }


  /*
   * Purpose: A method that simulates the attack sequence of the user
   *
   * Parameters: The opponent/'defender' the user is up against.
   *
   * Return Value: None.
   *
   * Side Effects: The health of the opponent if the attack hits. The 'pp' of the users attack when its used.
   */

    virtual void PlayerAttack(Pokemon * opponent) {
        double FightChoice = 0;
        int SuperEffectiveCounter = 0;


        int power1 = getAttack1(); //
        int power2 = getAttack2(); // I only want to modify the attack temporarily
        int power3 = getAttack3(); // so I assign it to a variable so that the power does not
        int power4 = getAttack4(); // permanently change.
        int Accuracy1 = getAccuracy1(); // Accuracy will never change for an attack, so
        int Accuracy2 = getAccuracy2(); // I can just get them from the get methods.
        int Accuracy3 = getAccuracy3();
        int Accuracy4 = getAccuracy4();




        int randomNumber = 0;
        randomNumber = rand();
        randomNumber++;


        if (opponent->getCategory() == categorySuperEffective) { // If the category of the opponent's pokemon is the
            power1 = power1 * 2; // is the category that the user's pokemon is super effective against
            power2 = power2 * 2; // The users pokemon will do 2x the damage to the opponent with his abilities
            power3 = power3 * 2;
            power4 = power4 * 2;


            SuperEffectiveCounter = 1; // Set this counter as 2 if the user's abilities against opponent are super effective.

        } else if (opponent->getCategory() == categoryNotEffective) { // If the category of the opponent's pokemon is the
            power1 = power1 * 0.5; // is the category that the user's pokemon is not effective against,
            power2 = power2 * 0.5; // the user's pokemon will only do 1/2 the damage to the opponent with his abilities.
            power3 = power3 * 0.5;
            power4 = power4 * 0.5;

            SuperEffectiveCounter = 2; // Set this counter as 2 if the user's abilities against opponent are not effective.

        }


        cout << endl;
        while (FightChoice != 1 && FightChoice != 2 && FightChoice != 3 && FightChoice != 4 && FightChoice!= 5){
        FightChoice = getAttackChoice();
        }

        if (FightChoice == 1 && Attack1->getPP() > 0) { // Only if they choose the first attack, and its 'pp' is greater than 0
            if ((randomNumber % 100) < Accuracy1) { // Random number generated. This attack has 'accuracy1'% chance of hitting in the range(i.e if accuracy1 = 60, it has a 60% chance of happening)
                // If it hits the range that means the attack hit
                cout << "You use " << Attack1->getName() << " !" << endl;
                cout << "You hit him for " << power1 << " damage!" << endl;

                if (SuperEffectiveCounter == 1) { // Will only occur when the user's pokemon is super effective against opponent's pokemon.
                    cout << "It's super effective!" << endl; // If the damage dealt was super effective, print it.
                } else if (SuperEffectiveCounter == 2) { // Will only occur when the user's pokemon is not effect against opponent's pokemon
                    cout << "It's not very effective..." << endl; // If the damage dealt was not effective, print it.
                }

                opponent->health = opponent->health - power1; // The Opponent pokemon's health decreases by the damage the ability 1 does.
                Attack1->decreasePP(); // Decrease the pp of that attack by 1.
            } else { // Otherwise if the random number generated was not in the range
                cout << "You use " << Attack1->getName() << " !" << endl;
                cout << "but it missed!" << endl; // print that the attack missed.
                Attack1->decreasePP(); // still decrease 'pp' since the move was used.
            }
        } else if (FightChoice == 1 && Attack1->getPP() <= 0) { // If the pokemon does not have enough 'pp' to use attack1 (equal or less than 0)
            cout << "You have ran out of PP for that move! Please select another move." << endl; //tell them to use another move.
            PlayerAttack(opponent); // Call itself again to choose move again.
        }




        if (FightChoice == 2 && Attack2->getPP() > 0) { // Only if they choose the second attack, and its 'pp' is greater than 0
            if ((randomNumber % 100) < Accuracy2) { // Random number generated. This attack has 'accuracy2'% chance of hitting in the range.
                // If it hits the range that means the attack hit
                cout << "You use " << Attack2->getName() << " !" << endl;
                cout << "You hit him for " << power2 << " damage!" << endl;

                if (SuperEffectiveCounter == 1) {
                    cout << "It's super effective!" << endl;
                } else if (SuperEffectiveCounter == 2) {
                    cout << "It's not very effective..." << endl;
                }

                opponent->health = opponent->health - power2; // The Opponent pokemon's health decreases by the damage the ability 2 does.
                Attack2->decreasePP(); // Decrease the pp of that attack by 1.
            } else { // Otherwise if the random number generated was not in the range
                cout << "You use " << Attack2->getName() << " !" << endl;
                cout << "but it missed!" << endl; // print that the attack missed.
                Attack2->decreasePP(); // still decrease 'pp' since the move was used.
            }
        }  else if (FightChoice == 2 && Attack2->getPP() <= 0) { // If the pokemon does not have enough 'pp' to use attack2 (equal or less than 0)
            cout << "You have ran out of PP for that move! Please select another move." << endl; //tell them to use another move.
            PlayerAttack(opponent); // Call itself again to choose move.
        }



        if (FightChoice == 3 && Attack3->getPP() > 0) {
            if ((randomNumber % 100) < Accuracy3) { // Random number generated. This attack has 'accuracy3'% chance of hitting in the range.
                // If it hits the range that means the attack hit
                cout << "You use " << Attack3->getName() << " !" << endl;
                cout << "You hit him for " << power3 << " damage!" << endl;

                if (SuperEffectiveCounter == 1) {
                    cout << "It's super effective!" << endl;
                } else if (SuperEffectiveCounter == 2) {
                    cout << "It's not very effective..." << endl;
                }

                opponent->health = opponent->health - power3; // The Opponent pokemon's health decreases by the damage the ability 3 does.
                Attack3->decreasePP(); // Decrease the pp of that attack by 1.
            } else {
                cout << "You use " << Attack3->getName() << " !" << endl;
                cout << "but it missed!" << endl;
                Attack3->decreasePP();
            }

        }  else if (FightChoice == 3 && Attack3->getPP() <= 0) {
            cout << "You have ran out of PP for that move! Please select another move." << endl;
            PlayerAttack(opponent);
        }




        if (FightChoice == 4 && Attack4->getPP() > 0) {
            if ((randomNumber % 100) < Accuracy4) { // Random number generated. This attack has 'accuracy4'% chance of hitting in the range.
                // If it hits the range that means the attack hit
                cout << "You use " << Attack4->getName() << " !" << endl;
                cout << "You hit him for " << power4 << " damage!" << endl;

                if (SuperEffectiveCounter == 1) {
                    cout << "It's super effective!" << endl;
                } else if (SuperEffectiveCounter == 2) {
                    cout << "It's not very effective..." << endl;
                }

                opponent->health = opponent->health - power4; // The Opponent pokemon's health decreases by the damage the ability 4 does.
                Attack4->decreasePP(); // Decrease the pp of that attack by 1.
            } else {
                cout << "You use " << Attack4->getName() << " !" << endl;
                cout << "but it missed!" << endl;
                Attack4->decreasePP();
            }
        }  else if (FightChoice == 4 && Attack1->getPP() <= 0) {
            cout << "You have ran out of PP for that move! Please select another move." << endl;
            PlayerAttack(opponent);
        }



    }


  /*
   * Purpose: A method that simulates the attack sequence of the opponent
   *
   * Parameters: The opponent/'defender' that is attacking.
   *
   * Return Value: None.
   *
   * Side Effects: The health of the user's pokemon if the opponent attack hits.
   * The 'pp' of the opponents attack when its used.
   */

    virtual void OpponentAttack(Pokemon * opponent) {
        int OpponentSuperEffectiveCounter = 0;

        int OpponentPower1 = opponent->getAttack1(); // I only want to modify the opponents attack temporarily
        int OpponentPower2 = opponent->getAttack2(); // so I assign it to a variable so that the power does not
        int OpponentPower3 = opponent->getAttack3(); // permanently change.
        int OpponentPower4 = opponent->getAttack4();
        int OpponentAccuracy1 = opponent->getAccuracy1(); // Accuracy will never change for an opponents attack, so
        int OpponentAccuracy2 = opponent->getAccuracy2(); // I can just get them off the get methods.
        int OpponentAccuracy3 = opponent->getAccuracy3();
        int OpponentAccuracy4 = opponent->getAccuracy4();


        int randomNumberOpponent = 0;
        randomNumberOpponent = rand(); // Generate a random number.
        randomNumberOpponent++;
        randomNumberOpponent = randomNumberOpponent % 12; // between 1-12


        int randomNumberOpponentAccuracy = 0;
        randomNumberOpponentAccuracy = rand();
        randomNumberOpponentAccuracy++;

        if (opponent->getCategory() == categorySuperEffective) { // If the category of the opponent's pokemon is the
            OpponentPower1 = OpponentPower1 * 0.5; // is the same category that the user's pokemon is super effective against
            OpponentPower2 = OpponentPower2 * 0.5; // this also means that the opponent's abilities will not be effective towards the user's pokemon.
            OpponentPower3 = OpponentPower3 * 0.5; // (specifically only 1/2 as effective with his abilities)
            OpponentPower4 = OpponentPower4 * 0.5;

            OpponentSuperEffectiveCounter = 2;
        } else if (opponent->getCategory() == categoryNotEffective) { // If the category of the opponent's pokemon is the
            OpponentPower1 = OpponentPower1 * 2; // is the same category that the user's pokemon is not effective against,
            OpponentPower2 = OpponentPower2 * 2; // this also means that the opponent's abilities will be super effective towards the user's pokemon.
            OpponentPower3 = OpponentPower3 * 2;
            OpponentPower4 = OpponentPower4 * 2;

            OpponentSuperEffectiveCounter = 1;
        }

        cout << endl;
        cout << endl;


        if (opponent->health > 0) {
            if (randomNumberOpponent == 1 || randomNumberOpponent == 2 || randomNumberOpponent == 3) {
                // Will have a 25% chance of the random number hitting in this range.
                if ((randomNumberOpponentAccuracy % 100) < OpponentAccuracy1) { // Random number generated. This attack has 'OpponentAccuracy1'% chance of hitting in the range
                // If it hits the range that means the attack hit
                    cout << "The Opponent uses " << opponent->Attack1->getName() << " !" << endl;
                    cout << "He hits you for " << OpponentPower1 << " damage!" << endl;

                    if (OpponentSuperEffectiveCounter == 1) {
                        cout << "It's super effective!" << endl;
                    } else if (OpponentSuperEffectiveCounter == 2) {
                        cout << "It's not very effective..." << endl;
                    }

                    health = health - OpponentPower1; // User's health is decreased by the power of the opponents attack.
                } else { // Otherwise if the random number generated was not in the range
                    cout << "The Opponent uses " << opponent->Attack1->getName() << " !" << endl;
                    cout << "but it missed!" << endl; // print that the attack missed.
                }
            } else if (randomNumberOpponent == 4 || randomNumberOpponent == 5 || randomNumberOpponent == 6) {
                // Will have a 25% chance of the random number hitting in this range.
                if ((randomNumberOpponentAccuracy % 100) < OpponentAccuracy2) { // Random number generated. This attack has 'OpponentAccuracy2'% chance of hitting in the range
                // If it hits the range that means the attack hit
                    cout << "The Opponent uses " << opponent->Attack2->getName() << " !" << endl;
                    cout << "He hits you for " << OpponentPower2 << " damage!" << endl;

                    if (OpponentSuperEffectiveCounter == 1) {
                        cout << "It's super effective!" << endl;
                    } else if (OpponentSuperEffectiveCounter == 2) {
                        cout << "It's not very effective..." << endl;
                    }

                    health = health - OpponentPower2; // User's health is decreased by the power of the opponents attack.
                } else {
                    cout << "The Opponent uses " << opponent->Attack2->getName() << " !" << endl;
                    cout << "but it missed!" << endl;
                }
            } else if (randomNumberOpponent == 7 || randomNumberOpponent == 8 || randomNumberOpponent == 9) {
                // Will have a 25% chance of the random number hitting in this range.
                if ((randomNumberOpponentAccuracy % 100) < OpponentAccuracy3) { // Random number generated. This attack has 'OpponentAccuracy4'% chance of hitting in the range
                // If it hits the range that means the attack hit
                    cout << "The Opponent uses " << opponent->Attack3->getName() << " !" << endl;
                    cout << "He hits you for " << OpponentPower3 << " damage!" << endl;

                    if (OpponentSuperEffectiveCounter == 1) {
                        cout << "It's super effective!" << endl;
                    } else if (OpponentSuperEffectiveCounter == 2) {
                        cout << "It's not very effective..." << endl;
                    }

                    health = health - OpponentPower3; // User's health is decreased by the power of the opponents attack.
                } else {
                    cout << "The Opponent uses " << opponent->Attack3->getName() << " !" << endl;
                    cout << "but it missed!" << endl;
                }
            } else {
            // Will have a 25% chance of the random number hitting in this range since 1-9 range is considered above.
            // Whenever the randomNumber hits 10-12 it will go through this if condition.
                if ((randomNumberOpponentAccuracy % 100) < OpponentAccuracy4) { // Random number generated. This attack has 'OpponentAccuracy4'% chance of hitting in the range
                // If it hits the range that means the attack hit
                    cout << "The Opponent uses " << opponent->Attack4->getName() << " !" << endl;
                    cout << "He hits you for " << OpponentPower4 << " damage!" << endl;

                    if (OpponentSuperEffectiveCounter == 1) {
                        cout << "It's super effective!" << endl;
                    } else if (OpponentSuperEffectiveCounter == 2) {
                        cout << "It's not very effective..." << endl;
                    }

                    health = health - OpponentPower4; // User's health is decreased by the power of the opponents attack.
                } else {
                    cout << "The Opponent uses " << opponent->Attack4->getName() << " !" << endl;
                    cout << "but it missed!" << endl;
                }

            }


        }
    }

  /*
   * Purpose: Prints the fight menu screen and finds the choice the user inputs from the fight screen.
   *
   * Parameters: The pokemon that is currently 'attacking' (one of user's pokemon) and the pokemon
   * that is currently 'defending' (the current opponent)
   *
   * Return Value: The decision that the user chooses in the fight menu.
   *
   * Side Effects: Changes the variable decision depending on whatever the user inputs.
   */

    double printandFindFightMenuChoice(Pokemon * Attacker, Pokemon * Defender) {
    double Decision = 0;

    cout << endl;
    cout << endl;

    while (Decision != 1 && Decision != 2 && Decision != 3){
    if (Attacker->health > 0) {
        cout << "You have " << Attacker->getType() << " (" << Attacker->getCategory() << ")" << " currently on the battlefield against " << Defender->getType() << " (" << Defender->getCategory() << ")" "!" << endl;
        cout << Attacker->getType() << " currently has " << Attacker->health << " HP!" << endl;
        cout << Defender->getType() << " currently has " << Defender->health << " HP!" << endl;


        cout << "What would you like to do?" << endl;
        cout << "(1) Fight" << endl;
        cout << "(2) Change Pokemon" << endl;
        cout << "(3) Use items" << endl;
        cin >> Decision;

        if (cin.fail()){ // If cin is in failed state (Letter is inputted)
            cin.clear(); // Clear the cin
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the bad input
        }

    } else if (Attacker->health <= 0) { // If your attacker is dead, force user to switch pokemon/attacker.
        cout << "Your Pokemon has died!" << endl;
        Decision = 2;
    }
    }

    return Decision;
}

  /*
   * Purpose: A method that simulates the switch sequence if a user wants to switch pokemon.
   *
   * Parameters: All of the pokemon that the user has, and his current attacking pokemon.
   *
   * Return Value: Returns which of the user's pokemon is the new attacker pokemon.
   *
   * Side Effects: The variable Newattacker depending on user input.
   */

    Pokemon * printandFindSwitchChoice(Pokemon * Attacker, Pokemon * teamMate[]) {
    double Decision = 0;
    Pokemon * NewAttacker = 0;


    while(NewAttacker != teamMate[0] && NewAttacker != teamMate[1] && NewAttacker != teamMate[2]){ // while the Newattacker is not set to one of the user's pokemon
        cout << "Which Pokemon would you like to switch to?" << endl; // keep asking them for their switch choice
        if (Attacker == teamMate[0]) { // If the current attacker is teamMate[0],

            if (teamMate[1]->health > 0) { // Only display this teammate choice if it's health is greater than 0.
                cout << "(1) " << teamMate[1]->getType() << " (" << teamMate[1]->getCategory() << ")" << endl; // the new attacker can be teamMate[1]
            }

            if (teamMate[2]->health > 0) { // Only display this teammate choice if it's health is greater than 0.
                cout << "(2) " << teamMate[2]->getType() << " (" << teamMate[2]->getCategory() << ")"  << endl; // the new attacker can be teamMate[2]
            }

            cout << "(3) Back" << endl;

            cin >> Decision;

        if (cin.fail()){ // If cin is in failed state (Letter is inputted)
            cin.clear(); // Clear the cin
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the bad input
        }

            if (Decision == 1 && teamMate[1]->health > 0) { // If they choose teammate 1 and his health is greater than 0
                NewAttacker = teamMate[1]; //The new attacker will be teammate 1
            } else if (Decision == 2 && teamMate[2]->health > 0) { // If they choose teammate 2 and his health is greater than 0
                NewAttacker = teamMate[2]; //The new attacker will be teammate 2
            } else if (Decision == 3) { // If they choose to back break out of the loop.
                break;
            }
        } else if (Attacker == teamMate[1]) { // If the current attacker is teamMate[1]

            if (teamMate[0]->health > 0) { // Only display teammate 0 choice if it's health is greater than 0.
                cout << "(1) " << teamMate[0]->getType() << " (" << teamMate[0]->getCategory() << ")" << endl; // the new attacker can be teamMate[0]
            }

            if (teamMate[2]->health > 0) { // Only display this teammate 2 choice if it's health is greater than 0.
                cout << "(2) " << teamMate[2]->getType() << " (" << teamMate[2]->getCategory() << ")" << endl; // the new attacker can be teamMate[2]
            }

            cout << "(3) Back" << endl;

            cin >> Decision;

        if (cin.fail()){ // If cin is in failed state (Letter is inputted)
            cin.clear(); // Clear the cin
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the bad input
        }

            if (Decision == 1 && teamMate[0]->health > 0) { // If they choose teammate 0 and his health is greater than 0
                NewAttacker = teamMate[0]; //The new attacker will be teammate 0
            } else if (Decision == 2 && teamMate[2]->health > 0) { // If they choose teammate 2 and his health is greater than 0
                NewAttacker = teamMate[2]; //The new attacker will be teammate 2
            } else if (Decision == 3) {
                break;
            }
        } else if (Attacker == teamMate[2]) { // If the current attacker is teamMate[2]

            if (teamMate[0]->health > 0) {
                cout << "(1) " << teamMate[0]->getType() << " (" << teamMate[0]->getCategory() << ")" << endl;
            }

            if (teamMate[1]->health > 0) {
                cout << "(2) " << teamMate[1]->getType() << " (" << teamMate[1]->getCategory() << ")" << endl;
            }

            cout << "(3) Back" << endl;

            cin >> Decision;

            if (cin.fail()){ // If cin is in failed state (Letter is inputted)
            cin.clear(); // Clear the cin
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the bad input
        }

            if (Decision == 1 && teamMate[0]->health > 0) { // If they choose teammate 0 and his health is greater than 0
                NewAttacker = teamMate[0]; //The new attacker will be teammate 0
            } else if (Decision == 2 && teamMate[1]->health > 0) { // If they choose teammate 1 and his health is greater than 0
                NewAttacker = teamMate[1]; //The new attacker will be teammate 1
            } else if (Decision == 3) {
                break;
            }
        }

    }

    return NewAttacker; // Return who the new attacker is.


}


};


/*
 * Purpose: To represent a general rock type pokemon of any entity, and the INTERFACE
 * (i.e behavior or ACTION that we can do on our objects)
 */

class rock : public Pokemon {
public:

    rock(Attack *one, Attack *two, Attack *three, Attack *four, string type, int health) :

    Pokemon(one, two, three, four, "Rock", type, health) {
        setCategorySuperEffective("Fire"); // Set methods that we can use since at this point in
        setCategoryNotEffective("Water"); // the hierarchy, we have enough information with it being a
        // rock type pokemon to set these values.
    }


};

/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know this pokemon's category and the category's set values),
 * in this class, we now know specifically all the values that are needed to create geodude.
 */

class Geodude : public rock {
public:

    Geodude() :

    rock(new StoneEdge(), new RockTomb(), new HeadSmash(), new PowerGem(), "Geodude", 246) {
    }
};

/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know this pokemon's category and the category's set values),
 * in this class, we now know specifically all the values that are needed to create Onix.
 */

class Onix : public rock {
public:

    Onix() :

    rock(new StoneEdge(), new RockTomb(), new HeadSmash(), new PowerGem(), "Onix", 275) {
    }
};

/*
 * Purpose: To represent a general water type pokemon of any entity, and the INTERFACE
 * (i.e behavior or ACTION that we can do on our objects)
 */

class water : public Pokemon {
public:

    water(Attack *one, Attack *two, Attack *three, Attack *four, string type, int health) :

    Pokemon(one, two, three, four, "Water", type, health) {
        setCategorySuperEffective("Fire"); // Within this child class of pokemon, we have enough information
        setCategoryNotEffective("Grass"); // to know what category these water type pokemon will be effective against
        // and not effective against. Set the effective/not effective categories for this specific category of pokemon.
    }




};

/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know this pokemon's category and the category's set values),
 * in this class, we now know specifically all the values that are needed to create Blastoise.
 */

class Blastoise : public water {
public:

    Blastoise() :

    water(new AquaJet(), new Hydropump(), new Surf(), new Bubble(), "Blastoise", 318) {
    }

};

/*
 * Purpose: To represent a general electric type pokemon of any entity, and the INTERFACE
 * (i.e behavior or ACTION that we can do on our objects)
 */

class electric : public Pokemon {
public:

    electric(Attack *one, Attack *two, Attack *three, Attack *four, string type, int health) :

    Pokemon(one, two, three, four, "Electric", type, health) {
        setCategorySuperEffective("Water"); // Within this child class of pokemon, we have enough information
        setCategoryNotEffective("Grass"); // to know what category these electric type pokemon will be effective against
        // and not effective against. Set the effective/not effective categories for this specific category of pokemon.
    }


};

/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know this pokemon's category and the category's set values),
 * in this class, we now know specifically all the values that are needed to create Jolteon.
 */

class Jolteon : public electric{
public:
    Jolteon() :

    electric(new Thunder(), new ThunderFang(), new ZapCannon(), new Spark(), "Jolteon", 250) {
    }
};

/*
 * Purpose: To represent a general grass type pokemon of any entity, and the INTERFACE
 * (i.e behavior or ACTION that we can do on our objects)
 */

class grass : public Pokemon {
public:

    grass(Attack *one, Attack *two, Attack *three, Attack *four, string type, int health) :

    Pokemon(one, two, three, four, "Grass", type, health) {
        setCategorySuperEffective("Water"); // Within this child class of pokemon, we have enough information
        setCategoryNotEffective("Fire"); // to know what category these grass type pokemon will be effective against
        // and not effective against. Set the effective/not effective categories for this specific category.
    }


};

/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know this pokemon's category and the category's set values),
 * in this class, we now know specifically all the values that are needed to create Bulbasaur.
 */

class Bulbasaur : public grass {
public:

    Bulbasaur():

    grass(new LeafBlade(), new RazorLeaf(), new LeafTornado(), new SolarBeam(), "Bulbasaur", 250) {
    }
};

/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know this pokemon's category and the category's set values),
 * in this class, we now know specifically all the values that are needed to create Roselia.
 */
class Roselia: public grass{
public:
    Roselia():

    grass(new LeafBlade(), new RazorLeaf(), new LeafTornado(), new SolarBeam(), "Roselia", 450) {
    }
};

/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know this pokemon's category and the category's set values),
 * in this class, we now know specifically all the values that are needed to create Serperior.
 */
class Serperior: public grass{
    public:
    Serperior():

    grass(new LeafBlade(), new RazorLeaf(), new LeafTornado(), new SolarBeam(), "Serperior", 520) {
    }
};

/*
 * Purpose: To represent a general fire type pokemon of any entity, and the INTERFACE
 * (i.e behavior or ACTION that we can do on our objects)
 */
class fire : public Pokemon {
public:

    fire(Attack *one, Attack *two, Attack *three, Attack *four, string type, int health) :

    Pokemon(one, two, three, four, "Fire", type, health) {
        setCategorySuperEffective("Grass"); // Within this child class of pokemon, we have enough information
        setCategoryNotEffective("Water"); // to know what category these fire type pokemon will be effective against
        // and not effective against. Set the effective/not effective categories for this specific category of pokemon.
    }


};

/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know this pokemon's category and the category's set values),
 * in this class, we now know specifically all the values that are needed to create Charmander.
 */

class Charmander : public fire {
public:

    Charmander() :

    fire(new Ember(), new FirePunch(), new FlameWheel(), new VCreate(), "Charmander", 240) {
    }
};

/*
 * Purpose: To represent a general item of any entity, and the INTERFACE
 * (i.e behavior or ACTION that we can do on our objects)
 */

class Item{
private:
  int effect;
  int pp;
  string name;


  /*
   * Purpose: A set method that is used so that values could be set for the 'pp' of an item
   *
   * Parameters: The value that you are setting the 'pp' to.
   *
   * Return Value: None.
   *
   * Side Effects: The 'pp' is changed based on whatever value is set for it.
   */

  void setPP(int pp){
      this->pp = pp;
  }

  /*
   * Purpose: A set method that is used so that values could be set for the name of an item
   *
   * Parameters: The string that you are setting the name to.
   *
   * Return Value: None
   *
   * Side Effects: The name is changed based on whatever value is set for it.
   */

  void setName(string name){
      this->name = name;
  }

  //Constructor for the Item. An item will always have a name and 'pp'.
public:
  Item(int pp, string name){
      setPP(pp);
      setName(name);
  }


  virtual int getPP(){
      return pp;
  }

  virtual string getName(){
      return name;
  }

  /*
   * Purpose: Decreases the 'pp' of an item.
   *
   * Parameters: None
   *
   * Return Value: None
   *
   * Side Effects: 'pp' of an item is decreased by 1 everytime this function is called.
   */

  virtual void decreasePP(){
      pp--;
  }

  //A pure virtual method is needed because every item will have an effect,
  //but at the very top of the Item hierarchy, it does not know how to do it.
  virtual void Effect(Pokemon * user) = 0;


};

/*
 * Purpose: To represent a general healing potion item, and the INTERFACE
 * (i.e behavior or ACTION that we can do on our objects)
 */

class HealingPotions: public Item{
protected:

    HealingPotions(int pp, string name) :

    Item(pp, name) {
    }

    int heal;


  /*
   * Purpose: A set method that is used so that the amount of healing it can be set to the healing potion.
   *
   * Parameters: The value that you are setting the amount of healing to be.
   *
   * Return Value: None.
   *
   * Side Effects: The 'heal' value is changed based on whatever value is set for it.
   */

    virtual void setHeal(int healing){
        heal = healing;
    }

    //Overrides the effect function set in its parent class.
    virtual void Effect(Pokemon * user){
    user->health = user->health + heal;
    }

};

/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know what exactly what kind of healing potion we have),
 * in this class, we now know specifically all the values that are needed to create a minor healing potion.
 */
class MinorHpGain : public HealingPotions{
public:
    MinorHpGain():

    HealingPotions(5, "Minor Healing Potion"){
        setHeal(80); // Deep enough within the hierarchy to know that specifically minor healing potions
                      // will heal for 80 damage. Set heal as 80.
    }

};

/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know what exactly what kind of healing potion we have),
 * in this class, we know now specifically all the values that are needed to create a greater healing potion.
 */
class GreaterHPGain : public HealingPotions{
public:
    GreaterHPGain():

    HealingPotions(3, "Greater Healing Potion"){
        setHeal(180); // Deep enough within the hierarchy to know that specifically greater healing potions
                      // will heal for 180 damage. Set heal as 180.
    }
};


/*
 * Purpose: To represent a general weapon item, and the INTERFACE
 * (i.e behavior or ACTION that we can do on our objects)
 */

class Weapons: public Item{
protected:
    Weapons(int pp, string name):

    Item(pp, name){
    }

    int damage;

  /*
   * Purpose: A set method that is used so that the amount of health it decreases can be set to the weapon.
   *
   * Parameters: The value that you are setting the amount of healing to be.
   *
   * Return Value: None.
   *
   * Side Effects: The 'heal' value is changed based on whatever value is set for it.
   */

    virtual void setHealthDecrease(int healthDecrease){
        damage = healthDecrease;
    }

     //Overrides the effect function set in its parent class.
    virtual void Effect(Pokemon * opponent){
       opponent->health = opponent->health - damage;

    }
};


/*
 * Purpose: Now that the class is broken down into specific enough categories (i.e we know what exactly what kind of weapon we have),
 * in this class, we know now specifically all the values that are needed to create a poison bomb.
 */

class Poison: public Weapons{
public:
    Poison():

    Weapons(2, "Poison Bomb"){
        setHealthDecrease(50); // Deep enough within the hierarchy to know that specifically poison bomb will do 50 damage.
                               // Set health decrease as 50.
    }
};

void printInstructions(){
    cout << "Welcome to the Pokemon Gym battle simulator!" << endl;
    cout << "The objective of this game is to beat the pokemon of all 5 gym leaders to become the ultimate pokemon trainer!" << endl;
    cout << endl;
    cout << "During your battles you will be given 3 options:" << endl;
    cout << "1. To Attack" << endl;
    cout << "2. To switch from one of your 3 pokemon" << endl;
    cout << "3. To use an item to gain an advantage!" << endl;
    cout << "Be aware that some pokemon will do more/less damage to others depending on their category!" << endl;

    cout << endl;
    cout << "Damage Chart:" << endl;
    cout << "SE = Strong Against, NE = Weak Against." << endl;

    cout << endl;

    cout << "Water -> SE -> Fire" << endl;
    cout << "Water -> NE -> Grass" << endl;
    cout << "Fire -> SE -> Grass" << endl;
    cout << "Fire -> NE -> Water" << endl;
    cout << "Grass -> SE -> Water" << endl;
    cout << "Grass -> NE -> Fire" << endl;
    cout << "Electric -> SE -> Water" << endl;
    cout << "Electric -> NE -> Grass" << endl;
    cout << "Rock -> SE -> Fire" << endl;
    cout << "Rock -> NE -> Water" << endl;

    cout << endl;
    cout << "That's all, I hope you enjoy the game! Creator: Daniel L" << endl;
    cout << endl;
}

  /*
   * Purpose: Prints the amount of battles remaining within the game.
   *
   * Parameters: Amount of gyms (opponents) has been defeated.
   *
   * Return Value: None.
   *
   * Side Effects: None.
   */

void printGymsRemaining(int finishedGyms) {
    cout<< endl;
    cout << endl;
    cout << "Gyms Remaining:" << endl;

    if (finishedGyms == 0) {
        cout << "1. Pewter City Gym" << endl;
        cout << "2. Cerulean City Gym" << endl;
        cout << "3. Vermillion City Gym" << endl;
        cout << "4. Celadon City Gym" << endl;
        cout << "5. Fuchsia City Gym" << endl;
    } else if (finishedGyms == 1) {
        cout << "2. Cerulean City Gym" << endl;
        cout << "3. Vermillion City Gym" << endl;
        cout << "4. Celadon City Gym" << endl;
        cout << "5. Fuchsia City Gym" << endl;
    } else if (finishedGyms == 2) {
        cout << "3. Vermillion City Gym" << endl;
        cout << "4. Celadon City Gym" << endl;
        cout << "5. Fuchsia City Gym" << endl;
    } else if (finishedGyms == 3) {
        cout << "4. Celadon City Gym" << endl;
        cout << "5. Fuchsia City Gym" << endl;
    } else if (finishedGyms == 4) {
        cout << "5. Fuchsia City Gym" << endl;
    }

}




  /*
   * Purpose: Given the 'pp' of the items, it will sort all of the pp values
   * from smallest to largest.
   *
   * Parameters: An array of all the PP of the items.
   *
   * Return Value: None.
   *
   * Side Effects: None.
   */

void sortPP(int PPofItems[]){
    int lowestPP;
    int comparePP;
    int tmp;

    for (lowestPP = 0; lowestPP < 3; lowestPP++){
    for (comparePP = lowestPP + 1; comparePP < 3; comparePP++){
        if (PPofItems[comparePP] < PPofItems[lowestPP]){
            tmp = PPofItems[comparePP];
            PPofItems[comparePP] = PPofItems[lowestPP];
            PPofItems[lowestPP] = tmp;
        }
    }
    }
}

  /*
   * Purpose: Print the 'pp' of all the items.
   *
   * Parameters: An array of all the PP of the items.
   *
   * Return Value: None.
   *
   * Side Effects: None.
   */

void printPP( int PPofItems[]){
    int index;

    cout << endl;
    cout << endl;
    cout << "You should never only use one move, you'll run out of PP!" << endl;
    cout << "Printing from the order of PP that is closest to running out..." << endl;

        for (index = 0; index < 3; index++) {
        cout << PPofItems[index] << " PP" << endl;
    }

}

 /*
   * Purpose: Prints the item choosing screen and based on user input,
   * the user can use the items given to them.
   *
   * Parameters: An array of all of the user's items, the current 'attacker' pokemon
   * from the user and the current 'defender' pokemon from the opponent.
   *
   * Return Value: None.
   *
   * Side Effects: Decreases pp by 1 if an item is used. If the function 'effect' is called
   * health of the 'attacker' will either increase or the health of the 'defender' will decrease.
   */

void printandUseItems(Item * teamMateItems[], Pokemon * user, Pokemon * opponent){
    int teamMateItemsPP[3];
    teamMateItemsPP[0] = teamMateItems[0]->getPP();
    teamMateItemsPP[1] = teamMateItems[1]->getPP();
    teamMateItemsPP[2] = teamMateItems[2]->getPP();

    double decision = 0;
    while (decision != 1 && decision != 2 && decision != 3 && decision!= 4){ // While the user has not chosen any of the items or back.
    cout << endl;
    cout << "Items Available:" << endl;
    cout << "(1) " << teamMateItems[0]->getName() << "( " << teamMateItems[0]->getPP() << " PP, +80 HP)" << endl;
    cout << "(2) " << teamMateItems[1]->getName() << "( " << teamMateItems[1]->getPP() << " PP, +180 HP)" << endl;
    cout << "(3) " << teamMateItems[2]->getName() << "( " << teamMateItems[2]->getPP() << " PP, 50 Power)" << endl;
    cout << "(4) Back" << endl;

    sortPP(teamMateItemsPP); // Sort the PP from lowest PP to highest
    printPP(teamMateItemsPP); // Print the sorted PP.

    cout << endl;
    cout << "Which item would you like to use?" << endl;
    cin >> decision;

            if (cin.fail()){ // If cin is in failed state (Letter is inputted)
            cin.clear(); // Clear the cin
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Throw away the bad input
        }
    }


    if (decision == 1 && teamMateItems[0]->getPP() > 0){ // If they choose the first item, and it has a pp greater than 0
        teamMateItems[0]->Effect(user); // Use the effect of the item on the user's attacker pokemon.
        teamMateItems[0]->decreasePP(); // decrease its 'pp' by 1.
        cout << "You have gained 80HP or increased your max health by 80 " << endl;
    }else if (decision == 1 && teamMateItems[0]->getPP() <= 0){ // If it's pp is less or equal to 0
        cout << "Not Enough PP, returning to menu... " << endl; // print an error message.
    }



        if (decision == 2 && teamMateItems[1]->getPP() > 0){ // If they choose the second item, and it has a pp greater than 0
        teamMateItems[1]->Effect(user); // Use the effect of the item on the user's attacker pokemon.
        teamMateItems[1]->decreasePP(); // decrease its 'pp' by 1.
        cout << "You have gained 180HP or increased your max health by 180 " << endl;
    } else if (decision == 2 && teamMateItems[1]->getPP() <= 0){  // If it's pp is less or equal to 0
        cout << "Not Enough PP, returning to menu... " << endl; // print an error message.
    }



        if (decision == 3 && teamMateItems[2]->getPP() > 0){ // If they choose the third item, and it has a pp greater than 0
        teamMateItems[2]->Effect(opponent); // Use the effect of the item on the user's attacker pokemon.
        teamMateItems[2]->decreasePP();  // decrease its 'pp' by 1.
         cout << "You throw a poison bomb at your opponent! They are hit for 50 HP " << endl;
    } else if (decision == 3 && teamMateItems[2]->getPP() <= 0){ // If it's pp is less or equal to 0
        cout << "Not Enough PP, returning to menu... " << endl; // print an error message.
    }


}



int main(int argc, char** argv) {

    string name = " ";
    string MainMenuChoice = " ";

    Pokemon * teamMate[3];
    teamMate[0] = new Blastoise(); //
    teamMate[1] = new Bulbasaur(); // Create the user's pokemon
    teamMate[2] = new Onix(); //

    Item * teamMateItems[3];

    teamMateItems[0] = new MinorHpGain(); //
    teamMateItems[1] = new GreaterHPGain(); // Create the user's items.
    teamMateItems[2] = new Poison(); //

    Pokemon * opponent[5];
    opponent[0] = new Charmander(); //
    opponent[1] = new Geodude(); //
    opponent[2] = new Roselia(); // Create the opponent's pokemon
    opponent[3] = new Jolteon(); //
    opponent[4] = new Serperior(); //

    double Choice = 0;

    srand(time(NULL));

    Pokemon * Attacker; // There will always be only 1 attacker and defender fighting at any point in time.
    Pokemon * Defender; //

    Attacker = teamMate[0]; // Preset the attacker as the first teammate
    Defender = opponent[0]; // Preset the defender as the first opponent
    Pokemon * NewAttacker;


    cout << "Welcome to the Pokemon Gym Trainer! Please enter your name:" << endl;
    getline(cin, name);
    printInstructions(); // Print the instructions.

    while (MainMenuChoice != "1" && MainMenuChoice != "2" ) {
        cout << "This is the main menu " << name << ", choose the number in correspondence to what you want to do!" << endl;
        cout << "(1) Start Game!" << endl;
        cout << "(2) Quit" << endl;
        getline(cin, MainMenuChoice);
    }



    if (MainMenuChoice == "1") {
        printGymsRemaining(0); // Print the remaining opponents left.
        while (Defender->health > 0) { // While the opponent pokemon is still alive
            Choice = Attacker->printandFindFightMenuChoice(Attacker, Defender); // Find what choice the user wants to do in menu.
            if (Choice == 1) { // If user chooses to attack
                Attacker->PlayerAttack(Defender); // User's attack sequence
                Attacker->OpponentAttack(Defender); // Opponents attack sequence
                if (Defender->health <= 0) { // If your attack makes the defender pokemon go to 0 or less
                    cout << "Congratulations, you beat the opponent! " << endl; // Print message and the loop ends.
                } else if (teamMate[0]->health <= 0 && teamMate[1]->health <= 0 && teamMate[2]->health <= 0) { // Otherwise if all of the user pokemon's health go to 0 or less.
                    cout << "Sorry you died!" << endl;
                    return 0; // End game.
                }
            } else if (Choice == 2) { // If the user chooses to switch pokemon
                NewAttacker = Attacker->printandFindSwitchChoice(Attacker, teamMate); // Set newattacker to be the attacker returned in the function.
                if (NewAttacker == teamMate[0] || NewAttacker == teamMate[1] || NewAttacker == teamMate[2]){ // If newattacker is equal to one of the user's teammates
                Attacker = NewAttacker; // set the attacker as the new attacker established
                Attacker->OpponentAttack(Defender); // the opponent will attack you when you switch out.
                }

                if (teamMate[0]->health <= 0 && teamMate[1]->health <= 0 && teamMate[2]->health <= 0) { // If after the opponent attack, all of your teammate's health is equal or less than 0
                    cout << "Sorry you died!" << endl;
                    return 0; // End game.
                }
            } else if (Choice == 3) { // If the user chooses to use an item
                printandUseItems(teamMateItems, Attacker, Defender); // print the item screen and allow them to choose an item to use.
                 if (Defender->health <= 0) { // If you use an item and the defender's health is less or equal to 0
                    cout << "Congratulations, you beat the opponent! " << endl; // You beat the opponent and loop ends.
                }
            }
        }



        printGymsRemaining(1); // Print the remaining opponents left.
        Defender = opponent[1]; // The new defender will be the next opponent in the array.
        while (Defender->health > 0) { // Same steps as above in the first battle sequence
            Choice = Attacker->printandFindFightMenuChoice(Attacker, Defender);
            if (Choice == 1) {
                Attacker->PlayerAttack(Defender);
                Attacker->OpponentAttack(Defender);
                if (Defender->health <= 0) {
                    cout << "Congratulations, you beat the opponent! " << endl;
                } else if (teamMate[0]->health <= 0 && teamMate[1]->health <= 0 && teamMate[2]->health <= 0) {
                    cout << "Sorry you died!" << endl;
                    return 0;
                }
            } else if (Choice == 2) {
                NewAttacker = Attacker->printandFindSwitchChoice(Attacker, teamMate);
                if (NewAttacker == teamMate[0] || NewAttacker == teamMate[1] || NewAttacker == teamMate[2]){
                Attacker = NewAttacker;
                Attacker->OpponentAttack(Defender);
                }
                if (teamMate[0]->health <= 0 && teamMate[1]->health <= 0 && teamMate[2]->health <= 0) {
                    cout << "Sorry you died!" << endl;
                    return 0;
                }
            } else if (Choice == 3) {
              printandUseItems(teamMateItems, Attacker, Defender);
               if (Defender->health <= 0) {
                    cout << "Congratulations, you beat the opponent! " << endl;
                }
            }
        }



        printGymsRemaining(2); // Print the remaining opponents left
        Defender = opponent[2]; // The new defender will be the next opponent in the array.
        while (Defender->health > 0) { // Same steps as above in the first battle sequence
            Choice = Attacker->printandFindFightMenuChoice(Attacker, Defender);
            if (Choice == 1) {
                Attacker->PlayerAttack(Defender);
                Attacker->OpponentAttack(Defender);
                if (Defender->health <= 0) {
                    cout << "Congratulations, you beat the opponent! " << endl;
                } else if (teamMate[0]->health <= 0 && teamMate[1]->health <= 0 && teamMate[2]->health <= 0) {
                    cout << "Sorry you died, thanks for playing!" << endl;
                    return 0;
                }
            } else if (Choice == 2) {
                NewAttacker = Attacker->printandFindSwitchChoice(Attacker, teamMate);
                if (NewAttacker == teamMate[0] || NewAttacker == teamMate[1] || NewAttacker == teamMate[2]){
                Attacker = NewAttacker;
                Attacker->OpponentAttack(Defender);
                }
                if (teamMate[0]->health <= 0 && teamMate[1]->health <= 0 && teamMate[2]->health <= 0) {
                    cout << "Sorry you died, thanks for playing!" << endl;
                    return 0;
                }
            } else if (Choice == 3) {
                printandUseItems(teamMateItems, Attacker, Defender);
               if (Defender->health <= 0) {
                    cout << "Congratulations, you beat the opponent! " << endl;
                }
            }
        }

        printGymsRemaining(3); // Print the remaining opponents left.
        Defender = opponent[3]; // The new defender will be the next opponent in the array.
        while (Defender->health > 0) { // Same steps as above in the first battle sequence
            Choice = Attacker->printandFindFightMenuChoice(Attacker, Defender);
            if (Choice == 1) {
                Attacker->PlayerAttack(Defender);
                Attacker->OpponentAttack(Defender);
                if (Defender->health <= 0) {
                    cout << "Congratulations, you beat the opponent! " << endl;
                } else if (teamMate[0]->health <= 0 && teamMate[1]->health <= 0 && teamMate[2]->health <= 0) {
                    cout << "Sorry you died, thanks for playing!" << endl;
                    return 0;
                }
            } else if (Choice == 2) {
                NewAttacker = Attacker->printandFindSwitchChoice(Attacker, teamMate);
                if (NewAttacker == teamMate[0] || NewAttacker == teamMate[1] || NewAttacker == teamMate[2]){
                Attacker = NewAttacker;
                Attacker->OpponentAttack(Defender);
                }
               if (teamMate[0]->health <= 0 && teamMate[1]->health <= 0 && teamMate[2]->health <= 0) {
                    cout << "Sorry you died, thanks for playing!" << endl;
                    return 0;
                }
            } else if (Choice == 3) {
              printandUseItems(teamMateItems, Attacker, Defender);
               if (Defender->health <= 0) {
                    cout << "Congratulations, you beat the opponent! " << endl;
                }
            }
        }

        printGymsRemaining(4); // Print the remaining opponents left
        Defender = opponent[4]; // The new defender will be the next opponent in the array.
        while (Defender->health > 0) { // Same steps as above in the first battle sequence
            Choice = Attacker->printandFindFightMenuChoice(Attacker, Defender);
            if (Choice == 1) {
                Attacker->PlayerAttack(Defender);
                Attacker->OpponentAttack(Defender);
                if (Defender->health <= 0) {
                    cout << "Congratulations, you beat the opponent! " << endl;
                } else if (teamMate[0]->health <= 0 && teamMate[1]->health <= 0 && teamMate[2]->health <= 0) {
                    cout << "Sorry you died, thanks for playing!" << endl;
                    return 0;
                }
            } else if (Choice == 2) {
                NewAttacker = Attacker->printandFindSwitchChoice(Attacker, teamMate);
                if (NewAttacker == teamMate[0] || NewAttacker == teamMate[1] || NewAttacker == teamMate[2]){
                Attacker = NewAttacker;
                Attacker->OpponentAttack(Defender);
                }
                if (teamMate[0]->health <= 0 && teamMate[1]->health <= 0 && teamMate[2]->health <= 0) {
                    cout << "Sorry you died, thanks for playing!" << endl;
                    return 0;
                }
            } else if (Choice == 3) {
              printandUseItems(teamMateItems, Attacker, Defender);
               if (Defender->health <= 0) {
                    cout << "Congratulations, you beat the opponent! " << endl;
                }
            }
        }

        cout << "Congratulations you have beaten all 5 gyms! Thanks for playing!" << endl; // Only prints once they pass through every loop beating every opponent.

    } else if (MainMenuChoice == "2") { // If they choose to quit game
        return 0; // End the program.
    }





    return 0;
}
