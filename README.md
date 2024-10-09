# Arduino-HuskyLens-Servos
![Circuit-connections-diagram-for-the-Huskylens-facial-recognition-camera](https://github.com/user-attachments/assets/224f2c17-c1cd-4148-a48e-4c6ed9dbcf5c)

# Coder avec Huskylense
## Les options 
#### ALGORITHM_FACE_RECOGNITION :reconnaissance facial
#### ALGORITHM_OBJECT_TRACKING  :Traqueur d'objet
#### ALGORITHM_OBJECT_RECOGNITION :reconnaissance d'objet
#### ALGORITHM_LINE_TRACKING : Suiveur de ligne
#### ALGORITHM_COLOR_RECOGNITION: reconnaissance des couleurs
#### ALGORITHM_TAG_RECOGNITION : reconnaissance de symboles
#### ALGORITHM_OBJECT_CLASSIFICATION : Classification d'objets


## Description: Structure to store the blocks or arrows

### Command Use to determine whether this is arrow or block
#### COMMAND_RETURN_BLOCK It is a block
#### COMMAND_RETURN_ARROW It is an arrow

### Pour un bloc:
| Code | definition |
| :----: | :---- |
|.xCenter | Centre en X du bloc | 
|.yCenter | Centre en Y du bloc |
|.width | largeur du bloc | 
|.height | Hauteur du bloc | 
|.ID | ID du bloc | 			

### Pour une fleche:
| Code | definition |
| :----: | :---- |
|.xOrigin | Origine de la fleche en X | 
|.yOrigin | Origine de la fleche en Y |
|.xTarget | Cible de la fleche en X | 
|.yTarget | Cible de la fleche en Y | 
|.ID | ID de la fleche | 			
