#include<iostream>
#include<algorithm>
#include<list>
#include<iomanip> 
#include<vector>
#include<string>
#include "Dot_Exporter.h"
#include<map> 
using namespace std; 
class Graf_biologiczny {
protected:
	int V; 
	vector<string> nazwy_gatunkow; 
	vector<vector<int>> adj_list;
	vector<int> stopien_wejsciowy; 
	vector<int> stopien_wyjsciowy; 
public: 
	Graf_biologiczny(int wierzcholki, vector<string>& nazwy_organizmow) : V(wierzcholki), nazwy_gatunkow(nazwy_organizmow) {
		adj_list.resize(V); 
		stopien_wejsciowy.assign(V, 0); 
		stopien_wyjsciowy.assign(V, 0); 
	}
	//Dodaje relacje miedzygatunkowa ofiara-->drapieznik 
	void dodaj_relacje(int ofiara, int drapieznik) {
		if (ofiara < V && drapieznik < V) {
			adj_list[ofiara].push_back(drapieznik); 
			stopien_wyjsciowy[ofiara]++; 
			stopien_wejsciowy[drapieznik]++; 
		}
	}
	void display_info() {
		cout << "\n\t==Siec troficzna==\t\n"; 
		cout << setw(3) << "V" << " " << setw(20) << left << "Organizm" << " In (Ofiary) | Out (Drapiezniki) | Stopien\n"; 
		cout << string(70, '*') << endl; 

		int max_degree = 0; 
		int key_species_ID = 0; 
		for (int i = 0; i < V; i++) {
			int obecny_stopien = stopien_wejsciowy[i] + stopien_wyjsciowy[i]; 
			cout << setw(3) << i << " | " << setw(18) << left << nazwy_gatunkow[i] << " | " << setw(10) << stopien_wejsciowy[i]
				<< " | " << setw(15) << stopien_wyjsciowy[i] << " | " << obecny_stopien << endl; 

			//Sprawdzenie maksymalnego stopnia w grafie: 
			if (obecny_stopien > max_degree) {
				max_degree = obecny_stopien; 
				key_species_ID = i; 
			}
		}
		cout << "Kluczowy gatunek w sieci troficznej to: " << nazwy_gatunkow[key_species_ID] << endl; 
		cout << "Jego stopien w grafie wynosi: " << max_degree << endl; 
	}
	void zapisz_wizualizacje(string filename) {
		GraphVisualizer::exportToDot(filename, "BioNetwork", nazwy_gatunkow, adj_list, true);
	}
};
int main(void) {
	vector<string> organizmy = {
		"Trawa morska", "Manat", "Lagodon", "Zuchwiak", "Delfin", "Jezowiec", 
		"Wargacz", "Plaszczka", "Rekin mlot"
	}; 
	Graf_biologiczny Zatoka_Amerykanska(9, organizmy); 
	Zatoka_Amerykanska.dodaj_relacje(0, 1); 
	Zatoka_Amerykanska.dodaj_relacje(0, 2); 
	Zatoka_Amerykanska.dodaj_relacje(0, 5); 
	Zatoka_Amerykanska.dodaj_relacje(5, 6); 
	Zatoka_Amerykanska.dodaj_relacje(2, 3); 
	Zatoka_Amerykanska.dodaj_relacje(2, 4); 
	Zatoka_Amerykanska.dodaj_relacje(3, 4); 
	Zatoka_Amerykanska.dodaj_relacje(6, 7); 
	Zatoka_Amerykanska.dodaj_relacje(7, 8); 
	Zatoka_Amerykanska.dodaj_relacje(1, 8); 

	Zatoka_Amerykanska.display_info(); 

	Zatoka_Amerykanska.zapisz_wizualizacje("Zatoka_US_siec_troficzna.dot"); 
	return 0; 
}