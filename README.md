# Sieć troficzna w C++

Projekt przedstawia prosty model **sieci troficznej** zbudowany z użyciem **grafu skierowanego**.  
Każdy organizm jest reprezentowany jako wierzchołek, a każda relacja pokarmowa jako skierowana krawędź:

**ofiara → drapieżnik**

Program umożliwia:
- tworzenie relacji troficznych między gatunkami,
- obliczanie stopni wejściowych i wyjściowych wierzchołków,
- identyfikację gatunku o największym stopniu w grafie,
- eksport sieci do pliku **Graphviz DOT** w celu dalszej wizualizacji.

Projekt pokazuje, jak narzędzia teorii grafów mogą być stosowane w modelowaniu prostych układów biologicznych.

---

## Opis biologiczny

W ekologii sieć troficzna opisuje zależności pokarmowe pomiędzy organizmami w ekosystemie.  
W tym projekcie relacja:
Organizm_A → Organizm_B 
Oznacza, że Organizm_B zjada Organizm_A, np: 
Trawa morska → Manat 
Oznacza, że manat odżywia się trawą morską.

Zastosowany model

Program wykorzystuje: 
- graf skierowany
- listę sąsiedztwa
- analizę:
--> stopnia wejściowego (in-degree)
--> stopnia wyjściowego (out-degree)
--> stopnia całkowitego (degree)

Interpretacja stopni:
stopień wejściowy – ile ofiar ma dany organizm
stopień wyjściowy – ilu drapieżników zjada dany organizm
stopień całkowity – suma połączeń danego gatunku w sieci

Na tej podstawie program wskazuje również kluczowy gatunek według najwyższego stopnia w grafie.
