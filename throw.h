#ifndef THROW_H
#define THROW_H

#include "coin.h"
#include "command.h"
#include "mushroom.h"
#include "rock.h"
#include <iostream>

using namespace std;

class Throw : public Command {
public:
    Throw() : Command("throw") {};

    void fire(Cave& c, string userCommand) {

        string s = tail(userCommand);

        Location* loc = c.getMap()[c.getTom()->getX()][(c.getTom()->getY())];

        if (s[0] == 'w')
            loc = c.getMap()[((c.getTom()->getX())+1)][c.getTom()->getY()];
        else if  (s[0] == 'n')
            loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()-1];
        else if (s[0]=='e')
            loc = c.getMap()[c.getTom()->getX()+1][c.getTom()->getY()];
        else if (s[0]=='s')
            loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()+1];

        if ((c.getTom()->getX())-1!=0&&c.getTom()->getY()-1!=0&&c.getTom()->getX()+1!=c.getWidth()&&c.getTom()->getY()+1!=c.getHeight())
            loc -> add(new Coin());




/*
        if (s.compare("coin")==0)
            loc -> add(new Coin());
        else if (s.compare("mushroom")==0)
            loc -> add(new Mushroom());
        else
            cerr << "I don't know how to place a " << userCommand << endl;
*/
    }
};

#endif // THROW_H
