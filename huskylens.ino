https://github.com/HuskyLens/HUSKYLENSArduino


#include <Servo.h>
#include <DFRobot_HuskyLens.h>

// Dynamic variables
volatile float mind_n_currentx, mind_n_currenty;
// Create an object
DFRobot_HuskyLens huskylens;
Servo             servo_9;
Servo             servo_10;


// Au demarrage
void setup() {
	servo_9.attach(9);
	servo_10.attach(10);
	huskylens.writeOSD(String("attendre..."), 230, 35);
	huskylens.beginI2CUntilSuccess();
	huskylens.writeAlgorithm(ALGORITHM_OBJECT_TRACKING);
	delay(1000);
	huskylens.writeOSD(String("zou!!!"), 230, 35);
	angle_servo9 = 40;
	angle_servo10 = 150;
	servo_9.angle(abs(angle_servo9));
	servo_10.angle(abs(angle_servo10));
}

// Je lance la boucle de lecture
void loop() {
	huskylens.request();
	huskylens.writeOSD(String(huskylens.readBlockParameter(1).xCenter), 230, 35);
	if ((huskylens.readBlockParameter(1).xCenter>190)) {
		angle_servo9 -= 1.5;
		servo_9.write(angle_servo9);
	}
	else if (((huskylens.readBlockParameter(1).xCenter>10) && (huskylens.readBlockParameter(1).xCenter<130))) {
		angle_servo9 += 1.5;
		servo_9.write(angle_servo9);
	}
	if ((huskylens.readBlockParameter(1).yCenter>150)) {
		angle_servo10 += 1.0;
		servo_10.write(angle_servo10);
	}
	else if (((huskylens.readBlockParameter(1).yCenter>10) && (huskylens.readBlockParameter(1).yCenter<90))) {
		angle_servo10 -= 1;
		servo_10.write(angle_servo10);
	}
}

//Mode d'emploi de Huskylense//
/* Les options 
ALGORITHM_FACE_RECOGNITION :reconnaissance facial
ALGORITHM_OBJECT_TRACKING  :Traqueur d'objet
ALGORITHM_OBJECT_RECOGNITION :reconnaissance d'objet
ALGORITHM_LINE_TRACKING : Suiveur de ligne
ALGORITHM_COLOR_RECOGNITION: reconnaissance des couleurs
ALGORITHM_TAG_RECOGNITION : reconnaissance de symboles
ALGORITHM_OBJECT_CLASSIFICATION : Classification d'objets
*/

/*Description: Structure to store the blocks or arrows

*Command Use to determine whether this is arrow or block
COMMAND_RETURN_BLOCK It is a block
COMMAND_RETURN_ARROW It is an arrow

*Pour un bloc:
xCenter 	Centre en X du bloc
yCenter 	Centre en Y du bloc
width 		largeur du bloc
height 		Hauteur du bloc
ID 			ID du bloc

*Pour une fleche:
xOrigin  	Origine de la fleche en X
yOrigin 	Origine de la fleche en Y
xTarget 	Cible de la fleche en X
yTarget 	Cible de la fleche en Y
ID 			ID de la fleche
*/