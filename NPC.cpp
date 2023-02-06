#include "NPC.h"
#include "Player.h"

/* Virtual function that you need to complete   */
/* In NPC, this function should deal with the   */
/* transaction in easy implementation           */
void NPC::triggerEvent(Object* player){
    Player* p = dynamic_cast<Player*>(player);
    
    if(kind == 0){
        string r;
        if(p->race == 0){
            r = "a human";
        }
        else if(p->race == 1){
            r = "a goblin";
        }
        else if(p->race == 2){
            r = "an elf";
        }
        cout << endl  << "*A weird old man with huge beard appears*" << endl;
        sleep(1);
        cout << "I'm Gandolf! Welcome to HELL, you ask why i'm here?" << endl << "Appearently this is my new job..." <<endl ;
        sleep(1);
        cout << "Enough about me!!!  So, you are " << r << endl;
        cout << "Huh, so i would suggest the  door on the ";
        if(p->race == 0){
            cout << "on the [LEFT] for you HUMAN" << endl;
        }
        if(p->race == 1){
            cout << "on the [LEFT] for you GOBLIN" << endl;
        }
        else if(p->race == 2){
            cout << "on the [RIGHT] for you ELF" << endl;
        }
        sleep(1);
        cout << endl << "I'll strongly suggest you to go through the one i suggested." << endl;
        cout << "*Then Gandolf disappears*" << endl;
        
        p->getCurrentRoom()->popObject(p->getCurrentRoom()->getObjects());
        
    }
    
    else if(kind == 1){
        cout << endl << "*A beautiful god like woman apears*" << endl;
        sleep(1);
        cout << "I'm the elf queen. Hello sweety,... would you like to talk to me for awhile?" << endl;
        sleep(1);
        cout  <<" 1) Yeah, sure" << endl << " 2) No, sorry i'm busy" << endl;
        int c1;
        cin >> c1;
        cout << endl;
        if(c1 == 1){
            cout << "You're so nice, darling. What kind of wind blow you here? " << endl;
            sleep(1);
            cout <<  " 1) I honestly don't know, my honor. What bring you here? " << endl << " 2) I guess I did something wrong...? I think I really have to go" << endl;
            int c2;
            cin >> c2;
            cout << endl;
            if(c2 == 1){
                cout << "That's really nice of you, I was cursed by my evil ex girlfriend" << endl;
                cout << "~That's so cool, I mean CRUEL of her.~" << endl;
                cout << "But......anyway, can you apologize to Sabrina for me if you ever met her? PLEASE" << endl;
                sleep(1);
                cout << " 1) Yes, I will" << endl << " 2) Maybe next time?" << endl;
                int c3;
                cin >> c3;
                cout << endl;
                if(c3 == 1){
                    cout << "Actually, I know a faster way for you to get of of here... ACTUALLY I JUST WANT YOU TO GET TO MY EX ASAP!!" << endl << "Here you go" << endl << endl;
                    cout << "~Wait what?????~" << endl;
                    p->end = 1;
                    p->getCurrentRoom()->popObject(p->getCurrentRoom()->getObjects());
                    sleep(1);
                }
                else{
                    sleep(1);
                    cout << "Fine, it's nice knowing you, good luck on your journey" << endl << "*Then the elf queen disappears.*" << endl;
                    p->getCurrentRoom()->popObject(p->getCurrentRoom()->getObjects());
                }
            }
            else{
                sleep(1);
                cout << "So long, young warrior" << endl << "*Then the elf queen disappears.*" << endl;
                p->getCurrentRoom()->popObject(p->getCurrentRoom()->getObjects());
            }
        }
        else{
            sleep(1);
            cout << "Such a cruel heart and soul, with the worst upon you!!" << endl << "*Then the elf queen disappears.*" << endl;
            p->getCurrentRoom()->popObject(p->getCurrentRoom()->getObjects());
        }
    }
    
    else if(kind == 2){
        cout << endl << "*A very average guy shows up*" << endl;
        sleep(1);
        cout << "I'm just an ordinary merchant, totally innocent in this hell like dungeon" << endl << "Wait what, you don't believe me? WELL THEN, TRADE!" << endl;
        sleep(1);
        cout << "I have" << endl << " 1) " << commodity[0].getName() << endl << " 2) " << commodity[1].getName() << endl << " 3) no thanks" << endl;
        cout << "You can take one from me!!" << endl;
        sleep(1);
        cout << "But in exchange, I'll take 20 points from your health" << endl << "So....." << endl;
        
        int c1;
        cin >> c1;
        if(c1 == 1){
            this->getCommodity()[0].triggerEvent(p);
            cout << endl << "*" << commodity[0].getName() << " is now in your inventory!*" <<  endl;
            p->setCurrentHealth(p->getCurrentHealth() - 20);
        }
        else if(c1 == 2){
            this->getCommodity()[1].triggerEvent(p);
            cout << endl <<  "*" << commodity[1].getName() << " is now in your inventory!*" <<  endl;
            p->setCurrentHealth(p->getCurrentHealth() - 20);
        }
        else{
            cout << "Okay fine, i gotta get going then" << endl;
        }
        sleep(1);
        cout << "*Then the merchant disappears*" << endl ;
        p->getCurrentRoom()->popObject(p->getCurrentRoom()->getObjects());
    }
    
}

/* Set & Get function*/
void NPC::setScript(string sp){
    script = sp;
}
void NPC::setCommodity(vector<Item> it){
    
}
//string NPC::getScript(){};
vector<Item> NPC::getCommodity(){
    return commodity;
};
