Il peut être necessaire d'installer qt : 

    sudo apt-get install qt5-default


Effectuer la commande qmake suivante pour générer le makefile si besoin :

    qmake ScheduleCreator.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug


Ensuite effectuer :

    make

Et lancer le programme avec :

    ./ScheduleCreator

Pour tester la fonction de génération d'EDT, veuillez selectionner la filiere INFOS6;

Pour tester la fonction de sortie Latex, veuillez lancer la fonction de génération sur la filiere INFOS6 au préalable;



