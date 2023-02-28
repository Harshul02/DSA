string removeVowels(string S) 
	{
	    // Your code goes here
	   // vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	    
	   // for(int i=0; i<S.size(); i++)
	   // {
	   //     if(find(vowels.begin(), vowels.end(), S[i]) != vowels.end())
	   //     {
	   //         S = S.replace(i,1,"");
	   //         i -= 1;
	   //     }
	   // }
	   // return S;
	   
	   regex r("[aeiouAEIOU]");
	   return regex_replace(S, r, "");
	}