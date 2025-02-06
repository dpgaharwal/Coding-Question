class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0)
            return result;

        int start = k > 0 ? 1 : n + k;
        int end = k > 0 ? k : n - 1;

        int sum = 0;
        for (int i = start; i <= end; ++i)
        {
            sum += code[i % n];
        }

        for (int i = 0; i < n; ++i)
        {
            result[i] = sum;
            sum -= code[start % n];
            start = (start + 1) % n;
            end = (end + 1) % n;
            sum += code[end % n];
        }

        return result;
    }
};
