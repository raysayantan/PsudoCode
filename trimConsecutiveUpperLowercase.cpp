/*
 Given a string that contains alphabetic characters, remove pairs of xX or Xx where the two chars in the pair are the same letter in different case. So xX is removed, Xx is removed, but xx and XX are not. 

Sample input: abcCkPDdppGGa 
Sample output: abkPppGGa
*/
string trimUpperLowerCombination(string input){
string res = “”;
int len = input.length();
int offset = ‘A’ - ‘a’;

if(len == 0 ) return res; //null string
int i = 0;
while(i < len){
	if(input[i] >= ‘a’ && input[i] <= ‘z’){
		if(i+1 < len && input[i+1] == input[i] + offset){
			i = i + 2;
		} else {
			res += string(input[i]); i++;
		}
			
	} else if(input[i] >= ‘A’ && input[i] <= ‘Z’){
		if(i+1 < len && input[i+1] == input[i] + offset){
			i +=2;
} esle {
	res += string(inpu[i]);
	i++;
}		
	}
}

	return res;
}
