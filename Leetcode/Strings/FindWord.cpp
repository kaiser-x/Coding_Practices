#include<unordered_set>
#include<sstream>
bool findWord(string &s, string &w)
{
	//	Write your code here.
   //<< adds string to stream , >> gets a token or individual string from stream
    stringstream str(s);
    string token;
    unordered_set<string> st;
    //we do not set any delimiter here, >> gets token from stream, and 
    //as long as it keeps geting it the loop continues untill it encounters
    //null
//     while(str>>token) st.insert(token);
    
    //By seting a delimiter ,space is delimiter here
    while(getline(str,token,' ')){
        st.insert(token);
    }
    return (st.find(w)!=st.end())? true: false;
}