class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int n = s.length();
        vector<int> pre_a(n + 1, 0), pre_b(n + 1, 0), pre_c(n + 1, 0);
        int total_a = 0, total_b = 0, total_c = 0;

        for (int i = 0; i < n; ++i)
        {
            pre_a[i + 1] = pre_a[i];
            pre_b[i + 1] = pre_b[i];
            pre_c[i + 1] = pre_c[i];
            if (s[i] == 'a')
            {
                pre_a[i + 1]++;
                total_a++;
            }
            else if (s[i] == 'b')
            {
                pre_b[i + 1]++;
                total_b++;
            }
            else if (s[i] == 'c')
            {
                pre_c[i + 1]++;
                total_c++;
            }
        }

        if (total_a < k || total_b < k || total_c < k)
            return -1;

        int max_middle_length = 0;
        int l = 0;

        for (int r = 0; r < n; ++r)
        {
            while (l <= r)
            {
                int counts_in_middle_a = pre_a[r + 1] - pre_a[l];
                int counts_in_middle_b = pre_b[r + 1] - pre_b[l];
                int counts_in_middle_c = pre_c[r + 1] - pre_c[l];

                int counts_in_ends_a = total_a - counts_in_middle_a;
                int counts_in_ends_b = total_b - counts_in_middle_b;
                int counts_in_ends_c = total_c - counts_in_middle_c;

                if (counts_in_ends_a >= k && counts_in_ends_b >= k && counts_in_ends_c >= k)
                {
                    max_middle_length = max(max_middle_length, r - l + 1);
                    break;
                }
                else
                {
                    l++;
                }
            }
        }

        return n - max_middle_length;
    }
};
