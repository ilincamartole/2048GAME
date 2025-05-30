# 2048GAME
Proiectul simulează Jocul 2048, ce se bazează pe fuzionarea a două block-uri daca acestea au aceeași valoare (putere a lui doi). Scopul jocului este să se creeze un block ce sa aibă valoarea 2048. In realizarea jocului am implementat și alte trei moduri
-Joc Greu: block-urile se pot combina numai daca au aceeași valoarea ȘI aceeași culoare
-Joc Random: în loc de puterile lui 2, block-urile iau inițial valori de la 1 la 9.
-Joc Extrem

La inceput, user-ul se logheaza cu o parola. Username-ul si parola sunt citite dintr-un fisier text. Apoi, exista un meniu din care user ul poate alege modul de joc pe care vrea sa il joace.

Instrucțiuni: se folosesc săgețile sus, jos, stânga, dreapta pentru a muta block-urile. Când se apasă o tastă, toate block-urile ce se pot muta în direcția respectivă vor face asta.
Comanda de rulare a jocului este :
g++ -std=c++17 -IC:/SFML-2.5.1/include -LC:/SFML-2.5.1/lib src/main.cpp src/Block.cpp src/Board.cpp src/Joc2048.cpp src/Scor.cpp src/BlockSpecial.cpp src/JocGreu.cpp src/JocRandom.cpp -lsfml-graphics -lsfml-window -lsfml-system -o main.exe
>>
Urmata de : ./main.exe
Apoi, se urmează instrucțiunile din terminal.

Cerințe:

- separarea codului în fișiere header și surse ✅
- fără using namespace std; ✅
- moșteniri: - Joc2048->JocGreu✅

		      ->JocRandom✅

	     - Block->BlockSpecial✅
- funcții virtuale (pure):

	- minim o funcție virtuală specifică temei ✅ (funcțiile mutari, 	descriere și clone sunt virtuale și suprascrise în clasele 	derivate)
	- apelarea funcțiilor virtuale prin pointeri la clasa de bază ✅
	(funcțiile virtuale sunt apelate prin pointeri la clasa de bază 	(ex. joc->mutari(...) în main.cpp)
- constructori virtuali (clone) ✅
- apelarea constructorului din clasa de bază din constructorii derivatelor ✅ (JocGreu și JocRandom) apeleaza constructorul din Joc2048)
- dynamic cast pentru downcast cu sens ✅ (dynamic_cast este utilizat în main.cpp pentru a verifica tipul unui obiect)
- std::unique_ptr ✅ utilizat in main.cpp
- excepții pentru gestionarea erorilor ✅ 
- STL ✅ (vectori de scoruri in clasa Scor)
- const ✅

- Cerinte (tema 3):

  - transformarea unei clase intr-o clasa template: Am transformat clasa Block in clasa template pentru a putea rula pe orice tip de valori. ✅
  - realizarea autentificarii user-ului cu o clasa Singleton: aceasta citeste din fisier si valideaza numele de utilizator si parola. ✅
  - design patters: Am facut JobFactory.h ca sa ea launch diferitelor moduri de joc.✅
  - functiile membre si atributele din clasa Block sunt acum template. ✅

Bibliografie:
- https://www.sfml-dev.org/
- https://github.com/biancapopa31/oop/tree/main/headers
- https://www.linkedin.com/advice/1/how-can-you-use-oop-create-video-games-skills-programming-ntv1e
