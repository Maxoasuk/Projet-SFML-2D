// Projet_Alex_Micoulet.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "SceneManager.h"
#include "Level.h"
#include "Starting.h"
#include "GameOver.h"
#include "Ending.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::View view = window.getDefaultView();
    view.setCenter(0.f, 0.f);
    view.zoom(0.2f);
    window.setView(view);

    SceneManager* sceneManager = SceneManager::getInstance();

    Starting starting;
    starting.init();

    GameOver gameover;
    gameover.init();

    Ending ending;
    ending.init();

    sceneManager->addScene("starting", &starting);
    sceneManager->addScene("gameover", &gameover);
    sceneManager->addScene("ending", &ending);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Scene* currentScene = sceneManager->getCurrentScene();
        currentScene->update(clock.restart().asSeconds());

        window.clear();
        window.draw(*currentScene);
        window.display();
    }
    return 0;

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
