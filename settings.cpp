#include "settings.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <unistd.h>
using namespace std;



void Settings::selectMode() {
    unsigned int p;
    set=false;
    cout<<"Please Select your desired mode: "<<
    '\n'<<"1- Short Pomodoro"<<
    '\n'<<"2- Medium Pomodoro"<<
    '\n'<<"3- Long Pomodoro"<<
    '\n'<<"4- More Detail"<<endl;
    cin>>p;
    while (p>=4){
        if(p==4){
            cout<<"Mode's Details: "<<
    '\n'<<"1- Short Pomodoro: Good for short tasks --> 1hour (2X 25m work + 5min break) "<<
    '\n'<<"2- Medium Pomodoro: To complete mini projects --> 2hours (2X 45m work + 15min break)"<<
    '\n'<<"3- Long Pomodoro: If you have motivation --> 4hours (4X 50m work + 10min break)"<<endl;
            sleep(10);
        }

    cout<<"Please Select a valid mode: "<<
    '\n'<<"1- Short Pomodoro"<<
    '\n'<<"2- Medium Pomodoro"<<
    '\n'<<"3- Long Pomodoro"<<endl;
    cin>>p;
    }
    switch (p)
    {
    case 1:
        set=true;
        wIndex=2;
        bIndex=2;
        pomodoroShort(25, 5);
        break;
    case 2: 
        set=true;
         wIndex=2;
        bIndex=2;
        
        pomodoroMedium(45, 15);
        break;
    case 3:
        set=true;
        wIndex=4;
        bIndex=4;
        
        pomodoroLong(50, 10);
        break;
    
    default:
        set=false;
        cout<<"404 mode not found: GO AGAIN!!"<<endl;
        break;
    }

    
}




void Settings::timeLoop(unsigned int workDuration,unsigned int breakDuration){
    selectMode();
    cout<<"running";
    int w=workDuration;
    int b=breakDuration;
    while (set==true){
        unsigned int totalTime=0;
        for (int k= 0; k < wIndex; k++)
        {
 cout<< "loop number "<< k<<endl;
        
        
        for (int i=0;i<workDuration;i++){
            sleep(60);
            cout <<" Work time remaining: " <<w-1<<endl;
            totalTime++;
        }
        for (int j = 0; j < breakDuration; j++)
        {
            sleep(60);
            cout <<"Time remaining: " <<b-1<<endl;
            totalTime++;
        }
        

    }
        
        if (workDuration*wIndex+breakDuration*bIndex==totalTime)
        {set=false;
            endAnimation();
        }

    }
   


}




//FONCTIONNALITES A RAJOUTER AVEC RAYLIB POUR UTILISER LES INPUTS CLAVIER
//bool Settings::stop(string cmd) const{}

//bool Settings::reset(string cmd) const{}
//void Settings::stopLoop() const{}
//void Settings::resetLoop(){}


void Settings::pomodoroShort(unsigned int workDuration,unsigned int breakDuration) {
cout<<"ok";
timeLoop(workDuration,breakDuration);

}




void Settings::pomodoroMedium(unsigned int workDuration,unsigned int breakDuration) {

timeLoop(workDuration,breakDuration);


}

void Settings::pomodoroLong(unsigned int workDuration,unsigned int breakDuration) {
timeLoop(workDuration,breakDuration);


}

//Extras

void Settings::endAnimation()const{

    // Texte ASCII dense (Style: Block / Heavy)
    const std::vector<std::string> asciiArt = {
        " ██████╗ ██████╗ ███████╗ █████╗ ████████╗     ██╗ ██████╗ ██████╗ ██╗  ██╗",
        "██╔════╝ ██╔══██╗██╔════╝██╔══██╗╚══██╔══╝     ██║██╔═══██╗██╔══██╗██║  ██║",
        "██║  ███╗██████╔╝█████╗  ███████║   ██║        ██║██║   ██║██████╔╝██║  ██║",
        "██║   ██║██╔══██╗██╔══╝  ██╔══██║   ██║   ██   ██║██║   ██║██╔══██╗╚═╝  ╚═╝",
        "╚██████╔╝██║  ██║███████╗██║  ██║   ██║   ╚█████╔╝╚██████╔╝██████╔╝██╗  ██╗",
        " ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝    ╚════╝  ╚═════╝ ╚═════╝ ╚═╝  ╚═╝"
    };

    // Couleurs : Vert, Cyan, Blanc (pour un effet de pulsation)
    const std::vector<std::string> colors = {"\033[1;32m", "\033[1;36m", "\033[1;37m"};

    // Animation de 12 frames
    for (int frame = 0; frame < 12; ++frame) {
        // Efface l'écran et replace le curseur en haut à gauche
        std::cout << "\033[2J\033[H"; 

        // Sélection de la couleur
        std::cout << colors[frame % colors.size()] << std::endl;

        // Affichage du bloc
        for (const std::string& line : asciiArt) {
            std::cout << "    " << line << std::endl; 
        }

        std::cout << "\033[0m" << std::flush; // Reset couleur et force l'affichage

        // Pause de 150ms pour une animation fluide
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

