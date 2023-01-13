# I. Bluetooth / liaison des appareils

Nous avons finalement réussi à faire fonctionner le bluetooth pour mettre en liason l'accéléroscope et la voiture.

L'erreur était toute simple : en refaisant le circui j'ai branché le RX de la carte sur le RX du capteur bluetooth (de même avec le TX).  
Alors qu'il faut brancher le RX avec le TX... 
J'ai ensuite modifié le code sur l'accéléromètre pour envoyer des lettres (via bluetooth) indiquant la direction (ZQSD).



# II. Correction de bug / amélioration à faire
