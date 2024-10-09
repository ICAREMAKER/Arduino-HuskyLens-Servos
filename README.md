# Arduino-HuskyLens-Servos
#### https://arduiblog.com/2021/05/24/huskylens/
#### https://github.com/HuskyLens/HUSKYLENSArduino
![Circuit-connections-diagram-for-the-Huskylens-facial-recognition-camera](https://github.com/user-attachments/assets/224f2c17-c1cd-4148-a48e-4c6ed9dbcf5c)

# Coder avec Huskylense
## Les options 
| Code | Definition |
| :----: | :---- |
|ALGORITHM_FACE_RECOGNITION | Reconnaissance facial | 
|ALGORITHM_OBJECT_TRACKING | Traqueur d'objet |  
|ALGORITHM_OBJECT_RECOGNITION | Reconnaissance d'objet | 
|ALGORITHM_LINE_TRACKING | Suiveur de ligne |  
|ALGORITHM_COLOR_RECOGNITION | Reconnaissance des couleurs | 
|ALGORITHM_TAG_RECOGNITION | Reconnaissance de symboles |
|ALGORITHM_OBJECT_CLASSIFICATION | Classification d'objets |  
 
exemple de syntaxe
```C
huskylens.writeAlgorithm(ALGORITHM_OBJECT_TRACKING);
```
## Description: Structure to store the blocks or arrows

### Command Use to determine whether this is arrow or block
| Code | Definition |
| :----: | :---- |
|COMMAND_RETURN_BLOCK | C'est un bloc | 
|COMMAND_RETURN_ARROW | C'est une fleche |  

### Pour un bloc:
| Code | Definition |
| :----: | :---- |
|.xCenter | Centre en X du bloc | 
|.yCenter | Centre en Y du bloc |
|.width | Largeur du bloc | 
|.height | Hauteur du bloc | 
|.ID | ID du bloc | 			

### Pour une fleche:
| Code | Definition |
| :----: | :---- |
|.xOrigin | Origine de la fleche en X | 
|.yOrigin | Origine de la fleche en Y |
|.xTarget | Cible de la fleche en X | 
|.yTarget | Cible de la fleche en Y | 
|.ID | ID de la fleche | 			
