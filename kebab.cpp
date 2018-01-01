#include "kebab.h"

// Constructor for Kebab.
Kebab::Kebab(){
	std::vector<char> skewer;
}

// Adds an ingredient to a kebab.
// - parameters: item - the item to be added to the kebab.
// returns true if there was space on the kebab, false otherwise.
bool Kebab::addIngredient(char item){
	if(isValidIngredient(item)){
		if(skewer.size()<maxlength){
			skewer.push_back(item);
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

// Builds a kebab from a provided string.
// - parameters: string s - the string representing the kebab
//							to be created.
void Kebab::buildKebab(std::string s){
	for(int i = 0; i < s.length(); i++) {
    addIngredient(s[i]);
	}
}

// Returns the number of meat items on a kebab.
unsigned int Kebab::numMeats() const{
	int quickNum = 0;
	for(int i=0; i < skewer.size(); i++){
		if(skewer[i] == 'b' || skewer[i] == 'B'){
			quickNum = quickNum + 1;
		}
	}
	return quickNum;
}

// Returns true whether a kebab has the same ingredients as another.
// - parameters: k - the provided kebab to be compared.
bool Kebab::hasSameIngredients(Kebab& k) const{
	int beef1 = 0;
	int tomato1 = 0;
	int mushroom1 = 0;
	int pepper1 = 0;
	int squash1 = 0;

	int beef2 = 0;
	int tomato2 = 0;
	int mushroom2 = 0;
	int pepper2 = 0;
	int squash2 = 0;


	for(int i=0; i < k.listIngredients().length(); i++){
		if(k.listIngredients()[i] == 'b' || k.listIngredients()[i] == 'B'){
			beef1++;
		}
		if(k.listIngredients()[i] == 't' || k.listIngredients()[i] == 'T'){
			tomato1++;
		}
		if(k.listIngredients()[i] == 'm' || k.listIngredients()[i] == 'M'){
			mushroom1++;
		}
		if(k.listIngredients()[i] == 'p' || k.listIngredients()[i] == 'P'){
			pepper1++;
		}
		if(k.listIngredients()[i] == 's' || k.listIngredients()[i] == 'S'){
			squash1++;
		}
	}

	for (int i = 0; i < skewer.size(); ++i)
	{
		if(skewer[i] == 'b' || skewer[i] == 'B'){
			beef2++;
		}
		if(skewer[i] == 't' || skewer[i] == 'T'){
			tomato2++;
		}
		if(skewer[i] == 'm' || skewer[i] == 'M'){
			mushroom2++;
		}
		if(skewer[i] == 'p' || skewer[i] == 'P'){
			pepper2++;
		}
		if(skewer[i] == 's' || skewer[i] == 'S'){
			squash2++;
		}
	}

	if (beef1 <= beef2 &&
		tomato2 >= tomato1 &&
		squash2 >= squash1 &&
		pepper1 <= pepper2 &&
		mushroom1 <= pepper2)
	{
		return true;
	}else{
		return false;
	}
}

// Lists the ingredients on a kebab.
std::string Kebab::listIngredients() const{
	std::string quickList = "";
	for (int i = 0; i < skewer.size(); ++i)
	{
		quickList.push_back(skewer[i]);
	}
	return quickList;
}