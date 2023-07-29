class result 
{
    public static string betterCompression(string s) 
    {
        // Write your code here
        string result = "";
        Dictionary<char, int> dict = new Dictionary<char, int>();
        for(int i = 0; i < s.Length; i++)
        {
            if(Char.IsLetter(s[i]))
            {
                if(dict.ContainsKey(s[i]))
                {
                    dict[s[i]]++;
                }
                else
                {
                    dict.Add(s[i], 1);
                }
            }
            else
            {
                int num = 0;
                while(Char.IsDigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                foreach(KeyValuePair<char, int> kvp in dict)
                {
                    result += kvp.Key.ToString() + kvp.Value.ToString();
                }
                dict.Clear();
            }
        }
        foreach(KeyValuePair<char, int> kvp in dict)
        {
            result += kvp.Key.ToString() + kvp.Value.ToString();
        }
        return result;
    }
}