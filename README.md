Implémentation du patron Singleton


<img width="222" height="90" alt="image" src="https://github.com/user-attachments/assets/264b0c02-51f6-4c58-8377-fae7b1c8b9ca" />

1. Pourquoi le constructeur doit-il être privé ?

Pour empêcher la création d'objets directement avec new ou une déclaration classique. Ainsi, une seule instance est accessible avec getInstance().

2. Quelles sont les limites en multithread ?
- Une mauvaise implémentation peut créer plusieurs instances simultanément.
- Il faut protéger l'accès partagé aux données.

 
 Utilisation du patron Fabrique (Factory Method)


 <img width="228" height="94" alt="image" src="https://github.com/user-attachments/assets/aeb9ccb3-2033-434c-ad5a-e9355c93744a" />

1. Quelle est l'utilité du Factory ?
- Centraliser la création des objets.
- Séparer la création de l'utilisation.
2. Comment rendre le système plus modulaire avec FabriqueAbstraite ?
Créer une classe abstraite FabriqueAbstraite contenant une méthode virtuelle creerForme(). Chaque fabrique concrète implémente cette méthode. 
Application du patron Observateur (Observer)  



<img width="238" height="117" alt="image" src="https://github.com/user-attachments/assets/1ae5aacc-938d-4506-af5b-85ccca863203" />


Mise en œuvre du patron Stratégie (Strategy)

<img width="216" height="81" alt="image" src="https://github.com/user-attachments/assets/c043cf1e-b380-4105-929e-9e06f1bce177" />


1. Comment éviter une forte dépendance ?

Utiliser une interface abstraite Observateur. La station dépend uniquement de cette interface et non des classes concrètes.
