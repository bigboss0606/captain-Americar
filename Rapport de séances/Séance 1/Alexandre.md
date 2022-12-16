I. Recherche / théorie 

J'ai cherché ce que pouvais renvoyer un accéléromètre comme information et donc quel mouvement peut être effectué pour faire bouger la voiture.


L'accéléromètre mesure l'accélération (taux de variation de la vitesse de l'objet). 
Il détecte les forces statiques comme la gravité (9,8 m/s2) ou des forces dynamiques comme les vibrations ou le mouvement. 
Le MPU-6050 mesure l'accélération sur les axes X, Y et Z.

Il est donc possible de mesurer un éventuel roulis ou tangage. 

![This is an image](https://upload.wikimedia.org/wikipedia/commons/1/1b/A%C3%A9ronef_%28Beech_bimoteur%29_et_ses_axes.png)

On utilisera donc le roulis pour faire tourner la voiture et le tangage pour la faire avancer ou reculer.
En combinant l'accéléromètre avec un gyroscope, on pourra déterminer l'accélération de la voiture qui dépendera donc de la vitesse de mouvement. 

II. Test d'un accéléromètre ( GY-521)

On obtient l'information (avec des prints) sous cette forme :

Acceleration X: 7.10, Y: 7.14, Z: -0.79 m/s^2
Rotation X: -0.04, Y: -0.01, Z: 0.02 rad/s
Temperature: 22.18 degC

Acceleration X: mesure le tangage 
Acceleration Y: mesure le roulis
Rotation X,Y,Z: mesure la vitesse angulaire

En théorie l'accélération mesure l'accélération sur les différents axes, mais en pratique on utilisera cette information pour déterminer le tangage ou le roulis.

Problème : en effectuant des tests on remarque qu'un accoup fausse les résultats.
Un petit accoup vers l'avant par l'exemple fait que le capteur renvoie une accélération de -17.
Nous verrons plus tard si cela est vraiment dérangeant pour le controle de la voiture ou non.

Pour l'instant, à l'aide de if, le capteur renvoie avant, derrière, gauche ou droite selon l'inclinaison du capteur.
(Il peut aussi renvoyer une combinaison des 2 : avant/gauche, derrière/droite ect.....)
