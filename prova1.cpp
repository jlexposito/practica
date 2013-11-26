string Estructura::clasificar_criterio1(Arbre<string>& a, vector<bool>& b, const int tamany, const list<string>& pc, int& count, int& nivell){
	string s;
	if(not a.es_buit()){
		string x = a.arrel();
		list<string>::const_iterator it = pc.begin();
		Arbre<string> ae, ad;
		a.fills(ae, ad);
		if(ae.es_buit() and ad.es_buit()){
			nivell = 0;
			int i = 0;
			while(it != pc.end()){
				if(x == (*it)){
					b[i] = true;
					++count;
				}
				else if (b[i] == true) ++count;
				++i;
				++it;
			}
			if(count >= tamany) s = x;
			//cout << "<<<<< CONTADORS " << x << " SENSE FILLS " << count<< endl;
		}
		else{
			string se, sd;
			vector<bool> be(tamany, false);
			vector<bool> bd(tamany, false);
			int countE = 0;
			int countD = 0;
			int nivellE = 0;
			int nivellD = 0;

			clasificar_criterio1(ae, be, tamany, pc, countE, nivellE);
			clasificar_criterio1(ad, bd, tamany, pc, countD, nivellD);
			
			if(countE >= tamany and countD < tamany) s =  ae.arrel();
			else if (countD >= tamany){
				if(nivellE <= nivellD) s = ae.arrel();
				else s = ad.arrel();
			}
			else{
				count = countE + countD;
				nivell = max(nivellE, nivellD) +1;
				for(int i = 0; i < tamany; ++i) b[i]  = be[i] or bd[i];
				if(count >= tamany) s = x;
				//cout << s << " " << nivellE <<" "<< nivellD << "  "<<endl;
			}					
			a.plantar(x, ae, ad);

			cout << x <<  endl;
			cout << countE << " " << nivellE << endl;
			cout << countD <<" "<< nivellD << endl;
			cout << count << " Resultat: " << s << endl;
			cout << "------------------"<<endl;

		}
	}
	return s;
}
