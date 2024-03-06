#include <bits/stdc++.h>
using namespace std;
// d is the number of characters in the input alphabet
#define d 256
// } Driver Code Ends
// Hashing: Compute hash values for both the pattern and the initial substring of the text.
// Matching: Slide the pattern over the text, comparing hash values at each step.
// Confirm Match: If hash values match, confirm the match by comparing the pattern with the current substring.
// Repeat and Output: Repeat the process until all matches are found, outputting their positions in the text.
class Solution
{
public:
    /* pat -> pattern
        txt -> text
        q -> A prime number
    */
    vector<int> ans;
    int q = 101; // A prime number
    vector<int> search(string pat, string txt)
    {
        // code here.
        int M = pat.size();
        int N = txt.size();
        int p = 0; // hash value for pattern
        int t = 0; // hash value for txt
        int h = 1;
        // The value of h would be "pow(d, M-1)%q"
        for (int i = 0; i < M - 1; i++)
        {
            h = (h * d) % q;
        }

        // Calculate the hash value of pattern and first  window of text

        for (int i = 0; i < M; i++)
        {
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }
        // slide the window over text one by one
        for (int i = 0; i < N - M; i++)
        {
            if (p == t)
            {
                for (int j = 0; j < M; j++)
                {
                    if (txt[i + j] != pat[j])
                        break;

                    // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
                    if (j == M)
                    {
                        ans.push_back(i + 1);
                    }
                }
            }
            // Calculate hash value for next window of text: Remove leading digit, add trailing digit
            if (i < M - N)
            {
               t = (d * (t - txt[i]*h) + txt[i+M]) % q;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends